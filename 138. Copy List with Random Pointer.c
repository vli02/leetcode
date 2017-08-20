/*
138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.



Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode **srcstack;
    struct RandomListNode **dststack;
    int *flagstack, found_cycle = 0;
    int i, sp = 1, sz = 100;
    struct RandomListNode *ret = NULL, *newnode, *newrandom, **prevp = NULL;
    struct RandomListNode *node = head, *random;
    
    srcstack = malloc(sz * sizeof(struct RandomListNode *));
    dststack = malloc(sz * sizeof(struct RandomListNode *));
    flagstack = malloc(sz * sizeof(int));
    //assert(srcstack && dststack && flagstack);
    srcstack[0] = dststack[0] = NULL;
    
    while (node) {
        i = 1;
        while (i < sp && srcstack[i] != node) {
            i ++;
        }
        if (i == sp) {
            newnode = malloc(sizeof(struct RandomListNode));
            //assert(newnode);
            newnode->label = node->label;
            newnode->next = NULL;
            newnode->random = NULL;
            if (sp == sz) {
                sz = sz * 2;
                srcstack = realloc(srcstack, sz * sizeof(struct RandomListNode *));
                dststack = realloc(dststack, sz * sizeof(struct RandomListNode *));
                flagstack = realloc(flagstack, sz * sizeof(int));
                //assert(srcstack && dststack && flagstack);
            }
            srcstack[sp] = node;
            dststack[sp] = newnode;
            flagstack[sp] = 1;
            sp ++;
        } else {
            newnode = dststack[i];
            found_cycle = flagstack[i];
            flagstack[i] = 1;
        }
​
        if (!ret) ret = newnode;
        
        if (prevp) *prevp = newnode;
        prevp = &newnode->next;
        
        //if (found_cycle) break;
​
        random = node->random;
        i = 0;
        while (i < sp && srcstack[i] != random) {
            i ++;
        }
        if (i == sp) {
            newrandom = malloc(sizeof(struct RandomListNode));
            //assert(newrandom);
            newrandom->label = random->label;
            newrandom->next = NULL;
            newrandom->random = NULL;
            if (sp == sz) {
                sz = sz * 2;
                srcstack = realloc(srcstack, sz * sizeof(struct RandomListNode *));
                dststack = realloc(dststack, sz * sizeof(struct RandomListNode *));
                flagstack = realloc(flagstack, sz * sizeof(int));
                //assert(srcstack && dststack && flagstack);
            }
            srcstack[sp] = random;
            dststack[sp] = newrandom;
            flagstack[sp] = 0;
            sp ++;
        } else {
            newrandom = dststack[i];
        }
        newnode->random = newrandom;
        
        node = node->next;
    }
    
    free(srcstack);
    free(dststack);
    
    return ret;
}


/*
Difficulty:Medium
Total Accepted:119.6K
Total Submissions:454.5K


Companies Amazon Microsoft Bloomberg Uber
Related Topics Hash Table Linked List
Similar Questions 
                
                  
                    Clone Graph
*/
