/*
Problem: Find Minimum in Rotated Sorted Array
Input:
- First line: integer n
- Second line: n space-separated integers (sorted array rotated between 1 and n times)

Output:
- Print the minimum element of the array

Example 1:
Input:
5
3 4 5 1 2
Output:
1

Example 2:
Input:
7
4 5 6 7 0 1 2
Output:
0

Example 3:
Input:
4
11 13 15 17
Output:
11
*/

#include <stdio.h>

// Function to find minimum in rotated sorted array
int findMin(int nums[], int n) {
    int left = 0, right = n - 1;

    // If array is not rotated at all
    if (nums[left] <= nums[right]) {
        return nums[left];
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid element is the minimum
        if (mid > 0 && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }

        // Decide which half to search
        if (nums[mid] >= nums[left]) {
            // Minimum lies in right half
            left = mid + 1;
        } else {
            // Minimum lies in left half
            right = mid - 1;
        }
    }
    return -1; // Should never reach here if input is valid
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = findMin(nums, n);
    printf("%d\n", result);

    return 0;
}
