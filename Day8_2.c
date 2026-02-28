/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/
#include <stdio.h>
#include <stdbool.h>

// Function to check if n is a power of two
bool isPowerOfTwo(int n) {
    // A power of two has exactly one bit set in binary
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n;
    scanf("%d", &n);

    if (isPowerOfTwo(n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
