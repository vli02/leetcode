/*
525. Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 


Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.



Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.



Note:
The length of the given binary array will not exceed 50,000.
*/

typedef struct elem_s {
    int n;
    int idx;
    struct elem_s *shadow;
} elem_t;
​
#define SZ 10240
​
void free_set(elem_t **set, int sz) {
    int i;
    elem_t *e, *s;
    for (i = 0; i < sz; i ++) {
        e = set[i];
        while (e) {
            s = e->shadow;
            free(e);
            e = s;
        }
    }
}
void put(elem_t **set, int n, int idx) {
    int k = n; //(n >= 0) ? n : -n;
    elem_t *e = malloc(sizeof(elem_t));
    e->n = n;
    e->idx = idx;
    e->shadow = set[k % SZ];
    set[k % SZ] = e;
}
elem_t *lookup(elem_t **set, int n) {
    int k = n; //(n >= 0) ? n : -n;
    elem_t *e = set[k % SZ];
    while (e && e->n != n) e = e->shadow;
    return e;
}
int findMaxLength(int* nums, int numsSize) {
    int n[2] = { 0 };
    int i, d = 0;
    elem_t *buff[SZ * 2] = { 0 };
    elem_t *e, *set = &buff[SZ];
    
    if (!numsSize) return 0;
    
    put(set, 0, -1);
    
    for (i = 0; i < numsSize; i ++) {
        n[nums[i]] ++;
        e = lookup(set, n[0] - n[1]);
        if (!e) {
            put(set, n[0] - n[1], i);
        } else if (d < i - e->idx) {
            d = i - e->idx;
        }
    }
    
    free_set(buff, sizeof(buff)/sizeof(buff[0]));
​
    return d;
}


/*
Difficulty:Medium
Total Accepted:12.3K
Total Submissions:31.5K


Companies Facebook
Related Topics Hash Table
Similar Questions 
                
                  
                    Maximum Size Subarray Sum Equals k
*/
