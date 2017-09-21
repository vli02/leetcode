/*
23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *merge(struct ListNode *a, struct ListNode *b) {
    struct ListNode head, *prev, *c;
    prev = &head;
    while (a && b) {
        if (a->val < b->val) {
            c = a;
            a = a->next;
        } else {
            c = b;
            b = b->next;
        }
        prev->next = c;
        prev = c;
    }
    prev->next = a ? a : b;
    return head.next;
}
struct ListNode *divide_and_merge(struct ListNode **lists, int start, int end) {
    int mid;
    struct ListNode *a, *b;
    
    if (start == end) return lists[start];
    
    mid = start + (end - start) / 2;
    
    a = divide_and_merge(lists, start, mid);
    b = divide_and_merge(lists, mid + 1, end);
    
    return merge(a, b);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *head = NULL;

    if (listsSize == 0) return NULL;

#if 0  // 245ms
    int i;
    struct ListNode *a, *b;
    
    a = lists[0];
    for (i = 1; i < listsSize; i ++) {
        b = lists[i];
        a = merge(a, b);
    }
    head = a;
#else  // 9ms   O(NKlogK) N is average length of a list, K is number of lists
    head = divide_and_merge(lists, 0, listsSize - 1);
#endif
    return head;
}

/*
Difficulty:Hard
Total Accepted:159.5K
Total Submissions:586.7K


Companies LinkedIn Google Uber Airbnb Facebook Twitter Amazon Microsoft
Related Topics Divide and Conquer Linked List Heap
Similar Questions 
                
                  
                    Merge Two Sorted Lists
                  
                    Ugly Number II
*/
