/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:
Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode* queue[200]; // max nodes = 100, safe buffer
    int front = 0, rear = 0;

    int* result = (int*)malloc(100 * sizeof(int)); // max 100 nodes
    *returnSize = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front; // number of nodes at this level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            // If it's the last node of this level, add to result
            if (i == levelSize - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }

    return result;
}
