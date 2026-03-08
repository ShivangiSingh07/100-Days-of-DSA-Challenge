/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
typedef struct {
    struct Node* front;
    struct Node* rear;
} CircularQueue;

// Create a new queue
CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(CircularQueue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = temp;
        q->rear->next = q->front; // circular link
    } else {
        q->rear->next = temp;
        q->rear = temp;
        q->rear->next = q->front; // maintain circularity
    }
}

// Dequeue operation
void dequeue(CircularQueue* q) {
    if (q->front == NULL) {
        return; // empty queue
    }

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // maintain circularity
        free(temp);
    }
}

// Display queue elements
void display(CircularQueue* q) {
    if (q->front == NULL) {
        return;
    }
    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

// Driver code
int main() {
    int n, m, x;
    scanf("%d", &n);

    CircularQueue* q = createQueue();

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    // Number of dequeue operations
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    // Display final queue
    display(q);

    return 0;
}
