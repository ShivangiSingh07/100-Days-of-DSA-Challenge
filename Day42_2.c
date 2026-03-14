/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ---------- Heap Utilities ----------
typedef struct {
    int *arr;
    int size;
    int capacity;
    int isMinHeap; // 1 for min-heap, 0 for max-heap
} Heap;

Heap* createHeap(int capacity, int isMinHeap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->arr = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    h->isMinHeap = isMinHeap;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

int compare(Heap* h, int a, int b) {
    return h->isMinHeap ? a > b : a < b;
}

void heapifyUp(Heap* h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (compare(h, h->arr[parent], h->arr[idx])) {
            swap(&h->arr[parent], &h->arr[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(Heap* h, int idx) {
    while (1) {
        int left = 2 * idx + 1, right = 2 * idx + 2, best = idx;
        if (left < h->size && compare(h, h->arr[best], h->arr[left])) best = left;
        if (right < h->size && compare(h, h->arr[best], h->arr[right])) best = right;
        if (best != idx) {
            swap(&h->arr[idx], &h->arr[best]);
            idx = best;
        } else break;
    }
}

void heapPush(Heap* h, int val) {
    h->arr[h->size++] = val;
    heapifyUp(h, h->size - 1);
}

int heapTop(Heap* h) {
    return h->arr[0];
}

int heapPop(Heap* h) {
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

// ---------- MedianFinder ----------
typedef struct {
    Heap* left;  // max-heap
    Heap* right; // min-heap
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->left = createHeap(50000, 0);  // max-heap
    obj->right = createHeap(50000, 1); // min-heap
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->left->size == 0 || num <= heapTop(obj->left)) {
        heapPush(obj->left, num);
    } else {
        heapPush(obj->right, num);
    }

    // Balance heaps
    if (obj->left->size > obj->right->size + 1) {
        heapPush(obj->right, heapPop(obj->left));
    } else if (obj->right->size > obj->left->size) {
        heapPush(obj->left, heapPop(obj->right));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->left->size > obj->right->size) {
        return (double)heapTop(obj->left);
    } else {
        return ((double)heapTop(obj->left) + (double)heapTop(obj->right)) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->left->arr);
    free(obj->right->arr);
    free(obj->left);
    free(obj->right);
    free(obj);
}
