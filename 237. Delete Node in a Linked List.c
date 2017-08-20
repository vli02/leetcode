/*
237. Delete Node in a Linked List

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.



Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *p;
    
    if (!node || !node->next) return;
    
    p = node->next;
    *node = *p;
    free(p);
}


/*
Difficulty:Easy
Total Accepted:162.1K
Total Submissions:348.7K


Companies Adobe Apple Microsoft
Related Topics Linked List
Similar Questions 
                
                  
                    Remove Linked List Elements
*/
