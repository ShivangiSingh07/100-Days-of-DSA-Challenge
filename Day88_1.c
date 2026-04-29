/*
Problem Statement:
Given n stalls located at different positions along a straight line and k cows,
place the cows in the stalls such that the minimum distance between any two cows
is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format:
n k
n space-separated integers representing stall positions

Output Format:
Print the maximum possible minimum distance between any two cows.

Sample Input:
5 3
1 2 8 4 9

Sample Output:
3

Explanation:
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows
is 3, which is the maximum possible.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to check if cows can be placed with at least 'dist' distance apart
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1; // place first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count == k) return 1; // all cows placed successfully
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1; // minimum possible distance
    int high = stalls[n-1] - stalls[0]; // maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;   // mid is possible, try for larger distance
            low = mid + 1;
        } else {
            high = mid - 1; // mid not possible, try smaller distance
        }
    }

    printf("%d\n", result);
    return 0;
}
