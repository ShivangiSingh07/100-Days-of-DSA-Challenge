/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

Problem:
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] 
represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance 
is at most distanceThreshold. If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3

Example 2:
Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
*/

#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {
    int dist[n][n];

    // Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // Fill in edge weights
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Count reachable cities for each city
    int resultCity = -1;
    int minReachable = INT_MAX;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }
        // Choose city with smallest count, break ties with larger index
        if (count <= minReachable) {
            minReachable = count;
            resultCity = i;
        }
    }

    return resultCity;
}

// Example driver
int main() {
    int n = 4;
    int edges[][3] = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int edgesSize = 4;
    int distanceThreshold = 4;

    int city = findTheCity(n, edges, edgesSize, distanceThreshold);
    printf("%d\n", city); // Expected output: 3

    return 0;
}
