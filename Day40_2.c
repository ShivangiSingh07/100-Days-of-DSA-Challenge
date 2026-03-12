/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    // Allocate result array initialized to 0
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;

    // Stack to store indices of temperatures
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1; // stack pointer

    for (int i = 0; i < temperaturesSize; i++) {
        // While current temperature is greater than the temperature at stack top
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--]; // pop
            answer[prevIndex] = i - prevIndex; // days waited
        }
        // Push current index onto stack
        stack[++top] = i;
    }

    free(stack);
    return answer;
}

// Example usage
int main() {
    int temps[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temps)/sizeof(temps[0]);
    int returnSize;

    int* result = dailyTemperatures(temps, n, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(",");
    }
    printf("]\n");

    free(result);
    return 0;
}
