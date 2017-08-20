/*
82. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.


For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *a, *b, *prev = NULL;
    a = head;
    head = NULL;
    while (a) {
        b = a->next;
        if (!b || a->val != b->val) {
            if (!prev) head = a;
            else prev->next = a;
            prev = a;
        } else {
            do {  // skip all duplicated ones
                b = b->next;
            } while (b && b->val == a->val);
        }
        a = b;
    }
    if (prev) prev->next = NULL;
    return head;
}


/*
Difficulty:Medium
Total Accepted:113.1K
Total Submissions:384.1K


Related Topics Linked List

*/
