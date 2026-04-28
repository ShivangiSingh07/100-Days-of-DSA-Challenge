/*
Problem: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas 
and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead 
and will not eat any more bananas during this hour.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

#include <stdio.h>

// Function to calculate total hours needed at speed k
long long hoursNeeded(int piles[], int n, int k) {
    long long hours = 0;
    for (int i = 0; i < n; i++) {
        // ceil(piles[i] / k) → (piles[i] + k - 1) / k
        hours += (piles[i] + k - 1) / k;
    }
    return hours;
}

int minEatingSpeed(int piles[], int n, int h) {
    int left = 1;
    int right = 0;
    for (int i = 0; i < n; i++) {
        if (piles[i] > right) right = piles[i]; // max pile size
    }

    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (hoursNeeded(piles, n, mid) <= h) {
            ans = mid;       // possible answer, try smaller k
            right = mid - 1;
        } else {
            left = mid + 1;  // need larger k
        }
    }
    return ans;
}

int main() {
    int n, h;
    scanf("%d", &n);
    int piles[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }
    scanf("%d", &h);

    int result = minEatingSpeed(piles, n, h);
    printf("%d\n", result);

    return 0;
}
