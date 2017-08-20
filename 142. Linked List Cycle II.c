/*
142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.



Note: Do not modify the linked list.


Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *n, *nn;
    
    if (!head) return NULL;
    
    n = nn = head;
    do {
        n = n->next;            // one step
        nn = nn->next;
        if (nn) nn = nn->next;  // two steps
    } while (nn && n != nn);
    
    if (!nn) return NULL;
    
    // there is a cycle
    n = head;
    while (n != nn) {
        n = n->next;
        nn = nn->next;
    }
    
    return n;
}


/*
Difficulty:Medium
Total Accepted:119.8K
Total Submissions:386.7K


Related Topics Linked List Two Pointers
Similar Questions Linked List Cycle Find the Duplicate Number

*/
