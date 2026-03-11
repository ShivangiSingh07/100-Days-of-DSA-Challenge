/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash map node
typedef struct {
    int key;
    int count;
} Node;

// Min-heap for top k
typedef struct {
    Node* arr;
    int size;
    int capacity;
} MinHeap;

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Node a, Node b) {
    return a.count - b.count; // min-heap based on frequency
}

void heapifyDown(MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && compare(heap->arr[left], heap->arr[smallest]) < 0)
        smallest = left;
    if (right < heap->size && compare(heap->arr[right], heap->arr[smallest]) < 0)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void heapifyUp(MinHeap* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (compare(heap->arr[i], heap->arr[parent]) < 0) {
            swap(&heap->arr[i], &heap->arr[parent]);
            i = parent;
        } else break;
    }
}

void pushHeap(MinHeap* heap, Node node) {
    if (heap->size < heap->capacity) {
        heap->arr[heap->size++] = node;
        heapifyUp(heap, heap->size - 1);
    } else if (compare(node, heap->arr[0]) > 0) {
        heap->arr[0] = node;
        heapifyDown(heap, 0);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Step 1: Count frequencies using hash map
    int mapSize = numsSize;
    Node* map = (Node*)malloc(mapSize * sizeof(Node));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (map[j].key == nums[i]) {
                map[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            map[count].key = nums[i];
            map[count].count = 1;
            count++;
        }
    }

    // Step 2: Use min-heap to keep top k
    MinHeap heap;
    heap.arr = (Node*)malloc(k * sizeof(Node));
    heap.size = 0;
    heap.capacity = k;

    for (int i = 0; i < count; i++) {
        pushHeap(&heap, map[i]);
    }

    // Step 3: Extract results
    int* result = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    for (int i = 0; i < k; i++) {
        result[i] = heap.arr[i].key;
    }

    free(map);
    free(heap.arr);
    return result;
}
