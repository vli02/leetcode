/*
39. Combination Sum

Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 


The same repeated number may be chosen from C unlimited number of times.


Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.




For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void bt(int *cand, int candsz, int target, int start, int dep, int **stack, int *spsz, int ***result, int **col, int *sz, int *ret) {
    int i, j, *buff;
    for (i = start; i < candsz; i ++) {
        if (dep == *spsz) {
            *spsz = (*spsz) * 2;
            *stack = realloc(*stack, (*spsz) * sizeof(int));
            //assert(*stack);
        }
        (*stack)[dep] = cand[i];
        
        if (cand[i] < target) {
            bt(cand, candsz, target - cand[i], i, dep + 1, stack, spsz, result, col, sz, ret);
        } else if (cand[i] == target) {
            // found it
            buff = malloc((dep + 1) * sizeof(int));
            //assert(buff);
            memcpy(buff, *stack, (dep + 1) * sizeof(int));
            if (*ret == *sz) {
                *sz = (*sz) * 2;
                *result = realloc(*result, (*sz) * sizeof(int *));
                *col = realloc(*col, (*sz) * sizeof(int));
                //assert(*result && *col);
            }
            (*result)[*ret] = buff;
            (*col)[*ret] = dep + 1;
            (*ret) += 1;
        }
    }
} 
​
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int **result;
    int sz = 100;
    int *stack, spsz = 10;
    
    result = malloc(sz * sizeof(int *));
    *columnSizes = malloc(sz * sizeof(int));
    stack = malloc(spsz * sizeof(int));
    //assert(result && *columnSizes && stacksz);
    
    *returnSize = 0;
    
    bt(candidates, candidatesSize, target, 0, 0, &stack, &spsz, &result, columnSizes, &sz, returnSize);
    
    if (*returnSize == 0) {
        free(result);
        free(*columnSizes);
        *columnSizes = NULL;
        result = NULL;
    }
    free(stack);
    
    return result;
}


/*
Difficulty:Medium
Total Accepted:168.2K
Total Submissions:435.2K


Companies Snapchat Uber
Related Topics Array Backtracking
Similar Questions 
                
                  
                    Letter Combinations of a Phone Number
                  
                    Combination Sum II
                  
                    Combinations
                  
                    Combination Sum III
                  
                    Factor Combinations
                  
                    Combination Sum IV
*/
