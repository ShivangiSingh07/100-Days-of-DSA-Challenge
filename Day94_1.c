/*
Problem:
Sort an array of non-negative integers using Counting Sort.
Steps:
1. Find the maximum element in the array.
2. Build a frequency array (count array).
3. Compute prefix sums in the count array.
4. Build the output array using the count array.
5. Print the sorted array.

Input:
- First line: integer n (size of array)
- Second line: n space-separated non-negative integers

Output:
- Print the sorted array

Example:
Input:
5
4 2 2 8 3

Output:
2 2 3 4 8
*/

#include <stdio.h>

void countingSort(int arr[], int n) {
    // Step 1: Find max element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Build frequency array
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 3: Compute prefix sums
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 4: Build output array
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 5: Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
