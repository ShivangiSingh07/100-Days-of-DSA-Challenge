/*
Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.
*/
#include <stdio.h>

// Function to check Min-Heap property
int isMinHeap(int arr[], int n) {
    // For each parent node, check its children
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If left child exists and is smaller than parent
        if (left < n && arr[i] > arr[left])
            return 0;

        // If right child exists and is smaller than parent
        if (right < n && arr[i] > arr[right])
            return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(arr, N))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
