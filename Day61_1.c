/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/
#include <stdio.h>

int main() {
    int n, m;
    int directed;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    // Initialize adjacency matrix with 0
    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter %d pairs (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Insert edge into adjacency matrix
        adj[u][v] = 1;
        if (!directed) {
            adj[v][u] = 1; // For undirected graphs
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
