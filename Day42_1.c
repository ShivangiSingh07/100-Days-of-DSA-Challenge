/*
Reverse a Queue Using Stack
Close
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/
#include <stdio.h>
#include <stdlib.h>

// Queue implementation using array
#define MAX 1000

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmptyQueue(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, int x) {
    q->arr[++q->rear] = x;
}

int dequeue(Queue *q) {
    return q->arr[q->front++];
}

// Stack implementation using array
typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int main() {
    int N;
    scanf("%d", &N);

    Queue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
    }

    Stack s;
    initStack(&s);

    // Step 1: Move all elements from queue to stack
    while (!isEmptyQueue(&q)) {
        push(&s, dequeue(&q));
    }

    // Step 2: Move all elements back from stack to queue
    while (!isEmptyStack(&s)) {
        enqueue(&q, pop(&s));
    }

    // Print reversed queue
    while (!isEmptyQueue(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}
