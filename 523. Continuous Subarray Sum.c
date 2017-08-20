/*
523. Continuous Subarray Sum

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.



Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.




Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.



Note:

The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/

typedef struct e_s {
    int mod;
    int idx;
    struct e_s *shadow;
} e_t;
#define SZ 1024
void free_t(e_t **set) {
    e_t *e, *s;
    int i;
    for (i = 0; i < SZ; i ++) {
        e = set[i];
        while (e) {
            s = e->shadow;
            free(e);
            e = s;
        }
    }
}
e_t *lookup(e_t **set, int mod) {
    e_t *e = set[mod % SZ];
    while (e && e->mod != mod) {
        e = e->shadow;
    }
    return e;
}
void put(e_t **set, int mod, int idx) {
    e_t *e = malloc(sizeof(e_t));
    //assert(e);
    e->mod = mod;
    e->idx = idx;
    e->shadow = set[mod % SZ];
    set[mod % SZ] = e;
}
bool checkSubarraySum(int* nums, int numsSize, int k) {
    int i, s, found = 0;
    e_t *set[SZ] = { 0 }, *e;
    
    put(set, 0, -1);
    
    s = 0;
    for (i = 0; i < numsSize; i ++) {
        s += nums[i];
        if (k) s = s % k;
        e = lookup(set, s);
        if (e) {
            if (i - e->idx >= 2) {
                found = 1;
                break;
            }
        } else {
            put(set, s, i);
        }
    }
    
done:
    free_t(set);
    
    return found;
}


/*
Difficulty:Medium
Total Accepted:16.3K
Total Submissions:71.8K


Companies Facebook
Related Topics Dynamic Programming Math
Similar Questions 
                
                  
                    Subarray Sum Equals K
*/
