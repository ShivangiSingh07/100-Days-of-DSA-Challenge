/*
Lowest Common Ancestor of a Binary Search Tree (BST)
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;   // both nodes in left subtree
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;  // both nodes in right subtree
        } else {
            return root;         // split point → LCA found
        }
    }
    return NULL;
}

int main() {
    int N;
    scanf("%d", &N);
    struct TreeNode* root = NULL;

    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int pVal, qVal;
    scanf("%d %d", &pVal, &qVal);

    // Create dummy nodes for p and q
    struct TreeNode pNode = {pVal, NULL, NULL};
    struct TreeNode qNode = {qVal, NULL, NULL};

    struct TreeNode* lca = lowestCommonAncestor(root, &pNode, &qNode);
    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}
