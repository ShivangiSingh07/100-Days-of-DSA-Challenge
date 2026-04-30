/*
Problem Statement:
Given an array of integers where each element represents the number of pages in a book,
and m students, allocate books such that each student gets at least one book and the
maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format:
n m
n space-separated integers representing pages in books

Output Format:
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input:
4 2
12 34 67 90

Sample Output:
113

Explanation:
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/

#include <stdio.h>

// Function to check if allocation is possible with maxPages limit
int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) return 0; // single book exceeds limit
        if (sum + books[i] > maxPages) {
            students++;
            sum = books[i];
            if (students > m) return 0;
        } else {
            sum += books[i];
        }
    }
    return 1;
}

int bookAllocation(int books[], int n, int m) {
    int low = books[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (books[i] < low) low = books[i];
        high += books[i];
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(books, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller maximum
        } else {
            low = mid + 1;  // increase limit
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    printf("%d\n", bookAllocation(books, n, m));
    return 0;
}
