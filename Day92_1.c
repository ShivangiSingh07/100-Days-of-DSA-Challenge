/*
Problem:
Implement Quick Sort using partition method (Lomuto or Hoare).
Print the sorted array.

Approach:
- Choose a pivot (here, last element).
- Partition the array so that elements <= pivot are on the left,
  and elements > pivot are on the right.
- Recursively apply quick sort on left and right partitions.
*/

#include <stdio.h>

// Lomuto partition scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // pivot element
    int i = low - 1;         // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // place pivot in correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // sort left part
        quickSort(arr, pi + 1, high); // sort right part
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
