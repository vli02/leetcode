/*
219. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

typedef struct {
    int val;
    int idx;
} e_t;
int cmp(void const *a, void const *b) {
    return ((const e_t *)a)->val < ((const e_t *)b)->val ? -1 :
           ((const e_t *)a)->val > ((const e_t *)b)->val ?  1 :
           ((const e_t *)a)->idx < ((const e_t *)b)->idx ? -1 : 1;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    e_t *p;
    int i, f;
    
    p = malloc(numsSize * sizeof(e_t));
    //assert(p);
    for (i = 0; i < numsSize; i ++) {
        p[i].val = nums[i];
        p[i].idx = i;
    }
    
    qsort(p, numsSize, sizeof(e_t), cmp);
    
    f = 0;
    for (i = 1; !f && i < numsSize; i ++) {
        if (p[i].val == p[i - 1].val &&
            p[i].idx - p[i - 1].idx <= k) f = 1;
    }
    
    free(p);
    
    return f;
}


/*
Difficulty:Easy
Total Accepted:116.5K
Total Submissions:360K


Companies Palantir Airbnb
Related Topics Array Hash Table
Similar Questions 
                
                  
                    Contains Duplicate
                  
                    Contains Duplicate III
*/
