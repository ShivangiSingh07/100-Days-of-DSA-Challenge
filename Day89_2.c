/*
Problem Statement:
A conveyor belt has packages that must be shipped from one port to another within 'days' days.
The ith package has weight = weights[i]. Each day, we load the ship with packages in order.
We may not exceed the ship's maximum weight capacity.

Return the least weight capacity of the ship that will result in all packages being shipped
within 'days' days.

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15

Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6

Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
*/

#include <stdio.h>

// Check if ship capacity 'cap' can ship all packages within 'days'
int canShip(int weights[], int n, int days, int cap) {
    int usedDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] > cap) return 0; // single package exceeds capacity
        if (currentLoad + weights[i] > cap) {
            usedDays++;
            currentLoad = weights[i];
            if (usedDays > days) return 0;
        } else {
            currentLoad += weights[i];
        }
    }
    return 1;
}

int shipWithinDays(int weights[], int n, int days) {
    int low = weights[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (weights[i] > low) low = weights[i]; // minimum capacity = max single weight
        high += weights[i];                     // maximum capacity = sum of all weights
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(weights, n, days, mid)) {
            result = mid;
            high = mid - 1; // try smaller capacity
        } else {
            low = mid + 1;  // need larger capacity
        }
    }
    return result;
}

int main() {
    int n, days;
    scanf("%d %d", &n, &days);

    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("%d\n", shipWithinDays(weights, n, days));
    return 0;
}
