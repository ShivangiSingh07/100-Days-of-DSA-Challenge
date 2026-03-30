// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Medium
// Topics
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
// and inorder is the inorder traversal of the same tree, construct and return the binary tree.

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int search(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct TreeNode* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, root->val);

    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preIndex);
}
