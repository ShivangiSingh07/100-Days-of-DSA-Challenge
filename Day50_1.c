/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

// Define BST Node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Search in BST
int search(struct Node* root, int key) {
    if (root == NULL) return 0; // false
    if (root->key == key) return 1; // true
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Driver code
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 40;
    if (search(root, key))
        printf("Key %d found in BST\n", key);
    else
        printf("Key %d not found in BST\n", key);

    return 0;
}
