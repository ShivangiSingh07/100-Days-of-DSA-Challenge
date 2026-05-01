/*
Problem:
Given n real numbers in [0,1), sort them using the Bucket Sort algorithm.
Steps:
1. Distribute the numbers into n buckets based on their value.
2. Sort each bucket individually (using insertion sort).
3. Concatenate all buckets to form the sorted array.

Input:
- First line: integer n (size of array)
- Second line: n space-separated real numbers in [0,1)

Output:
- Print the sorted array

Example:
Input:
5
0.78 0.17 0.39 0.26 0.72

Output:
0.17 0.26 0.39 0.72 0.78
*/

#include <stdio.h>
#include <stdlib.h>

// Insertion sort for each bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // Step 1: Create n empty buckets
    float *buckets[n];
    int bucketSizes[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]); // bucket index
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }

    // Step 3: Sort each bucket
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Step 4: Concatenate buckets
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    return 0;
}
