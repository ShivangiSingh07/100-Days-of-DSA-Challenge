/*
1192. Critical Connections in a Network
Hard

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

Constraints:
2 <= n <= 10^5
n - 1 <= connections.length <= 10^5
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

#include <stdio.h>
#include <stdlib.h>

int timeCounter;

void dfs(int u, int parent, int* disc, int* low, int** adj, int* adjSize,
         int*** result, int* returnSize, int** returnColumnSizes) {
    disc[u] = low[u] = ++timeCounter;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (v == parent) continue;
        if (disc[v] == -1) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize, returnColumnSizes);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (low[v] > disc[u]) {
                (*result)[*returnSize] = (int*)malloc(2 * sizeof(int));
                (*result)[*returnSize][0] = u;
                (*result)[*returnSize][1] = v;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
        } else {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0], v = connections[i][1];
        adj[u] = (int*)realloc(adj[u], (adjSize[u] + 1) * sizeof(int));
        adj[v] = (int*)realloc(adj[v], (adjSize[v] + 1) * sizeof(int));
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) disc[i] = -1, low[i] = -1;

    *result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    *returnSize = 0;
    timeCounter = 0;

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, disc, low, adj, adjSize, result, returnSize, returnColumnSizes);
        }
    }

    free(disc);
    free(low);
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(adjSize);

    return *result;
}
