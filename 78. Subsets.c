/*
78. Subsets

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.


For example,
If nums = [1,2,3], a solution is:


[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void bt(int *nums, int sz, int n, int start, int d, int **p, int *colsz, int *pn, int *buff) {
    int i;
    
    if (d == n) {  // done
        p[*pn] = malloc(d * sizeof(int));
        //assert(p[*pn]);
        memcpy(p[*pn], buff, d * sizeof(int));
        colsz[*pn] = d;
        (*pn) ++;
        return;
    }
    for (i = start; i < sz; i ++) {
        buff[d] = nums[i];
        bt(nums, sz, n, i + 1, d + 1, p, colsz, pn, buff);
    }
}
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int **p, psz, pn;
    int *buff, i;
    
    psz = 1 << numsSize;
    p = malloc(psz * sizeof(int *));
    *columnSizes = malloc(psz * sizeof(int));
    //assert(p && *columnSizes);
    
    buff = malloc(numsSize * sizeof(int));
    //assert(buff);
    
    pn = 0;
    p[pn] = NULL;
    *columnSizes[pn ++] = 0;
    for (i = 1; i <= numsSize; i ++) {
        bt(nums, numsSize, i, 0, 0, p, *columnSizes, &pn, buff);
    }
    
    free(buff);
​
    *returnSize = pn;
    return p;
}


/*
Difficulty:Medium
Total Accepted:173.7K
Total Submissions:428.5K


Companies Amazon Uber Facebook
Related Topics Array Backtracking Bit Manipulation
Similar Questions 
                
                  
                    Generalized Abbreviation
*/
