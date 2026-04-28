/*
Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted in ascending order)
- Third line: target integer x

Output:
- Print the index of x if found, otherwise -1

Example:
Input:
5
12 22 25 34 64
25

Output:
2
*/

#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid; // found at index mid
        else if (arr[mid] < x)
            left = mid + 1; // search right half
        else
            right = mid - 1; // search left half
    }
    return -1; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x;
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);
    printf("%d\n", result);

    return 0;
}
