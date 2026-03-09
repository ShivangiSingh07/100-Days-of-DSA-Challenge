/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/
#include <stdio.h>

#define MAX 1000   // maximum size of the queue

int arr[MAX];
int size = 0;

// Insert operation
void insert(int x) {
    if (size < MAX) {
        arr[size++] = x;
    }
}

// Find index of smallest element
int findMinIndex() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete operation
int delete() {
    if (size == 0) return -1;
    int minIndex = findMinIndex();
    int deleted = arr[minIndex];
    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return deleted;
}

// Peek operation
int peek() {
    if (size == 0) return -1;
    int minIndex = findMinIndex();
    return arr[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {   // insert
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') {   // delete
            printf("%d\n", delete());
        } else if (op[0] == 'p') {   // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}
