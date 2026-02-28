/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCircularList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        // Allocate memory for new node
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    // Make it circular
    last->next = head;
    return head;
}

// Function to traverse and print circular linked list
void traverseCircularList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) return;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createCircularList(arr, n);
    traverseCircularList(head);

    return 0;
}
