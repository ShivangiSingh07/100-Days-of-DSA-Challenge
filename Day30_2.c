/*
Problem: Add Two Numbers II
You are given two non‑empty linked lists representing two non‑negative integers.

Digits are stored in forward order (most significant digit first).

Each node contains a single digit.

Return the sum as a linked list, also in forward order.

Example 1
Input:  l1 = [7 → 2 → 4 → 3], l2 = [5 → 6 → 4]
Output: [7 → 8 → 0 → 7]
Example 2
Input:  l1 = [2 → 4 → 3], l2 = [5 → 6 → 4]
Output: [8 → 0 → 7]
Example 3
Input:  l1 = [0], l2 = [0]
Output: [0]

*/
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Utility function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Push values of list into stack
int pushToStack(struct ListNode* l, int* stack) {
    int top = 0;
    while (l) {
        stack[top++] = l->val;
        l = l->next;
    }
    return top; // size of stack
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int stack1[101], stack2[101]; // constraints: max 100 nodes
    int size1 = pushToStack(l1, stack1);
    int size2 = pushToStack(l2, stack2);

    int i = size1 - 1, j = size2 - 1;
    int carry = 0;

    struct ListNode* result = NULL;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += stack1[i--];
        if (j >= 0) sum += stack2[j--];

        carry = sum / 10;
        sum = sum % 10;

        // Insert at head
        struct ListNode* newNode = createNode(sum);
        newNode->next = result;
        result = newNode;
    }

    return result;
}
