/*
141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.



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
bool hasCycle(struct ListNode *head) {
    struct ListNode *n, *nn;
    
    if (!head) return false;
    
    n = nn = head;
    do {
        n = n->next;            // one step
        nn = nn->next;
        if (nn) nn = nn->next;  // two steps
    } while (nn && n != nn);
    
    if (nn) return true;
    
    return false;
}


/*
Difficulty:Easy
Total Accepted:191.5K
Total Submissions:541.6K


Companies Amazon Microsoft Bloomberg Yahoo
Related Topics Linked List Two Pointers
Similar Questions 
                
                  
                    Linked List Cycle II
*/
