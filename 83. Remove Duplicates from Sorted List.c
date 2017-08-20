/*
83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.


For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *prev, *p;
    
    if (!head) return NULL;
    
    prev = head;
    p = prev->next;
    
    while (p) {
        if (prev->val != p->val) {
            prev->next = p;
            prev = p;
        }
        p = p->next;
    }
    prev->next = NULL;
    
    return head;
}


/*
Difficulty:Easy
Total Accepted:191.9K
Total Submissions:481.8K


Related Topics Linked List

*/
