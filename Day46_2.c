/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

// Queue node for BFS
struct QueueNode {
    struct TreeNode* node;
    int level;
};

// Simple queue implementation
struct Queue {
    struct QueueNode* arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct QueueNode*)malloc(capacity * sizeof(struct QueueNode));
    return q;
}

int isEmpty(struct Queue* q) { return q->size == 0; }

void enqueue(struct Queue* q, struct TreeNode* node, int level) {
    if (q->size == q->capacity) return; // overflow check
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear].node = node;
    q->arr[q->rear].level = level;
    q->size++;
}

struct QueueNode dequeue(struct Queue* q) {
    struct QueueNode item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Max nodes = 2000 (constraint)
    struct Queue* q = createQueue(2000);
    enqueue(q, root, 0);

    // Allocate space for results
    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    // Temporary storage for each level
    int* levelData[2000]; // pointers to arrays
    int levelCount[2000]; // sizes of each level

    for (int i = 0; i < 2000; i++) {
        levelData[i] = (int*)malloc(2000 * sizeof(int));
        levelCount[i] = 0;
    }

    while (!isEmpty(q)) {
        struct QueueNode current = dequeue(q);
        struct TreeNode* node = current.node;
        int level = current.level;

        levelData[level][levelCount[level]++] = node->val;

        if (node->left) enqueue(q, node->left, level + 1);
        if (node->right) enqueue(q, node->right, level + 1);
    }

    // Build final result
    for (int i = 0; i < 2000 && levelCount[i] > 0; i++) {
        result[i] = (int*)malloc(levelCount[i] * sizeof(int));
        for (int j = 0; j < levelCount[i]; j++) {
            result[i][j] = levelData[i][j];
        }
        (*returnColumnSizes)[i] = levelCount[i];
        (*returnSize)++;
    }

    return result;
}
