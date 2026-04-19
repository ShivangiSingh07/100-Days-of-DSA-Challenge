/*
Problem Statement:
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
Input Format:
n m
u v w
Output Format:
Total weight of MST.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        graph[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int *key = (int *)malloc((n + 1) * sizeof(int));
    int *mstSet = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    for (int i = 1; i <= n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(key);
    free(mstSet);

    return 0;
}
