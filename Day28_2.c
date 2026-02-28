/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Examples:

Input: head = [1,2,2,1] → Output: true

Input: head = [1,2] → Output: false

Constraints:

The number of nodes in the list is in the range [1, 10^5].

0 <= Node.val <= 9
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // Step 1: Find middle using slow/fast pointers
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode* secondHalf = reverseList(slow->next);

    // Step 3: Compare first half and reversed second half
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalf;
    bool result = true;
    while (p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // (Optional) Step 4: Restore the list
    slow->next = reverseList(secondHalf);

    return result;
}
