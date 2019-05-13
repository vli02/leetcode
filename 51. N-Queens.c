/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define IDX(I, J, SZ) ((I) * (SZ) + J)

void set_flags(int *buff, int i, int j, int n, int flag) {
    int k, x, y;
    
    buff[IDX(i, j, n)] = flag;
    
    for (k = 0; k < n; k ++) {  // row
        if (k != j && buff[IDX(i, k, n)] != -1) {
            buff[IDX(i, k, n)] += flag ? 1 : -1;
        }
    }
    for (k = 0; k < n; k ++) {  // col
        if (k != i && buff[IDX(k, j, n)] != -1) {
            buff[IDX(k, j, n)] += flag ? 1 : -1;
        }
        x = k;
        y = j - i + k;
        if (y >= 0 && y < n) {
            if (x != i && y != j && buff[IDX(x, y, n)] != -1) {
                buff[IDX(x, y, n)] += flag ? 1 : -1;
            }
        }
        y = j + i - k;
        if (y >= 0 && y < n) {
            if (x != i && y != j && buff[IDX(x, y, n)] != -1) {
                buff[IDX(x, y, n)] += flag ? 1 : -1;
            }
        }
    }
}
void bt(int n, char ****pp, int *psz, int *pn, int *buff, int row) {
    int i, j, col, k;
    if (row == n) {
        // all done
        if (*psz == *pn) {
            *psz *= 2;
            (*pp) = realloc(*pp, *psz * sizeof(char **));
            //assert(*pp);
        }
        (*pp)[*pn] = malloc(n * sizeof(char *));
        for (i = 0; i < n; i ++) {
            (*pp)[*pn][i] = malloc((n + 1) * sizeof(char));
            //assert((*pp)[*pn][i]);
            for (j = 0; j < n; j ++) {
                (*pp)[*pn][i][j] = buff[IDX(i, j, n)] == -1 ? 'Q' : '.';
            }
            (*pp)[*pn][i][j] = 0;
        }
        (*pn) ++;
        return;
    }
    for (col = 0; col < n; col ++) {
        if (buff[IDX(row, col, n)] == 0) {
            set_flags(buff, row, col, n, -1);
            bt(n, pp, psz, pn, buff, row + 1);
            set_flags(buff, row, col, n, 0);
        }
    }
}
char*** solveNQueens(int n, int* returnSize) {
    char ***p;
    int *buff;
    int psz;
    
    psz = 10;
    p = malloc(psz * sizeof(char **));
    buff = calloc(n * n, sizeof(int));
    //assert(result && buff);
    
    *returnSize = 0;
    bt(n, &p, &psz, returnSize, buff, 0);
    
    free(buff);
    
    if (!*returnSize) {
        free(p);
        p = NULL;
    }
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:82.6K
Total Submissions:266.2K


Related Topics Backtracking
Similar Questions N-Queens II

*/
