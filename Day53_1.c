/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Queue {
    struct Node* node;
    int hd;
    struct Queue* next;
};

struct Queue* push(struct Queue* rear, struct Node* node, int hd) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (rear) rear->next = temp;
    return temp;
}

struct Queue* pop(struct Queue** front) {
    struct Queue* temp = *front;
    if (*front) *front = (*front)->next;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue *front = NULL, *rear = NULL;
    rear = push(rear, root, 0);
    front = rear;
    int i = 1;
    while (front && i < n) {
        struct Queue* qnode = pop(&front);
        struct Node* curr = qnode->node;
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            rear = push(rear, curr->left, 0);
            if (!front) front = rear;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            rear = push(rear, curr->right, 0);
            if (!front) front = rear;
        }
        i++;
    }
    return root;
}

struct List {
    int val;
    struct List* next;
};

struct Map {
    int hd;
    struct List* nodes;
    struct Map* next;
};

struct Map* insertMap(struct Map* head, int hd, int val) {
    struct Map* temp = head;
    while (temp) {
        if (temp->hd == hd) {
            struct List* l = (struct List*)malloc(sizeof(struct List));
            l->val = val;
            l->next = NULL;
            struct List* p = temp->nodes;
            while (p->next) p = p->next;
            p->next = l;
            return head;
        }
        temp = temp->next;
    }
    struct Map* m = (struct Map*)malloc(sizeof(struct Map));
    m->hd = hd;
    m->nodes = (struct List*)malloc(sizeof(struct List));
    m->nodes->val = val;
    m->nodes->next = NULL;
    m->next = head;
    return m;
}

void verticalOrder(struct Node* root) {
    if (!root) return;
    struct Map* map = NULL;
    struct Queue *front = NULL, *rear = NULL;
    rear = push(rear, root, 0);
    front = rear;
    while (front) {
        struct Queue* qnode = pop(&front);
        struct Node* node = qnode->node;
        int hd = qnode->hd;
        map = insertMap(map, hd, node->data);
        if (node->left) {
            rear = push(rear, node->left, hd - 1);
            if (!front) front = rear;
        }
        if (node->right) {
            rear = push(rear, node->right, hd + 1);
            if (!front) front = rear;
        }
    }
    for (int d = -1000; d <= 1000; d++) {
        struct Map* temp = map;
        while (temp) {
            if (temp->hd == d) {
                struct List* l = temp->nodes;
                while (l) {
                    printf("%d ", l->val);
                    l = l->next;
                }
                printf("\n");
                break;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, N);
    verticalOrder(root);
    return 0;
}
