/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head, *p;
    
    p = &head;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    // chain remaining
    if (l1) p->next = l1;
    if (l2) p->next = l2;
    
    p = head.next;
    
    return p;
}


/*
Difficulty:Easy
Total Accepted:244K
Total Submissions:624.7K


Companies Amazon LinkedIn Apple Microsoft
Related Topics Linked List
Similar Questions 
                
                  
                    Merge k Sorted Lists
                  
                    Merge Sorted Array
                  
                    Sort List
                  
                    Shortest Word Distance II
*/
