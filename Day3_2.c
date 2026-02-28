/* 
You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array
represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element

Examples:
Input: arr[] = [1, 2, 3, 5]
Output: 4
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Input: arr[] = [1]
Editorial
Submissions: 1.6M
Explanation: All the numbers from 1 to 5 are present except 4.
Explanation: All the numbers from 1 to 8 are present except 6.
Output: 2
Explanation: Only 1 is present so the missing element is 2.
Constraints:
1 ≤arr.size()≤106
1 ≤ arr[i] ≤ arr.size() + 1
*/
#include <stdio.h>

int missingNum(int arr[], int n) {
    // Expected sum of numbers from 1 to n
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;

    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int n = 4; // array size is 4, but numbers are from 1..5
    printf("%d\n", missingNum(arr, n + 1)); // pass n+1 as full range
    return 0;
}

