/*
Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   // maximum heap size

int heap[MAX];
int size = 0;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// Swap utility
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert operation
void insert(int x) {
    if (size == MAX) return; // heap full
    heap[size] = x;
    int i = size;
    size++;

    // Bubble up
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}

// Heapify down
void heapify(int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Extract minimum
int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) {
        size--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);

    return root;
}

// Peek minimum
int peek() {
    if (size <= 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
