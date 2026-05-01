/*
Problem:
Given an integer array nums and an integer k, return the kth largest element in the array.
Note: It is the kth largest element in sorted order, not the kth distinct element.
Solve without using the library's sort function.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include <stdio.h>

// Lomuto partition scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

// Quickselect function
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k) return arr[pi];
        else if (pi < k) return quickSelect(arr, pi + 1, high, k);
        else return quickSelect(arr, low, pi - 1, k);
    }
    return -1; // should not happen
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // kth largest → index (n - k) in sorted order
    int index = n - k;
    int result = quickSelect(nums, 0, n - 1, index);

    printf("%d\n", result);
    return 0;
}
