/*
90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.


For example,
If nums = [1,2,2], a solution is:


[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int **p;
    int *csz;
    int psz;
    int pn;
} res_t;
void add2res(res_t *res, int *buff, int d) {
    if (d) {
        int *tmp = malloc(d * sizeof(int));
        //assert(tmp);
        memcpy(tmp, buff, d * sizeof(int));
        res->p[res->pn] = tmp;
    } else {
        res->p[res->pn] = NULL;
    }
    res->csz[res->pn ++] = d;
}
void bt(int *nums, int sz, int start, res_t *res, int *buff, int d) {
    int i;
    
    add2res(res, buff, d);
    
    for (i = start; i < sz; i ++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        buff[d] = nums[i];
        bt(nums, sz, i + 1, res, buff, d + 1);
    }
}
int cmp(const void *a, const void *b) {
    int x = *(int *)a, y = *(int *)b;
    return x < y ? -1 :
           x > y ?  1 : 0;
}
int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    res_t res = { 0 };
    int *buff, i;
    
    res.psz = 1 << numsSize;
    res.p = malloc(res.psz * sizeof(int *));
    res.csz = malloc(res.psz * sizeof(int));
    //assert(res.p && res.csz);
    
    buff = malloc(numsSize * sizeof(int));
    //assert(buff);
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    bt(nums, numsSize, 0, &res, buff, 0);
    
    free(buff);
    
    *columnSizes = res.csz;
    *returnSize = res.pn;
    
    return res.p;
}

/*
Difficulty:Medium
Total Accepted:116.2K
Total Submissions:321.2K


Companies Facebook
Related Topics Array Backtracking

*/
