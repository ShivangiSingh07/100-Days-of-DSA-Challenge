/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;      // main stack
    int *minData;   // stack to track minimums
    int top;        // index for main stack
    int minTop;     // index for min stack
    int capacity;   // stack capacity
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 10000; // enough for constraints
    obj->data = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minData = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->data[++obj->top] = val;
    if (obj->minTop == -1 || val <= obj->minData[obj->minTop]) {
        obj->minData[++obj->minTop] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) return; // empty stack
    int popped = obj->data[obj->top--];
    if (popped == obj->minData[obj->minTop]) {
        obj->minTop--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minData[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->minData);
    free(obj);
}
