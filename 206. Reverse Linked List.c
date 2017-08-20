/*
206. Reverse Linked List

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *a, *b, *c;
    
    a = NULL;
    b = head;
    while (b) {
        c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
​
    return a;
}


/*
Difficulty:Easy
Total Accepted:245.8K
Total Submissions:541.6K


Companies Uber Facebook Twitter Zenefits Amazon Microsoft Snapchat Apple Yahoo Bloomberg Yelp Adobe
Related Topics Linked List
Similar Questions 
                
                  
                    Reverse Linked List II
                  
                    Binary Tree Upside Down
                  
                    Palindrome Linked List
*/
