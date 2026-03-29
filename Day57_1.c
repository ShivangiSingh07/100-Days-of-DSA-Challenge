/*
Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.
*/#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for building tree from level order
struct Queue {
    struct Node **arr;
    int front, rear, size;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL; // -1 means NULL
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue functions
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
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

// Mirror function
void mirror(struct Node* root) {
    if (root == NULL) return;
    // Swap children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);
    mirror(root);
    inorder(root);

    return 0;
}
