/*
Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7#include <stdio.h>
#include <stdlib.h>

// Define structure for a binary tree node
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
    if (val == -1) return NULL;
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

// Traversals
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    if (N == 0) return 0;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(N);
    enqueue(q, root);

    int i = 1;
    while (i < N) {
        struct Node* parent = dequeue(q);
        if (parent != NULL) {
            parent->left = newNode(arr[i++]);
            if (parent->left) enqueue(q, parent->left);

            if (i < N) {
                parent->right = newNode(arr[i++]);
                if (parent->right) enqueue(q, parent->right);
            }
        }
    }

    // Print traversals
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
1 2 4 5 3 6 7
4 5 2 6 7 3 1
*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for a binary tree node
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
    if (val == -1) return NULL;
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

// Traversals
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    if (N == 0) return 0;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(N);
    enqueue(q, root);

    int i = 1;
    while (i < N) {
        struct Node* parent = dequeue(q);
        if (parent != NULL) {
            parent->left = newNode(arr[i++]);
            if (parent->left) enqueue(q, parent->left);

            if (i < N) {
                parent->right = newNode(arr[i++]);
                if (parent->right) enqueue(q, parent->right);
            }
        }
    }

    // Print traversals
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}
