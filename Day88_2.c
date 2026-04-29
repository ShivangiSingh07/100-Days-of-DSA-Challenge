/*
Problem Statement:
In universe Earth C-137, Rick discovered a special form of magnetic force between two balls
if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at
position[i]. Morty has m balls and needs to distribute the balls into the baskets such that
the minimum magnetic force between any two balls is maximized.

Magnetic force between two different balls at positions x and y is |x - y|.

Input:
n == position.length
2 <= n <= 10^5
1 <= position[i] <= 10^9
All integers in position are distinct.
2 <= m <= position.length

Output:
Return the required maximum minimum magnetic force.

Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3

Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
*/

#include <stdio.h>
#include <stdlib.h>

// Function to check if we can place m balls with at least 'dist' apart
int canPlace(int *pos, int n, int m, int dist) {
    int count = 1; // place first ball at first basket
    int lastPos = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - lastPos >= dist) {
            count++;
            lastPos = pos[i];
            if (count == m) return 1; // successfully placed all balls
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    long long diff = (*(int*)a - *(int*)b);
    return (diff > 0) - (diff < 0);
}

int maxDistance(int *position, int n, int m) {
    // Sort basket positions
    qsort(position, n, sizeof(int), compare);

    int low = 1;
    int high = position[n-1] - position[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(position, n, m, mid)) {
            result = mid;   // feasible, try larger distance
            low = mid + 1;
        } else {
            high = mid - 1; // not feasible, reduce distance
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int position[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    printf("%d\n", maxDistance(position, n, m));
    return 0;
}
