/*
Problem Statement
Given an array of integers containing both positive and negative values, 
find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>
#include <stdlib.h>

struct HashNode {
    int prefixSum;
    int index;
    struct HashNode* next;
};

#define TABLE_SIZE 1000

struct HashNode* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

void insert(int prefixSum, int index) {
    int hashIndex = hashFunction(prefixSum);
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->prefixSum = prefixSum;
    newNode->index = index;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

int search(int prefixSum) {
    int hashIndex = hashFunction(prefixSum);
    struct HashNode* node = hashTable[hashIndex];
    while (node) {
        if (node->prefixSum == prefixSum) return node->index;
        node = node->next;
    }
    return -1;
}

int longestZeroSumSubarray(int arr[], int n) {
    int maxLen = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            if (i + 1 > maxLen) maxLen = i + 1;
        } else {
            int prevIndex = search(sum);
            if (prevIndex != -1) {
                if (i - prevIndex > maxLen) maxLen = i - prevIndex;
            } else {
                insert(sum, i);
            }
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", longestZeroSumSubarray(arr, n));
    return 0;
}
