/*
Problem Statement:
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format:
n m
u v w
source

Output Format:
Distances to all vertices.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int v, w;
    struct Edge* next;
};

struct Edge* adj[100005];
int dist[100005];
int visited[100005];

struct Node {
    int vertex, dist;
};

struct Heap {
    struct Node* arr;
    int size;
};

void push(struct Heap* h, int v, int d) {
    h->arr[++h->size].vertex = v;
    h->arr[h->size].dist = d;
    int i = h->size;
    while (i > 1 && h->arr[i].dist < h->arr[i/2].dist) {
        struct Node temp = h->arr[i];
        h->arr[i] = h->arr[i/2];
        h->arr[i/2] = temp;
        i /= 2;
    }
}

struct Node pop(struct Heap* h) {
    struct Node root = h->arr[1];
    h->arr[1] = h->arr[h->size--];
    int i = 1;
    while (1) {
        int smallest = i;
        int l = 2*i, r = 2*i+1;
        if (l <= h->size && h->arr[l].dist < h->arr[smallest].dist) smallest = l;
        if (r <= h->size && h->arr[r].dist < h->arr[smallest].dist) smallest = r;
        if (smallest != i) {
            struct Node temp = h->arr[i];
            h->arr[i] = h->arr[smallest];
            h->arr[smallest] = temp;
            i = smallest;
        } else break;
    }
    return root;
}

void addEdge(int u, int v, int w) {
    struct Edge* e = (struct Edge*)malloc(sizeof(struct Edge));
    e->v = v; e->w = w; e->next = adj[u];
    adj[u] = e;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int source;
    scanf("%d", &source);

    struct Heap h;
    h.arr = (struct Node*)malloc((m*2+5) * sizeof(struct Node));
    h.size = 0;

    dist[source] = 0;
    push(&h, source, 0);

    while (h.size > 0) {
        struct Node node = pop(&h);
        int u = node.vertex;
        if (visited[u]) continue;
        visited[u] = 1;
        for (struct Edge* e = adj[u]; e != NULL; e = e->next) {
            int v = e->v, w = e->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
