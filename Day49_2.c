/*
Problem: Insert into a Binary Search Tree
You are given the root node of a Binary Search Tree (BST) and an integer value val to insert into the tree.
Return the root node of the BST after the insertion.
It is guaranteed that the new value does not exist in the original BST.
There may be multiple valid ways to insert the value, as long as the tree remains a BST after insertion. You may return any of them.
Example 1
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Example 2
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]

Constraints
- The number of nodes in the tree is in the range [0,10^4].
- -10^8\leq \mathrm{Node.val}\leq 10^8.
- All values of Node.val are unique.

*/
#include <stdio.h>
#include <stdlib.h>

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

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);
    root = insertIntoBST(root, 5);

    inorder(root);
    return 0;
}
