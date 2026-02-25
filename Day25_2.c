/*
Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return NULL.

A cycle exists if some node in the list can be reached again by continuously following the next pointer.
Internally, pos denotes the index of the node that the tail’s next pointer connects to (0-indexed).
pos = -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle where tail connects to the second node.

Example 2
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle where tail connects to the first node.

Example 3
Input: head = [1], pos = -1
Output: no cycle
Explanation: No cycle exists.

Constraints
Number of nodes: [0, 10⁴]

Node values: [-10⁵, 10⁵]

pos is -1 or a valid index in the linked list
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect if cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // cycle detected
            break;
        }
    }

    // If no cycle
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // Step 2: Find the cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // cycle start node
}
