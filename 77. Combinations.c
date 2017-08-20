/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.


For example,
If n = 4 and k = 2, a solution is:


[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void bt(int *buff, int ***p, int *psz, int *pn, int n, int k, int d, int start) {
    int i;
    if (d == k) {
        // all done
        if (*psz == *pn) {
            *psz *= 2;
            *p = realloc(*p, *psz * sizeof(int *));
            //assert(*p);
        }
        (*p)[*pn] = malloc(k * sizeof(int));
        //assert((*p)[*pn]);
        memcpy((*p)[(*pn) ++], buff, k * sizeof(int));
        return;
    }
    for (i = start; i <= n; i ++) {
        buff[d] = i;
        bt(buff, p, psz, pn, n, k, d + 1, i + 1);
    }
}
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int **p, *buff;
    int psz, pn;
    
    pn = 0;
    psz = 10;
    p = malloc(psz * sizeof(int *));
    buff = malloc(k * sizeof(int));
    //assert(p && buff);
    
    bt(buff, &p, &psz, &pn, n, k, 0, 1);
    
    free(buff);
    
    *columnSizes = malloc(pn * sizeof(int));
    //assert(*columnSizes);
    
    *returnSize = pn;
    
    while (pn --) {
        (*columnSizes)[pn] = k;
    }
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:120.4K
Total Submissions:303.6K


Related Topics Backtracking
Similar Questions Combination Sum Permutations

*/
