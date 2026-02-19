/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/
#include <stdio.h>
#include <limits.h>

int kadaneMax(int* nums, int n) {
    int maxEndingHere = nums[0];
    int maxSoFar = nums[0];
    for (int i = 1; i < n; i++) {
        maxEndingHere = (nums[i] > maxEndingHere + nums[i]) ? nums[i] : maxEndingHere + nums[i];
        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
        }
    }
    return maxSoFar;
}

int kadaneMin(int* nums, int n) {
    int minEndingHere = nums[0];
    int minSoFar = nums[0];
    for (int i = 1; i < n; i++) {
        minEndingHere = (nums[i] < minEndingHere + nums[i]) ? nums[i] : minEndingHere + nums[i];
        if (minEndingHere < minSoFar) {
            minSoFar = minEndingHere;
        }
    }
    return minSoFar;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    int normalMax = kadaneMax(nums, numsSize);

    // Compute total sum
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    int minSubarray = kadaneMin(nums, numsSize);

    // If all numbers are negative, return normalMax
    if (totalSum == minSubarray) {
        return normalMax;
    }

    int circularMax = totalSum - minSubarray;
    return (normalMax > circularMax) ? normalMax : circularMax;
}
