/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
*/
#include <stdio.h>
#include <stdlib.h>

// adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add edge to adjacency list (undirected graph)
void addEdge(struct Node** adjList, int u, int v) {
    struct Node* node = createNode(v);
    node->next = adjList[u];
    adjList[u] = node;

    node = createNode(u);
    node->next = adjList[v];
    adjList[v] = node;
}

// BFS traversal to mark visited vertices
void bfs(struct Node** adjList, int n, int start, int* visited) {
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        struct Node* temp = adjList[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    free(queue);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    struct Node** adjList = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    // visited array
    int* visited = (int*)calloc(n + 1, sizeof(int));

    // run BFS from node 1
    bfs(adjList, n, 1, visited);

    // check if all nodes are visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    // free memory
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adjList[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(adjList);
    free(visited);

    return 0;
}
