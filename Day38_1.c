/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check if empty
int isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Check if full
int isFull(Deque *dq) {
    return dq->size == MAX;
}

// Insert at front
void push_front(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    dq->size++;
}

// Insert at rear
void push_back(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->rear == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
}

// Remove from front
void pop_front(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed %d from front\n", dq->arr[dq->front]);
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    if (dq->size == 0) dq->front = dq->rear = -1;
}

// Remove from rear
void pop_back(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed %d from rear\n", dq->arr[dq->rear]);
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    if (dq->size == 0) dq->front = dq->rear = -1;
}

// Get front element
int front(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get rear element
int back(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Display deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_front(&dq, 20);
    push_back(&dq, 30);
    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));

    pop_front(&dq);
    pop_back(&dq);
    display(&dq);

    return 0;
}
