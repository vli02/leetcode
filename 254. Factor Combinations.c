/*
254. Factor Combinations

Numbers can be regarded as product of its factors. For example,  
8 = 2 x 2 x 2;
  = 2 x 4.

Write a function that takes an integer n and return all possible combinations of its factors. 


Note: 

You may assume that n is always positive. 
Factors should be greater than 1 and less than n.



Examples: 
 input: 1
 output: 
[]

input: 37
 output: 
[]

 input: 12
 output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

 input: 32
 output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int *b;
    int sz;
} buff_t;
typedef struct {
    int **p;
    int *col;
    int sz;
    int n;
} res_t;
void add2buff(buff_t *buff, int d, int k) {
    if (buff->sz == d) {
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
    if(res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(int *));
        res->col = realloc(res->col, res->sz * sizeof(int));
        //assert(res->p && res->col);
    }
    res->p[res->n] = tmp;
    res->col[res->n] = d;
    res->n ++;
}
void dfs(int n, int d, int start, buff_t *buff, res_t *res) {
    int i, k;
    
    for (i = start; i <= sqrt(n); i ++) {
        if (!(n % i)) {
            add2buff(buff, d, i);
            k = n / i;
            dfs(k, d + 1, i, buff, res);
            add2buff(buff, d + 1, k);
            add2res(res, buff->b, d + 2);
        }
    }
}
int** getFactors(int n, int** columnSizes, int* returnSize) {
    int **result;
    int i, j, k, x, y;
    buff_t buff = { 0 };
    res_t res = { 0 };
    
    res.sz = 10;
    res.p = malloc(res.sz * sizeof(int *));
    res.col = malloc(res.sz * sizeof(int));
    //assert(res.p && res.col);
    
    buff.sz = 10;
    buff.b = malloc(buff.sz * sizeof(int));
    
    dfs(n, 0, 2, &buff, &res);
    
    free(buff.b);
    
    *returnSize = res.n;
    *columnSizes = res.col;
    
    return res.p;
}


/*
Difficulty:Medium
Total Accepted:27.4K
Total Submissions:64.5K


Companies LinkedIn Uber
Related Topics Backtracking
Similar Questions 
                
                  
                    Combination Sum
*/
