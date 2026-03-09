/*
Kth Largest Element in a Stream

You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:

0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int k;
    int *heap;     // min-heap of size k
    int size;      // current number of elements in heap
} KthLargest;

// Helper functions for min-heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int *heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] > heap[idx]) {
            swap(&heap[parent], &heap[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(int *heap, int size, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != idx) {
            swap(&heap[smallest], &heap[idx]);
            idx = smallest;
        } else break;
    }
}

// Create KthLargest object
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;

    for (int i = 0; i < numsSize; i++) {
        // use add function to insert initial numbers
        int temp = nums[i];
        if (obj->size < obj->k) {
            obj->heap[obj->size++] = temp;
            heapifyUp(obj->heap, obj->size - 1);
        } else if (temp > obj->heap[0]) {
            obj->heap[0] = temp;
            heapifyDown(obj->heap, obj->size, 0);
        }
    }
    return obj;
}

// Add new value and return kth largest
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj->heap, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

// Free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Example usage:
 * KthLargest* obj = kthLargestCreate(3, (int[]){4,5,8,2}, 4);
 * printf("%d\n", kthLargestAdd(obj, 3));  // 4
 * printf("%d\n", kthLargestAdd(obj, 5));  // 5
 * printf("%d\n", kthLargestAdd(obj, 10)); // 5
 * printf("%d\n", kthLargestAdd(obj, 9));  // 8
 * printf("%d\n", kthLargestAdd(obj, 4));  // 8
 * kthLargestFree(obj);
 */
