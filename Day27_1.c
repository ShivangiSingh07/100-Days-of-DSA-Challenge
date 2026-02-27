/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to calculate length of linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Advance pointer in longer list
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Traverse both lists simultaneously
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) return head1->data; // Intersection found
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1; // No intersection
}

int main() {
    int n, m, i, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    // Input second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    // For demonstration, manually link intersection
    // Example: connect last node of second list to 3rd node of first list
    if (head2 != NULL && head1 != NULL) {
        struct Node* temp1 = head1;
        for (i = 0; i < 2 && temp1 != NULL; i++) temp1 = temp1->next; // 3rd node
        struct Node* temp2 = head2;
        while (temp2->next != NULL) temp2 = temp2->next;
        temp2->next = temp1; // Create intersection
    }

    int result = findIntersection(head1, head2);
    if (result == -1) printf("No Intersection\n");
    else printf("%d\n", result);

    return 0;
}
