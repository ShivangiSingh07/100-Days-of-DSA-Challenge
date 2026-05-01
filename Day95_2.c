/*
Problem:
Given an integer array nums, return the maximum difference between two successive elements
in its sorted form. If the array contains less than two elements, return 0.
Algorithm must run in linear time and use linear extra space.

Approach:
Use bucket sort idea:
1. Find min and max.
2. Compute bucket size = ceil((max - min) / (n - 1)).
3. Distribute numbers into buckets storing only min and max.
4. The maximum gap is between successive non-empty buckets.

Example:
Input: [3,6,9,1]
Sorted: [1,3,6,9]
Max gap = 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int n) {
    if (n < 2) return 0;

    int minVal = nums[0], maxVal = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }
    if (minVal == maxVal) return 0;

    int bucketSize = (int)ceil((double)(maxVal - minVal) / (n - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Place numbers into buckets
    for (int i = 0; i < n; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    // Compute maximum gap
    int maxGap = 0;
    int prevMax = minVal;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN) continue; // empty
        if (bucketMin[i] - prevMax > maxGap)
            maxGap = bucketMin[i] - prevMax;
        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    return maxGap;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    printf("%d\n", maximumGap(nums, n));
    return 0;
}
