/*
Problem:
Relative Sort Array (LeetCode)
Given two arrays arr1 and arr2:
- arr2 contains distinct elements and defines a relative order.
- Sort arr1 so that:
  1. Elements of arr1 that appear in arr2 are placed first, in the order of arr2.
  2. Remaining elements not in arr2 are placed at the end, in ascending order.

Approach 3: Counting Sort
Steps:
1. Find the maximum element in arr1.
2. Build a frequency array (count) for arr1.
3. For each element in arr2, append it to result count[element] times.
4. Append remaining elements (not in arr2) in ascending order using count array.

Input:
- First line: integer n (size of arr1)
- Second line: n space-separated integers (arr1)
- Third line: integer m (size of arr2)
- Fourth line: m space-separated integers (arr2)

Output:
- Print the sorted array according to relative order.

Example:
Input:
6
2 3 1 3 2 4
4
2 1 4 3

Output:
2 2 1 4 3 3
*/

#include <stdio.h>

void relativeSortArray(int arr1[], int n, int arr2[], int m) {
    // Step 1: Find max element in arr1
    int max = arr1[0];
    for (int i = 1; i < n; i++) {
        if (arr1[i] > max)
            max = arr1[i];
    }

    // Step 2: Build frequency array
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr1[i]]++;

    // Step 3: Place elements of arr2 in result
    int result[n];
    int idx = 0;
    for (int i = 0; i < m; i++) {
        int val = arr2[i];
        while (count[val] > 0) {
            result[idx++] = val;
            count[val]--;
        }
    }

    // Step 4: Place remaining elements in ascending order
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            result[idx++] = i;
            count[i]--;
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    relativeSortArray(arr1, n, arr2, m);
    return 0;
}
