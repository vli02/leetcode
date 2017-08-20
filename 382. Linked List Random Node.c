/*
382. Linked List Random Node

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?


Example:
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    int n;
    int sz;
    struct ListNode *p;
    struct ListNode *head;
    struct ListNode *table[100];  // 100 * 100 indexed list
} Solution;
​
/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution* solutionCreate(struct ListNode* head) {
    Solution *obj = calloc(1, sizeof(Solution));
    //assert(obj);
    obj->p = obj->head = head;
    return obj;
}
​
/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    unsigned int k, i;
    struct ListNode *p;
    
    k = random();
    if (!obj->sz) {
        while (k != 0 && obj->p) {
            if ( obj->n <= 99 * 100 &&
                (obj->n % 100) == 0) {
                obj->table[obj->n / 100] = obj->p;
            }
            obj->n ++;
            obj->p = obj->p->next;
            k --;
        }
        if (obj->p) {
            return obj->p->val;
        } else {
            obj->sz = obj->n;
        }
    }
    k = k % obj->sz;
    if (k < 99 * 100) {
        i = k / 100;
        p = obj->table[i];
        k = k % 100;
    } else {
        p = obj->table[99];
        k -= 99 * 100;
    }
    while (k != 0) {
        p = p->next;
        k --;
    }
    return p->val;
}
​
void solutionFree(Solution* obj) {
    free(obj);
}
​
/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 * solutionFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:28.9K
Total Submissions:61.7K


Companies Google
Related Topics Reservoir Sampling
Similar Questions 
                
                  
                    Random Pick Index
*/
