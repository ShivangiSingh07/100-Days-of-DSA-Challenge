/*
Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;  // Empty tree has no leaf nodes
    }

    // A leaf node has no left or right child
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recursively count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
