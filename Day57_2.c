/*
Problem: Flatten Binary Tree to Linked List (LeetCode 114)

Given the root of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same TreeNode structure where the right child pointer points to the next node in the list.
- The left child pointer should always be NULL.
- The linked list should follow the pre-order traversal of the binary tree.

Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]

Constraints:
- Number of nodes: [0, 2000]
- Node values: [-100, 100]
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    if (root->left) {
        struct TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        struct TreeNode* curr = root->right;
        while (curr->right) {
            curr = curr->right;
        }
        curr->right = temp;
    }
}

void printFlattened(struct TreeNode* root) {
    while (root) {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;

    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;

    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 5;

    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 3;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 4;

    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 6;

    root->right->left = NULL;
    root->left->left->left = root->left->left->right = NULL;
    root->left->right->left = root->left->right->right = NULL;
    root->right->right->left = root->right->right->right = NULL;

    flatten(root);
    printFlattened(root);

    return 0;
}
