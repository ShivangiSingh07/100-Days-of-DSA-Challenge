/*
785. Is Graph Bipartite?
Medium

Problem Statement:
There is an undirected graph with n nodes, numbered between 0 and n - 1. 
You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. 
More formally, for each v in graph[u], there is an undirected edge between node u and node v.

The graph has the following properties:
- No self-edges (graph[u] does not contain u).
- No parallel edges (graph[u] does not contain duplicate values).
- If v is in graph[u], then u is in graph[v] (the graph is undirected).
- The graph may not be connected.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B 
such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false

Example 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true

Constraints:
graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.
*/

#include <stdbool.h>

bool dfs(int** graph, int* graphColSize, int node, int* color) {
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (color[neighbor] == -1) {
            color[neighbor] = 1 - color[node];
            if (!dfs(graph, graphColSize, neighbor, color)) return false;
        } else if (color[neighbor] == color[node]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[graphSize];
    for (int i = 0; i < graphSize; i++) color[i] = -1;

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!dfs(graph, graphColSize, i, color)) return false;
        }
    }
    return true;
}
