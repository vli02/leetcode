/*
36. Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.



A partially filled sudoku which is valid.


Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#define VERIFY_HASH(I, J) do { \
    c = board[I][J]; \
    if (c >= '1' && c <= '9') { \
        b = 1 << (c - '1'); \
        if (hash & b) return false; \
        hash |= b; \
    }\
} while (0)

#define IDX(I, J) ((I) / 3 * (boardColSize + 2) / 3 + (J) / 3)

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int hash;
    int i, j, m, n;
    char c;
    int b;
    
    int *hc, *hs, *buff;
    buff = calloc((boardColSize + ((boardRowSize + 2) / 3 * (boardColSize + 2) / 3)), sizeof(int));
    //assert(buff);
    hc = &buff[0];
    hs = &buff[boardColSize];
    
    for (i = 0; i < boardRowSize; i ++) {
        hash = 0;
        for (j = 0; j < boardColSize; j ++) {
            c = board[i][j];
            if (c < '1' || c > '9') continue;
            b = 1 << (c - '1');
            if ((hash & b) ||           // verify failed on current line
                (hc[j] & b) ||          // verify failed on current column
                (hs[IDX(i, j)] & b)) {  // failed on current nestled square
                free(buff);
                return false;
            }
            hash |= b;
            hc[j] |= b;
            hs[IDX(i, j)] |= b;
        }
    }
    free(buff);
    
    return true;
}

/*
Difficulty:Medium
Total Accepted:124.3K
Total Submissions:347.8K


Companies Snapchat Uber Apple
Related Topics Hash Table
Similar Questions 
                
                  
                    Sudoku Solver
*/
