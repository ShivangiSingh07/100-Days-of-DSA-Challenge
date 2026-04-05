/*
994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:
- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1

Example 3:
Input: grid = [[0,2]]
Output: 0

Constraints:
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 10
- grid[i][j] is 0, 1, or 2.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y;
} Point;

Point queue[MAX*MAX];
int front = 0, rear = 0;

void enqueue(Point p) {
    queue[rear++] = p;
}

Point dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int orangesRotting(int** grid, int m, int n) {
    front = rear = 0;
    int fresh = 0;
    int minutes = 0;

    // Initialize queue with all rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue((Point){i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!isEmpty() && fresh > 0) {
        int size = rear - front; // current level size
        for (int i = 0; i < size; i++) {
            Point p = dequeue();
            for (int d = 0; d < 4; d++) {
                int nx = p.x + dirs[d][0];
                int ny = p.y + dirs[d][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    enqueue((Point){nx, ny});
                }
            }
        }
        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int** grid = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("%d\n", orangesRotting(grid, m, n));

    for (int i = 0; i < m; i++) free(grid[i]);
    free(grid);

    return 0;
}
