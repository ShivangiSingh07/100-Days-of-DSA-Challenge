/*
## Design Circular Deque

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int count;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->size = k;
    obj->front = 0;
    obj->rear = -1;
    obj->count = 0;
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->count == obj->size) return false; // full
    obj->front = (obj->front - 1 + obj->size) % obj->size;
    obj->arr[obj->front] = value;
    obj->count++;
    if (obj->count == 1) obj->rear = obj->front;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->count == obj->size) return false; // full
    obj->rear = (obj->rear + 1) % obj->size;
    obj->arr[obj->rear] = value;
    obj->count++;
    if (obj->count == 1) obj->front = obj->rear;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->count == 0) return false; // empty
    obj->front = (obj->front + 1) % obj->size;
    obj->count--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->count == 0) return false; // empty
    obj->rear = (obj->rear - 1 + obj->size) % obj->size;
    obj->count--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->count == 0) return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->count == 0) return -1;
    return obj->arr[obj->rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->count == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->count == obj->size;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}
