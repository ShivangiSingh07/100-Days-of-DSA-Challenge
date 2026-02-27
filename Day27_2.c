/*
Given the head of a singly linked list, the task is to remove a cycle if present.
A cycle exists when a node’s next pointer points back to a previous node, forming a loop.

Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter.

The function should modify the linked list to remove the cycle if it exists.

The terminal will print true if a cycle is removed or if no cycle exists, otherwise it will print false.

Examples
Input: head = 1 -> 3 -> 4, pos = 2  
Output: true  
Explanation: A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0  
Output: true  
Explanation: The linked list does not contain any loop.

Input: head = 1 -> 2 -> 3 -> 4, pos = 1  
Output: true  
Explanation: A loop is present in the list, and it is removed.

Constraints
1
≤
size of linked list
≤
10
5
*/
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
  public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle using Floyd’s algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // If no cycle detected
        if (slow != fast) return;

        // Step 2: Find start of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Break the loop
        Node* start = slow;
        Node* temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = nullptr;
    }
};
