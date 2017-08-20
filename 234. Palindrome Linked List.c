/*
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *fast, *slow;
    struct ListNode *half = NULL, *tail = NULL;
    struct ListNode *p;
    
    fast = slow = head;
    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    if (fast && fast->next) {
        half = slow->next;
    } else {
        half = slow;
    }
    
    while (half) {
        p = half->next;
        half->next = tail;
        tail = half;
        half = p;
    }
    
    while (tail) {
        if (tail->val != head->val) return false;
        tail = tail->next;
        head = head->next;
    }
    
    return true;
}


/*
Difficulty:Easy
Total Accepted:113.4K
Total Submissions:346.7K


Companies Amazon Facebook
Related Topics Linked List Two Pointers
Similar Questions 
                
                  
                    Palindrome Number
                  
                    Valid Palindrome
                  
                    Reverse Linked List
*/
