// Problem: Perform DFS starting from a given source vertex using recursion.
// Input: - n - adjacency list - starting vertex s Output: - DFS traversal order

#include <stdio.h>

#define MAX 200

int visited[MAX];

void dfs(int adj[MAX][MAX], int n, int s) {
    visited[s] = 1;
    printf("%d ", s);
    for (int i = 0; i < n; i++) {
        if (adj[s][i] == 1 && !visited[i]) {
            dfs(adj, n, i);
        }
    }
}

int main() {
    int n, s;
    scanf("%d", &n);
    int adj[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    scanf("%d", &s);
    for (int i = 0; i < n; i++) visited[i] = 0;
    dfs(adj, n, s);
    return 0;
}
