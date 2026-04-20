/*
Problem Statement:
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v]
denotes a direct edge from vertex u to v. Find the number of strongly connected
components in the graph.

Input:
V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]

Output:
3
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[MAX];
struct Node* rev[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs1(int u) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v]) dfs1(temp->v);
        temp = temp->next;
    }
    stack[++top] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    struct Node* temp = rev[u];
    while (temp) {
        if (!visited[temp->v]) dfs2(temp->v);
        temp = temp->next;
    }
}

int kosaraju(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs1(i);
    }
    for (int i = 0; i < V; i++) visited[i] = 0;
    int count = 0;
    while (top >= 0) {
        int u = stack[top--];
        if (!visited[u]) {
            dfs2(u);
            count++;
        }
    }
    return count;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        rev[i] = NULL;
        visited[i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(rev, v, u);
    }
    int ans = kosaraju(V);
    printf("%d\n", ans);
    return 0;
}
