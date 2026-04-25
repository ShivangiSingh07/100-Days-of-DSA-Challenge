/*
Problem: A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 (peak = 2) or index number 5 (peak = 6).
*/

#include <stdio.h>

int findPeakElement(int* nums, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            // Peak lies on the left side (including mid)
            right = mid;
        } else {
            // Peak lies on the right side
            left = mid + 1;
        }
    }
    return left; // or right, both point to a peak
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int peakIndex = findPeakElement(nums, n);
    printf("%d\n", peakIndex);

    return 0;
}
