/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or N
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int V, E;

int dfs(int v, int parent) {
    visited[v] = 1;
    for (int u = 0; u < V; u++) {
        if (adj[v][u]) {
            if (!visited[u]) {
                if (dfs(u, v)) return 1;  // cycle found
            } else if (u != parent) {
                return 1;  // back edge found → cycle
            }
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    // initialize visited array
    for (int i = 0; i < V; i++) visited[i] = 0;

    // check for cycle
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
