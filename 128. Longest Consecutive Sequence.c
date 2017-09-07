/*
128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.


For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.


Your algorithm should run in O(n) complexity.
*/

typedef struct e_s {
    int key;
    int len;
    struct e_s *shadow;
} e_t;

#define HSZ 1000

void put(e_t **htable, int key, int len) {
    e_t *e = malloc(sizeof(e_t));
    //assert(e);
    e->key = key;
    e->len = len;
    e->shadow = htable[key % HSZ];
    htable[key % HSZ] = e;
}

int lookup(e_t **htable, int key, int **lp) {
    e_t *e = htable[key % HSZ];
    // Runtime Error Message:
    // Line 20: member access within misaligned address 0x000001ea62f4 for type 'struct e_t', 
    // which requires 8 byte alignment
    while (e && e->key != key) {
        e = e->shadow;
    }
    if (e) {
        *lp = &e->len;
        return e->len;
    }
    return 0;
}

int longestConsecutive(int* nums, int numsSize) {
    int i, l, r, x, len = 0;
    e_t *htable[HSZ] = { 0 };
    int *llp, *rlp;
    
    // make a hash table to store the length of consecutive of current number
    // and update the length of consecutive of left and right boundary
    
    for (i = 0; i < numsSize; i ++) {
        if (lookup(htable, nums[i], &llp) == 0) {
            l = lookup(htable, nums[i] - 1, &llp);
            r = lookup(htable, nums[i] + 1, &rlp);
            x = l + r + 1;
            
            put(htable, nums[i], x);
            if (l) *llp = x;
            if (r) *rlp = x;
            
            if (len < x) len = x;
        }
    }
    
    // TODO: clean up memory
    
    return len;
}

/*
Difficulty:Hard
Total Accepted:109K
Total Submissions:296.1K


Companies Google Facebook
Related Topics Array Union Find
Similar Questions 
                
                  
                    Binary Tree Longest Consecutive Sequence
*/
