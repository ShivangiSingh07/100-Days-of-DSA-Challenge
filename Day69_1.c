/*
Problem:
Given a weighted graph with non-negative edges, compute the shortest path
from a given source vertex using a priority queue (Dijkstra’s Algorithm).

Constraints:
- Graph is represented using adjacency lists.
- Edges have non-negative weights.
- Use a priority queue (min-heap) to efficiently select the next vertex.

Input:
- Number of vertices (V)
- Number of edges (E)
- Each edge: u v w (u → v with weight w)
- Source vertex

Output:
- Shortest distance from source to all vertices
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int vertex;
    int dist;
} Node;

typedef struct {
    Node *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (Node*)malloc(sizeof(Node) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->arr[parent].dist > heap->arr[idx].dist) {
            swap(&heap->arr[parent], &heap->arr[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    int left, right, smallest;
    while (1) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        smallest = idx;
        if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
            smallest = left;
        if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
            smallest = right;
        if (smallest != idx) {
            swap(&heap->arr[smallest], &heap->arr[idx]);
            idx = smallest;
        } else break;
    }
}

void push(MinHeap* heap, int vertex, int dist) {
    if (heap->size == heap->capacity) return;
    heap->arr[heap->size].vertex = vertex;
    heap->arr[heap->size].dist = dist;
    heapifyUp(heap, heap->size);
    heap->size++;
}

Node pop(MinHeap* heap) {
    Node root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

typedef struct AdjNode {
    int dest;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    AdjNode** list;
    int V;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->list = (AdjNode**)malloc(sizeof(AdjNode*) * V);
    for (int i = 0; i < V; i++) graph->list[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int u, int v, int w) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    node->dest = v;
    node->weight = w;
    node->next = graph->list[u];
    graph->list[u] = node;
}

void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    MinHeap* heap = createHeap(V * V);
    push(heap, src, 0);

    while (heap->size > 0) {
        Node node = pop(heap);
        int u = node.vertex;
        AdjNode* temp = graph->list[u];
        while (temp) {
            int v = temp->dest;
            int weight = temp->weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int V, E, src;
    scanf("%d %d", &V, &E);
    Graph* graph = createGraph(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
        addEdge(graph, v, u, w); // if undirected
    }
    scanf("%d", &src);
    dijkstra(graph, src);
    return 0;
}
