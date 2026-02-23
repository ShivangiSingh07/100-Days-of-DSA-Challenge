/*
Given the head of a singly linked list, determine if the linked list contains a cycle.
A cycle exists if there is a node in the list that can be reached again by continuously following the next pointer.

Internally, pos is used to denote the index of the node that the tail’s next pointer connects to.
Note that pos is not passed as a parameter in the function.

Return:

true if the linked list has a cycle.

false otherwise.

Example 1
Input:  
head = [3,2,0,-4], pos = 1

Output:  
true

Explanation:  
There is a cycle in the linked list where the tail connects to the 1st node (0-indexed).

Example 2
Input:  
head = [1,2], pos = 0

Output:  
true

Explanation:  
There is a cycle in the linked list where the tail connects to the 0th node.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false; // Empty list or single node without cycle
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move one step
        fast = fast->next->next;     // Move two steps
