/*
Problem:
Sort a singly linked list using insertion sort.

Approach:
- Traverse the list node by node.
- For each node, insert it into the correct position in the already sorted part.
- Maintain a dummy head to simplify insertion logic.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to insert node into sorted list
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;

        // Find position to insert
        struct ListNode* prev = &dummy;
        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert curr between prev and prev->next
        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }
    return dummy.next;
}

// Helper function to print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Helper to create new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* node = newNode(val);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    head = insertionSortList(head);
    printList(head);

    return 0;
}
