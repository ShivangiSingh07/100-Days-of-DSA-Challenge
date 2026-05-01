/*
Problem:
Given meeting intervals (start, end), find the minimum number of rooms required.
Approach:
1. Sort intervals by start time.
2. Use a min-heap (priority queue) to track end times of ongoing meetings.
3. For each interval:
   - If the earliest ending meeting has ended (heap top <= current start), pop it.
   - Push the current meeting’s end time into the heap.
4. The heap size at any point represents the number of rooms in use.
5. The maximum heap size during the process is the answer.

Input:
- First line: integer n (number of meetings)
- Next n lines: two integers (start, end) for each meeting

Output:
- Minimum number of rooms required

Example:
Input:
3
0 30
5 10
15 20

Output:
2
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by start time)
int cmp(const void* a, const void* b) {
    int s1 = ((int*)a)[0];
    int s2 = ((int*)b)[0];
    return s1 - s2;
}

// Min-heap for end times
void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        int temp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = temp;
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0) {
        int parent = (i-1)/2;
        if (heap[parent] <= heap[i]) break;
        int temp = heap[i]; heap[i] = heap[parent]; heap[parent] = temp;
        i = parent;
    }
}

int minMeetingRooms(int intervals[][2], int n) {
    // Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int heap[n]; // store end times
    int heapSize = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0], end = intervals[i][1];

        // Free up rooms that have ended
        if (heapSize > 0 && heap[0] <= start) {
            heap[0] = heap[heapSize-1];
            heapSize--;
            heapifyDown(heap, heapSize, 0);
        }

        // Allocate current meeting
        heap[heapSize++] = end;
        heapifyUp(heap, heapSize-1);

        if (heapSize > maxRooms) maxRooms = heapSize;
    }
    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);
    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d\n", minMeetingRooms(intervals, n));
    return 0;
}
