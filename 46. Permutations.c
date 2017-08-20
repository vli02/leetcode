/*
46. Permutations

Given a collection of distinct numbers, return all possible permutations.



For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
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
        if (!v[i]) {
            v[i] = 1;
            buff[l] = nums[i];
            bt(p, buff, v, nums, sz, l + 1, n);
            v[i] = 0;
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize) {
    int *buff, **p, *v;
    int i, n;
    n = 1;
    for (i = 2; i <= numsSize; i ++) {
        n = n * i;
    }
    *returnSize = n;
    p = malloc(n * sizeof(int *));
    v = calloc(numsSize, sizeof(int));
    buff = malloc(numsSize * sizeof(int));
    //assert(p && v && buff);
    
    n = 0;
    bt(p, buff, v, nums, numsSize, 0, &n);
    
    free(buff); free(v);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:176.8K
Total Submissions:404.2K


Companies LinkedIn Microsoft
Related Topics Backtracking
Similar Questions 
                
                  
                    Next Permutation
                  
                    Permutations II
                  
                    Permutation Sequence
                  
                    Combinations
*/
