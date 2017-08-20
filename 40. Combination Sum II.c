/*
40. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.


Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.




For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int **p;
    int *col;
    int sz;
    int n;
} res_t;
typedef struct {
    int *b;
    int sz;
} buff_t;
void add2buff(buff_t *buff, int d, int k) {
    if (buff->sz == 0) {
        buff->sz = 10;
        buff->b = malloc(buff->sz * sizeof(int));
        //assert(buff->b);
    } else if (buff->sz == d) {
        buff->sz *= 2;
        buff->b = realloc(buff->b, buff->sz * sizeof(int));
        //assert(buff->b);
    }
    buff->b[d] = k;
}
void add2res(res_t *res, int *b, int d) {
    int *tmp = malloc(d * sizeof(int));
    //assert(tmp);
    memcpy(tmp, b, d * sizeof(int));
    
    if (res->sz == 0) {
        res->sz = 10;
        res->p = malloc(res->sz * sizeof(int *));
        res->col = malloc(res->sz * sizeof(int));
        //assert(res->p && res->col);
    } else if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(int *));
        res->col = realloc(res->col, res->sz * sizeof(int));
        //assert(res->p && res->col);
    }
    res->p[res->n] = tmp;
    res->col[res->n] = d;
    res->n ++;
}
void bt(int *cand, int sz, int target, int start, int d, buff_t *buff, res_t *res) {
    int i;
    if (target < 0) return;  // no solution
    if (target == 0) {       // found it
        add2res(res, buff->b, d);
        return;
    }
    for (i = start; i < sz; i ++) {
        if (i > start && cand[i] == cand[i - 1]) continue;  // skip duplicated
        add2buff(buff, d, cand[i]);
        bt(cand, sz, target - cand[i], i + 1, d + 1, buff, res);
    }
}
int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x < y) ? -1 :
           (x > y) ?  1 : 0;
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    res_t res = { 0 };
    buff_t buff = { 0 };
    
    if (candidatesSize) {
        qsort(candidates, candidatesSize, sizeof(int), cmp);
        bt(candidates, candidatesSize, target, 0, 0, &buff, &res);
        if (buff.b) free(buff.b);
    }
    
    *returnSize = res.n;
    *columnSizes = res.col;
    return res.p;
}


/*
Difficulty:Medium
Total Accepted:120.7K
Total Submissions:358K


Companies Snapchat
Related Topics Array Backtracking
Similar Questions 
                
                  
                    Combination Sum
*/
