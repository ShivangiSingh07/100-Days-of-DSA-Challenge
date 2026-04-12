/*
Problem: Min Cost to Connect All Points
You are given an array points representing integer coordinates of some points on a 2D-plane.
The cost of connecting two points [xi, yi] and [xj, yj] is the Manhattan distance:
|xi - xj| + |yi - yj|.

Return the minimum cost to make all points connected.
All points are connected if there is exactly one simple path between any two points.

Example:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate Manhattan distance
int manhattan(int *a, int *b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int *minDist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }

    int result = 0;
    minDist[0] = 0; // start from point 0

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = manhattan(points[u], points[v]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(visited);
    return result;
}

// Example usage
int main() {
    int arr[5][2] = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int* points[5];
    int colSize = 2;
    for (int i = 0; i < 5; i++) points[i] = arr[i];

    printf("%d\n", minCostConnectPoints(points, 5, &colSize)); // Output: 20
    return 0;
}
