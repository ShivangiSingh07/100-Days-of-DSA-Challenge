/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Constraints:
- The number of nodes in the tree is in the range [1, 1000].
- Node.val == 0
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cameras;

// DFS helper function
// States:
// 0 -> Node needs camera
// 1 -> Node has camera
// 2 -> Node is covered
int dfs(struct TreeNode* root) {
    if (root == NULL) return 2; // Null nodes are covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1; // Place camera here
    }
    if (left == 1 || right == 1) {
        return 2; // Covered by child camera
    }
    return 0; // Needs camera
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 0) {
        cameras++; // Root needs camera
    }
    return cameras;
}
