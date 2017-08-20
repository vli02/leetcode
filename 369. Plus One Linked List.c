/*
369. Plus One Linked List

Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int plus(struct ListNode *node) {
    int one;
    if (!node->next) {
        one = (node->val + 1) / 10;
        node->val = (node->val + 1) % 10;
        return one;
    }
    one = plus(node->next);
    if (one) {
        one = (node->val + 1) / 10;
        node->val = (node->val + 1) % 10;
    }
    return one;
}
struct ListNode* plusOne(struct ListNode* head) {
    struct ListNode *node = head;
    int one = plus(node);
    if (one) {
        node = malloc(sizeof(struct ListNode));
        //assert(node);
        node->val = 1;
        node->next = head;
    }
    return node;
}


/*
Difficulty:Medium
Total Accepted:16K
Total Submissions:29.5K


Companies Google
Related Topics Linked List
Similar Questions 
                
                  
                    Plus One
*/
