/*
52. N-Queens II

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

#define IDX(I, J, SZ) ((I) * (SZ) + J)
​
void set_flags(int *buff, int i, int j, int n, int flag) {
    int k, x, y;
    
    buff[IDX(i, j, n)] = flag;
    
    for (k = 0; k < n; k ++) {  // row
        if (k != j && buff[IDX(i, k, n)] != -1) {
            buff[IDX(i, k, n)] += flag ? 1 : -1;
        }
    }
    for (k = 0; k < n; k ++) {  // col
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
void bt(int n, int *k, int *buff, int row) {
    int col;
    if (row == n) {
        // all done
        (*k) ++;
        return;
    }
    for (col = 0; col < n; col ++) {
        if (buff[IDX(row, col, n)] == 0) {
            set_flags(buff, row, col, n, -1);
            bt(n, k, buff, row + 1);
            set_flags(buff, row, col, n, 0);
        }
    }
}
int totalNQueens(int n) {
    int *buff, k = 0;
    
    buff = calloc(n * n, sizeof(int));
    //assert(result && buff);
    
    bt(n, &k, buff, 0);
    
    free(buff);
    
    return k;
}


/*
Difficulty:Hard
Total Accepted:64.8K
Total Submissions:144.4K


Companies Zenefits
Related Topics Backtracking
Similar Questions 
                
                  
                    N-Queens
*/
