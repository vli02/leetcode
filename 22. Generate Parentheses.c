/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void bt(char ***p, int *sz, int *k, int n, char *buff, int l, int open, int close) {
    if (open == n && close == n) {
        if (*sz == *k) {
            (*sz) *= 2;
            *p = realloc(*p, (*sz) * sizeof(char *));
            //assert(*p);
        }
        (*p)[(*k) ++] = strdup(buff);
        return;
    }
    if (open < n) {
        buff[l] = '(';
        bt(p, sz, k, n, buff, l + 1, open + 1, close);
    }
    if (close < open) {
        buff[l] = ')';
        bt(p, sz, k, n, buff, l + 1, open, close + 1);
    }
}
char** generateParenthesis(int n, int* returnSize) {
#if 0
    char **p, *buff;
    int i, k, sz;
    
    sz = 100;
    p = malloc(sz * sizeof(char *));
    //assert(p);
    
    buff = malloc(n * 2 + 1);
    //assert(buff);
    buff[n * 2] = 0;
    
    k = 0;
    bt(&p, &sz, &k, n, buff, 0, 0, 0);
    
    *returnSize = k;
    
    free(buff);
#else  // Because of memory allocation/freeing, this is much slower than above!!!
    int *sz, *nn;
    char ***pp, **p, **p1, **p2, *buff;
    int i, j, a, b, x, y, l, k, h;
    
    buff = calloc(n * 2 + 1, sizeof(char));
    //assert(buff);
​
    sz = calloc(n + 1, sizeof(int));
    nn = calloc(n + 1, sizeof(int));
    pp = malloc((n + 1) * sizeof(char **));
    //assert(sz && nn && pp);
    
    sz[0] = 1;
    pp[0] = calloc(sz[0], sizeof(char *));
    pp[0][nn[0] ++] = strdup(buff);
​
    for (i = 1; i <= n; i ++) {     // f(n) = '('f(0)')'f(n-1), '('f(1)')'f(n-2), ...'('f(n-1)')'f(0)
        for (j = 0; j < i; j ++) {
            a = nn[j];
            p1 = pp[j];
            
            b = nn[i - j - 1];
            p2 = pp[i - j - 1];
            
            l = 0;
            buff[l ++] = '(';
            for (x = 0; x < a; x ++) {
                k = l + sprintf(&buff[l], "%s", p1[x]);
                buff[k ++] = ')';
                for (y = 0; y < b; y ++) {
                    h = k + sprintf(&buff[k], "%s", p2[y]);
                    buff[h] = 0;
                    if (sz[i] == 0) {
                        sz[i] = 10;
                        pp[i] = malloc(sz[i] * sizeof(char *));
                        //assert(pp[i]);
                    } else if (nn[i] == sz[i]) {
                        sz[i] *= 2;
                        pp[i] = realloc(pp[i], sz[i] * sizeof(char *));
                        //assert(pp[i]);
                    }
                    pp[i][nn[i] ++] = strdup(buff);
                }
            }
        }
    }
    k = nn[n];
    *returnSize = k;
    p = malloc(k * sizeof(char *));
    memcpy(p, pp[n], k * sizeof(char *));
    
    for (i = 0; i <= n; i ++) {
        free(pp[i]);
    }
    free(sz); free(nn); free(pp);
#endif
​
    return p;
}


/*
Difficulty:Medium
Total Accepted:157.4K
Total Submissions:349.7K


Companies Google Uber Zenefits
Related Topics Backtracking String
Similar Questions 
                
                  
                    Letter Combinations of a Phone Number
                  
                    Valid Parentheses
*/
