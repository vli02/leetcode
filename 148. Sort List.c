/*
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4


Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* divide(struct ListNode *p) {
    struct ListNode *a, *b;
    a = p;
    b = p->next;
    
    while (b) {
        b = b->next;        // b moves two steps
        if (b) {
            a = a->next;    // a moves one steps
            b = b->next;
        }
    }
    
    b = a->next;            // this is the middle point
    a->next = NULL;
    
    return b;
}
​
struct ListNode* merge(struct ListNode *a, struct ListNode *b) {
    struct ListNode head, *p, *c;
    
    p = &head;
    
    while (a && b) {
        if (a->val < b->val) {
            c = a;
            a = a->next;

            c = b;
            b = b->next;
        }
        p->next = c;
        p = c;
    }
    
    p->next = a ? a : b;
    
    return head.next;
}
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *p, *a, *b;
    
    if (!head || !head->next) return head;
    
    p = divide(head);       // divide the list to two
    


/*
Difficulty:Medium


*/
