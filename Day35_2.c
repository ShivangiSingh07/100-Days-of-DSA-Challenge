/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isEmptyStack(Stack* s) {
    return s->top == -1;
}

void pushStack(Stack* s, int x) {
    s->arr[++s->top] = x;
}

int popStack(Stack* s) {
    return s->arr[s->top--];
}

int peekStack(Stack* s) {
    return s->arr[s->top];
}

// Queue using two stacks
typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    initStack(&q->s1);
    initStack(&q->s2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    pushStack(&obj->s1, x);
}

void transfer(MyQueue* obj) {
    while (!isEmptyStack(&obj->s1)) {
        int val = popStack(&obj->s1);
        pushStack(&obj->s2, val);
    }
}

int myQueuePop(MyQueue* obj) {
    if (isEmptyStack(&obj->s2)) {
        transfer(obj);
    }
    return popStack(&obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmptyStack(&obj->s2)) {
        transfer(obj);
    }
    return peekStack(&obj->s2);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmptyStack(&obj->s1) && isEmptyStack(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

