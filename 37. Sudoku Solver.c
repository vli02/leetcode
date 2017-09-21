/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.



A sudoku puzzle...




...and its solution numbers marked in red.
*/

#define IDX(I, J) ((I) / 3 * (boardColSize + 2) / 3 + (J) / 3)
​
int find_valid_bit(int b, int k) {
    while (k < 9 && (b & (1 << k))) {
        k ++;
    }
    return k;
}
​
int dfs(char **board, int boardRowSize, int boardColSize, int *bits_on_row, int *bits_on_col, int *bits_on_square) {
    int i, j, b, t, k;
    char c;
    
    for (i = 0; i < boardRowSize; i ++) {
        for (j = 0; j < boardColSize; j ++) {
            c = board[i][j];
            if (c != '.') continue;
            
            b = bits_on_row[i] |
                bits_on_col[j] |
                bits_on_square[IDX(i, j)];
            k = 0;
            while ((k = find_valid_bit(b, k)) < 9) {
                t = 1 << k;
                
                board[i][j] = '1' + k;
                bits_on_row[i] |= t;
                bits_on_col[j] |= t;
                bits_on_square[IDX(i, j)] |= t;
                
                if (dfs(board, boardRowSize, boardColSize, bits_on_row, bits_on_col, bits_on_square)) return 1;
                
                board[i][j] = '.';
                bits_on_row[i] &= ~t;
                bits_on_col[j] &= ~t;
                bits_on_square[IDX(i, j)] &= ~t;
                k ++;
            }
            
            return 0;
        }
    }
        
    return 1;
}
​
void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    int *buff, *bits_on_row, *bits_on_col, *bits_on_square;
    int i, j, b;
    char c;
    
    buff = calloc(boardRowSize +
                  boardColSize +
                  (boardRowSize + 2) / 3 * (boardColSize + 2) / 3, sizeof(int));
    //assert(buff);
    
    bits_on_row = &buff[0];
    bits_on_col = &buff[boardRowSize];
    bits_on_square = &buff[boardRowSize + boardColSize];
    
    for (i = 0; i < boardRowSize; i ++) {
        for (j = 0; j < boardColSize; j ++) {
            c = board[i][j];
            if (c == '.') continue;
            b = 1 << (c - '1');
            bits_on_row[i] |= b;
            bits_on_col[j] |= b;
            bits_on_square[IDX(i, j)] |= b;
        }
    }
    
    dfs(board, boardRowSize, boardColSize, bits_on_row, bits_on_col, bits_on_square);
    
    free(buff);
}


/*
Difficulty:Hard
Total Accepted:79.6K
Total Submissions:261.1K


Companies Uber Snapchat
Related Topics Hash Table Backtracking
Similar Questions 
                
                  
                    Valid Sudoku
*/
