/*
This is the same problem as question1 but framed on LeetCode.

Alternative approach without heap:
1. Separate start[] and end[] arrays.
2. Sort both arrays.
3. Use two pointers to count overlaps.
*/
int minMeetingRooms(int** intervals, int intervalsSize) {
    if (intervalsSize == 0) return 0;

    int* start = (int*)malloc(intervalsSize * sizeof(int));
    int* end = (int*)malloc(intervalsSize * sizeof(int));

    for (int i = 0; i < intervalsSize; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, intervalsSize, sizeof(int), (__compar_fn_t)strcmp);
    qsort(end, intervalsSize, sizeof(int), (__compar_fn_t)strcmp);

    int rooms = 0, endPtr = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (start[i] < end[endPtr]) rooms++;
        else endPtr++;
    }

    free(start);
    free(end);
    return rooms;
}
