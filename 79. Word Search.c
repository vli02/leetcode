/*
79. Word Search

Given a 2D board and a word, find if the word exists in the grid.


The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.



For example,
Given board = 
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]


word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

const int offset[][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
​
bool validate(int r, int c, int *visited, char **board, int rowsz, int colsz, char *word) {
    int i, j, k;
    
    if (board[r][c] != *word) return false;
    if (!*(word + 1)) return true;
    
    visited[r * colsz + c] = 1;
    
    for (k = 0; k < 4; k ++) {
        i = r + offset[k][0];
        j = c + offset[k][1];
        if (i >= 0 && i <= rowsz - 1 &&
            j >= 0 && j <= colsz - 1 &&
            !visited[i * colsz + j]) {
            if (validate(i, j, visited, board, rowsz, colsz, word + 1)) return true;    
        }
    }
​
    visited[r * colsz + c] = 0;
    
    return false;
}
bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int i, j, *visited;
    bool ret = false;
    
    visited = calloc(boardRowSize * boardColSize, sizeof(int));
    
    for (i = 0; !ret && i < boardRowSize; i ++) {
        for (j = 0; !ret && j < boardColSize; j ++) {
            if (validate(i, j, visited, board, boardRowSize, boardColSize, word)) ret = true;
        }
    }
​
    free(visited);
    return ret;
}


/*
Difficulty:Medium
Total Accepted:133.5K
Total Submissions:499.2K


Companies Microsoft Bloomberg Facebook
Related Topics Array Backtracking
Similar Questions 
                
                  
                    Word Search II
*/
