/*
 Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).

*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

struct TreeNode* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return NULL;

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct Queue q = {NULL, NULL};
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int levelCount = 0;
        struct QueueNode* temp = q.front;
        while (temp) {
            levelCount++;
            temp = temp->next;
        }

        int* level = (int*)malloc(levelCount * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelCount;

        for (int i = 0; i < levelCount; i++) {
            struct TreeNode* node = dequeue(&q);
            level[i] = node->val;
            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        result[*returnSize] = level;
        (*returnSize)++;
    }

    return result;
}
