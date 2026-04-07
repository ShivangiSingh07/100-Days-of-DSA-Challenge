/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];   // adjacency matrix
int V;                 // number of vertices

bool visited[MAX];
bool recStack[MAX];

bool dfsCycle(int v) {
    visited[v] = true;
    recStack[v] = true;

    for (int u = 0; u < V; u++) {
        if (graph[v][u]) {  // edge exists
            if (!visited[u] && dfsCycle(u))
                return true;
            else if (recStack[u])
                return true;
        }
    }

    recStack[v] = false; // backtrack
    return false;
}

bool isCyclic() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycle(i))
                return true;
        }
    }
    return false;
}

int main() {
    int E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // directed edge u -> v
    }

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
