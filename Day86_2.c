/*
Problem: Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.

Input:
- First line: integer x

Output:
- Print the integer square root of x

Examples:
Input:
4
Output:
2

Input:
8
Output:
2

Constraints:
0 <= x <= 2^31 - 1
*/

#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int left = 0, right = x, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) { // avoid overflow
            ans = mid;        // mid is a candidate
            left = mid + 1;   // search in right half
        } else {
            right = mid - 1;  // search in left half
        }
    }
    return ans;
}

int main() {
    int x;
    scanf("%d", &x);

    int result = mySqrt(x);
    printf("%d\n", result);

    return 0;
}
