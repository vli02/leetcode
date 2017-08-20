/*
25. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.



k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.


For example,
Given this linked list: 1->2->3->4->5



For k = 2, you should return: 2->1->4->3->5



For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *node, *prev = NULL, *ret = NULL;
    struct ListNode *next;
    struct ListNode **stack;
    int i;
    
    if (k <= 1) return head;
    
    stack = malloc(k * sizeof(struct ListNode *));
    //assert(stack);
    
#define PUSH(NODE) do { stack[i++] = NODE; } while (0)
#define POP(NODE) do { NODE = stack[--i]; } while (0)
    
    node = head;
    
    while (node) {
        i = 0;
        while (i < k && node) {
            PUSH(node);
            node = node->next;
        }
        next = node;
        
        if (i < k) {
            if (!ret) ret = head;
            free(stack);
            return ret;
        }
        
        while (i > 0) {
            POP(node);
            if (!ret) ret = node;
            if (prev) prev->next = node;
            prev = node;
        }
        prev->next = next;
        node = next;
    }
    
    free(stack);
    return ret;
}


/*
Difficulty:Hard
Total Accepted:99.1K
Total Submissions:322.6K


Companies Microsoft Facebook
Related Topics Linked List
Similar Questions 
                
                  
                    Swap Nodes in Pairs
*/
