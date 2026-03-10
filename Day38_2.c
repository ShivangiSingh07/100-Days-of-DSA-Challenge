/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/
#include <stdio.h>
#include <stdlib.h>

// Deque structure for indices
typedef struct {
    int *data;
    int front, rear, size, capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(sizeof(int) * capacity);
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    dq->capacity = capacity;
    return dq;
}

int isEmpty(Deque* dq) { return dq->size == 0; }
int isFull(Deque* dq) { return dq->size == dq->capacity; }

void push_back(Deque* dq, int val) {
    if (isFull(dq)) return;
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->data[dq->rear] = val;
    dq->size++;
}

void pop_back(Deque* dq) {
    if (isEmpty(dq)) return;
    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;
}

void pop_front(Deque* dq) {
    if (isEmpty(dq)) return;
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
}

int front(Deque* dq) { return dq->data[dq->front]; }
int back(Deque* dq) { return dq->data[dq->rear]; }

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;

    Deque* dq = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
        // Remove indices out of window
        if (!isEmpty(dq) && front(dq) <= i - k) {
            pop_front(dq);
        }

        // Remove smaller elements from back
        while (!isEmpty(dq) && nums[back(dq)] <= nums[i]) {
            pop_back(dq);
        }

        // Add current index
        push_back(dq, i);

        // Record max once window size is reached
        if (i >= k - 1) {
            result[*returnSize] = nums[front(dq)];
            (*returnSize)++;
        }
    }

    free(dq->data);
    free(dq);
    return result;
}

// Test driver
int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int returnSize;
    int* result = maxSlidingWindow(nums, 8, k, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
