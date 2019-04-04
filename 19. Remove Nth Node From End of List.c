/*
19. Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.


For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.



Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *a, *b, *p = NULL;
    a = b = head;
    while (n-- > 0) {       // b moves n steps first
        b = b->next;
    }
    
    while (b) {             // a, b move together, keeps a gap of n steps
        p = a;
        a = a->next;
        b = b->next;
    }
    
    if (a == head) {        // a is the one to be removed
        head = a->next;
    } else {
        p->next = a->next;
    }
    free(a);
    
    return head;
}


/*
Difficulty:Medium
Total Accepted:188.5K
Total Submissions:563.1K


Related Topics Linked List Two Pointers

*/
