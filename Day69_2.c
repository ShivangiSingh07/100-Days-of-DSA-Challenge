/*
Problem:
You are given a network of n nodes, labeled from 1 to n.
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
where ui is the source node, vi is the target node, and wi is the time it takes for a signal
to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes
to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 105
#define MAXE 6005

typedef struct {
    int v, w;
    struct Edge* next;
} Edge;

typedef struct {
    int node, dist;
} Node;

typedef struct {
    Node *arr;
    int size, capacity;
} MinHeap;

void swap(Node *a, Node *b) {
    Node temp = *a; *a = *b; *b = temp;
}

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (Node*)malloc(sizeof(Node) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heapifyUp(MinHeap* h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->arr[parent].dist > h->arr[idx].dist) {
            swap(&h->arr[parent], &h->arr[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* h, int idx) {
    while (1) {
        int left = 2*idx+1, right = 2*idx+2, smallest = idx;
        if (left < h->size && h->arr[left].dist < h->arr[smallest].dist) smallest = left;
        if (right < h->size && h->arr[right].dist < h->arr[smallest].dist) smallest = right;
        if (smallest != idx) {
            swap(&h->arr[smallest], &h->arr[idx]);
            idx = smallest;
        } else break;
    }
}

void push(MinHeap* h, int node, int dist) {
    if (h->size == h->capacity) return;
    h->arr[h->size].node = node;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

Node pop(MinHeap* h) {
    Node root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

typedef struct {
    Edge* head[MAXN];
    int V;
} Graph;

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i <= V; i++) g->head[i] = NULL;
    return g;
}

void addEdge(Graph* g, int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->v = v; e->w = w;
    e->next = g->head[u];
    g->head[u] = e;
}

int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    Graph* g = createGraph(n);
    for (int i = 0; i < timesSize; i++) {
        addEdge(g, times[i][0], times[i][1], times[i][2]);
    }

    int dist[MAXN];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[k] = 0;

    MinHeap* h = createHeap(n * n);
    push(h, k, 0);

    while (h->size > 0) {
        Node node = pop(h);
        int u = node.node;
        if (node.dist > dist[u]) continue;
        Edge* e = g->head[u];
        while (e) {
            int v = e->v, w = e->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(h, v, dist[v]);
            }
            e = e->next;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > ans) ans = dist[i];
    }
    return ans;
}

int main() {
    int times1[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    printf("%d\n", networkDelayTime(times1, 3, 4, 2)); // Output: 2

    int times2[][3] = {{1,2,1}};
    printf("%d\n", networkDelayTime(times2, 1, 2, 1)); // Output: 1

    int times3[][3] = {{1,2,1}};
    printf("%d\n", networkDelayTime(times3, 1, 2, 2)); // Output: -1

    return 0;
}
