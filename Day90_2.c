/*
Problem Statement:
Given an integer array nums and an integer k, split nums into k non-empty subarrays
such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: Best split is [7,2,5] and [10,8], largest sum = 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: Best split is [1,2,3] and [4,5], largest sum = 9.

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 10^6
1 <= k <= min(50, nums.length)
*/

#include <stdio.h>

// Function to check if we can split into <= k subarrays with max sum <= mid
int isPossible(int nums[], int n, int k, long long mid) {
    int count = 1; // number of subarrays
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > mid) return 0; // single element exceeds mid
        if (sum + nums[i] > mid) {
            count++;
            sum = nums[i];
            if (count > k) return 0;
        } else {
            sum += nums[i];
        }
    }
    return 1;
}

// Function to find minimized largest sum
long long splitArray(int nums[], int n, int k) {
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > low) low = nums[i]; // max element
        high += nums[i]; // sum of all elements
    }

    long long result = high;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isPossible(nums, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%lld\n", splitArray(nums, n, k));
    return 0;
}
