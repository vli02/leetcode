/*
325. Maximum Size Subarray Sum Equals k

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.



    Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.



    Example 1:


Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)



    Example 2:


Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)



    Follow Up:
    Can you do it in O(n) time?
*/

typedef struct e_s {
    int val;
    int idx;
    struct e_s *shadow;
} e_t;
​
#define SZ 10240
​
e_t *lookup(e_t **t, int val) {
    int k = val >= 0 ? val : -val;
    e_t *e = t[k % SZ];
    while (e && e->val != val) e = e->shadow;
    return e;
}
​
void put(e_t **t, int val, int idx) {
    int k = val >= 0 ? val : -val;
    e_t *p = malloc(sizeof(e_t));
    //assert(p);
    p->val = val;
    p->idx = idx;
    p->shadow = t[k % SZ];
    t[k % SZ] = p;
}
​
void free_t(e_t **t) {
    e_t *e, *s;
    int i;
    for (i = 0; i < SZ; i ++) {
        e = t[i];
        while (e) {
            s = e->shadow;
            free(e);
            e = s;
        }
    }
}
​
int maxSubArrayLen(int* nums, int numsSize, int k) {
    int i, s, d = 0;
    e_t *t[SZ] = { 0 }, *p;
    
    put(t, 0, -1);
    
    s = 0;
    for (i = 0; i < numsSize; i ++) {
        s += nums[i];           // current total
        p = lookup(t, s - k);   // test if there is a previous total which k = current - previous
        if (p && d < i - p->idx) {
            d = i - p->idx;
        }
        p = lookup(t, s);
        if (!p) put(t, s, i);   // don't override previous for getting max window size
    }                           // override if you want to get min window size
    
    free_t(t);
    
    return d;
}


/*
Difficulty:Medium
Total Accepted:31.6K
Total Submissions:74.7K


Companies Palantir Facebook
Related Topics Hash Table
Similar Questions 
                
                  
                    Minimum Size Subarray Sum
                  
                    Range Sum Query - Immutable
                  
                    Contiguous Array
*/
