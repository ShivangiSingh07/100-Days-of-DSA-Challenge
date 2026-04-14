/*
Question:
684. Redundant Connection (LeetCode)

You are given a graph that started as a tree with n nodes labeled from 1 to n, 
with one additional edge added. Return the edge that can be removed so that the 
resulting graph is a tree. If multiple answers exist, return the one that occurs 
last in the input.

Example:
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
*/

#include <stdio.h>
#include <stdlib.h>

// Find function with path compression
int find(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

// Union function
int unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX == rootY) return 0; // cycle detected

    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
    return 1;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;
    int* parent = (int*)malloc((n+1) * sizeof(int));
    int* rank = (int*)calloc((n+1), sizeof(int));

    for (int i = 1; i <= n; i++) parent[i] = i;

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionSet(parent, rank, u, v)) {
            result[0] = u;
            result[1] = v;
            return result;
        }
    }
    return result;
}
