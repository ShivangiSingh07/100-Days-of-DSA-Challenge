/*
Problem:
For each element in the array, count how many smaller elements appear on its right side.
Return the counts array.

Approach:
Use merge sort technique:
1. Pair each element with its index.
2. During merge, when an element from left half is placed before right half,
   update count for that element with number of elements already moved from right.
3. Continue recursively.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int counts[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pair L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            counts[L[i].idx] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        counts[L[i].idx] += rightCount;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(Pair arr[], int left, int right, int counts[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);
        merge(arr, left, mid, right, counts);
    }
}

int* countSmaller(int* nums, int n) {
    Pair arr[n];
    int* counts = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }
    mergeSort(arr, 0, n - 1, counts);
    return counts;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int* result = countSmaller(nums, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
