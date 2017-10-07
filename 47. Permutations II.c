/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.



For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void bt(int **p, int *buff, int *v, int *nums, int sz, int l, int *n) {
    int i;
    
    if (l == sz) {
        p[*n] = malloc(sz * sizeof(int));
        //assert(p[k]);
        memcpy(p[*n], buff, sz * sizeof(int));
        (*n) ++;
        return;
    }
    for (i = 0; i < sz; i ++) {
        if (v[i] || (i > 0 && nums[i] == nums[i - 1] && !v[i - 1])) continue;
        v[i] = 1;
        buff[l] = nums[i];
        bt(p, buff, v, nums, sz, l + 1, n);
        v[i] = 0;
    }
}
int cmp(const void *a, const void *b) {
    int x = *(int *)a, y = *(int *)b;
    return x < y ? -1 :
           x > y ?  1 : 0;
}
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    int *buff, **p, *v;
    int i, n;
    n = 1;
    for (i = 2; i <= numsSize; i ++) {
        n = n * i;
    }
    p = malloc(n * sizeof(int *));
    v = calloc(numsSize, sizeof(int));
    buff = malloc(numsSize * sizeof(int));
    //assert(p && v && buff);
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    n = 0;
    bt(p, buff, v, nums, numsSize, 0, &n);
    *returnSize = n;
    
    free(buff); free(v);
    
    return p;
}

/*
Difficulty:Medium
Total Accepted:126.2K
Total Submissions:385K


Companies LinkedIn Microsoft
Related Topics Backtracking
Similar Questions 
                
                  
                    Next Permutation
                  
                    Permutations
                  
                    Palindrome Permutation II
*/
