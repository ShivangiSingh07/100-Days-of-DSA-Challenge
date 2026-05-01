/*
Problem:
Given a collection of intervals, merge all overlapping intervals.

Approach:
1. Sort intervals by start time.
2. Traverse the sorted intervals:
   - Compare current interval with the last merged one.
   - If they overlap (current.start <= merged.end), update merged.end = max(merged.end, current.end).
   - Otherwise, add current interval as a new merged interval.
3. Print the merged intervals.

Input:
- First line: integer n (number of intervals)
- Next n lines: two integers (start, end) for each interval

Output:
- Merged intervals

Example:
Input:
4
1 3
2 6
8 10
15 18

Output:
1 6
8 10
15 18
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by start time)
int cmp(const void* a, const void* b) {
    int s1 = ((int*)a)[0];
    int s2 = ((int*)b)[0];
    return s1 - s2;
}

void mergeIntervals(int intervals[][2], int n) {
    // Step 1: Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    // Step 2: Traverse and merge
    int merged[n][2];
    int idx = 0;

    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= merged[idx][1]) {
            // Overlap → extend end
            if (intervals[i][1] > merged[idx][1])
                merged[idx][1] = intervals[i][1];
        } else {
            // No overlap → new interval
            idx++;
            merged[idx][0] = intervals[i][0];
            merged[idx][1] = intervals[i][1];
        }
    }

    // Print merged intervals
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", merged[i][0], merged[i][1]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    mergeIntervals(intervals, n);
    return 0;
}
