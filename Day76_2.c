/*
133. Clone Graph (LeetCode)

Problem:
Given a reference of a node in a connected undirected graph,
return a deep copy (clone) of the graph.

Approach:
- Use DFS to traverse the graph.
- Maintain a mapping from original node value to cloned node.
- For each neighbor, recursively clone if not already cloned.

Constraints:
- Node values are unique and in [1,100].
- Graph is connected.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Array to store cloned nodes (index by val)
struct Node* cloned[101];

// Helper function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->numNeighbors = 0;
    newNode->neighbors = NULL;
    return newNode;
}

// DFS clone function
struct Node* dfsClone(struct Node* node) {
    if (!node) return NULL;

    // If already cloned, return it
    if (cloned[node->val]) return cloned[node->val];

    // Create clone
    struct Node* copy = createNode(node->val);
    cloned[node->val] = copy;

    // Allocate neighbors array
    copy->numNeighbors = node->numNeighbors;
    copy->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Clone neighbors recursively
    for (int i = 0; i < node->numNeighbors; i++) {
        copy->neighbors[i] = dfsClone(node->neighbors[i]);
    }

    return copy;
}

// Main function
struct Node* cloneGraph(struct Node* s) {
    // Initialize cloned array
    for (int i = 0; i < 101; i++) cloned[i] = NULL;
    return dfsClone(s);
}
