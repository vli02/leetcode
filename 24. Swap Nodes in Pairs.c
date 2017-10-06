/*
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.



For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.



Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *a, *b, *c;
    
    a = head;
    if (a && a->next) {
        b = a->next;
        c = b->next;
        b->next = a;
        a->next = swapPairs(c);
        return b;
    }
    
    return a;
}

/*
Difficulty:Medium
Total Accepted:181.1K
Total Submissions:470K


Companies Microsoft Bloomberg Uber
Related Topics Linked List
Similar Questions 
                
                  
                    Reverse Nodes in k-Group
*/
