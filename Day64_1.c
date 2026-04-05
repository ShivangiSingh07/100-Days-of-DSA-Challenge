/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue implementation
int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n;
    scanf("%d", &n);

    // adjacency list
    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Read adjacency list
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k); // number of neighbors of node i
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            adj[i][v] = 1;
        }
    }

    int source;
    scanf("%d", &source);

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    // BFS
    enqueue(source);
    visited[source] = 1;

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }

    return 0;
}
