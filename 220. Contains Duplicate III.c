/*
220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
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
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    e_t *p;
    int i, j, d, f;
    
    p = malloc(numsSize * sizeof(e_t));
    //assert(p);
    for (i = 0; i < numsSize; i ++) {
        p[i].val = nums[i];
        p[i].idx = i;
    }
    
    qsort(p, numsSize, sizeof(e_t), cmp);
    
    f = 0;
    for (i = 0; !f && i < numsSize - 1; i ++) {
        //printf("\n%d: %d\n", p[i].idx, p[i].val);
        for (j = i + 1;
             !f &&
             j < numsSize &&
              ((p[i].val > 0 && p[j].val - p[i].val <= t) ||
                p[j].val <= t + p[i].val);
             j ++) {
            //printf("%d: %d\n", p[j].idx, p[j].val);
            d = p[j].idx - p[i].idx;
            if (d < 0) d = -d;
            if (d <= k) f = 1;
        }
    }
    
    free(p);
    
    return f;
}


/*
Difficulty:Medium
Total Accepted:55.6K
Total Submissions:291K


Companies Palantir Airbnb
Related Topics Binary Search Tree
Similar Questions 
                
                  
                    Contains Duplicate
                  
                    Contains Duplicate II
*/
