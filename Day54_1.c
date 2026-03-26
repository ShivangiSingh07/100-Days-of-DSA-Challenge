/*
Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:

Input:

7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.
*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for building tree
struct Queue {
    struct Node **arr;
    int front, rear, size;
};

// Create new node
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

// Check if queue empty
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

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    int leftToRight = 1; // flag

    while (!isEmpty(q)) {
        int count = q->rear - q->front;
        int level[count];
        for (int i = 0; i < count; i++) {
            struct Node* node = dequeue(q);
            level[i] = node->data;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        if (leftToRight) {
            for (int i = 0; i < count; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = count - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }
        leftToRight = !leftToRight; // toggle direction
    }
}

// Driver code
int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);
    zigzagTraversal(root);

    return 0;
}
