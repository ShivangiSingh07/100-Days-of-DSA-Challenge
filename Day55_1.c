/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.
*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for level-order building
struct Queue {
    struct Node **arr;
    int front, rear, size;
};

// Create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Initialize queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);
        if (curr) {
            // Left child
            curr->left = newNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);

            if (i < n) {
                // Right child
                curr->right = newNode(arr[i++]);
                if (curr->right) enqueue(q, curr->right);
            }
        }
    }
    return root;
}

// Print right view using level-order traversal
void rightView(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    while (!isEmpty(q)) {
        int count = q->rear - q->front; // nodes at current level
        for (int i = 0; i < count; i++) {
            struct Node* curr = dequeue(q);

            // Print the last node of each level
            if (i == count - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);
    rightView(root);

    return 0;
}
