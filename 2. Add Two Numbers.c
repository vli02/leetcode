/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *p, *q;
    int s = 0;
    
    while (l1 || l2 || s != 0) {
        p = malloc(sizeof(struct ListNode));
        //assert(p);
        if (l1) {
            s += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            s += l2->val;
            l2 = l2->next;
        }
        p->val = s % 10;
        p->next = NULL;
        s = s / 10;
        
        if (!head) {
            head = p;
        }
        if (q) {
            q->next = p;
        }
        q = p;
        
    }
    return head;
}


/*
Difficulty:Medium
Total Accepted:329.9K
Total Submissions:1.2M


Companies Amazon Microsoft Bloomberg Airbnb Adobe
Related Topics Linked List Math
Similar Questions 
                
                  
                    Multiply Strings
                  
                    Add Binary
                  
                    Sum of Two Integers
                  
                    Add Strings
                  
                    Add Two Numbers II
*/
