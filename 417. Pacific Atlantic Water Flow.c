/*
417. Pacific Atlantic Water Flow

Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.


Example:
Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int dfs(int *visited, int **matrix, int rowsz, int colsz, int x, int y, int ocean) {
    int a, b, c, d, o;
    int k;
    
    if ((ocean == 0 && (x == 0 || y == 0)) ||
        (ocean == 1 && (x == rowsz - 1 || y == colsz - 1))) {
        return 1;
    }
    
    visited[x * colsz + y] = 1;
    
    o = matrix[x][y];
    a = (x > 0 && visited[(x - 1) * colsz + y] == 0) ? matrix[x - 1][y] : o + 1;
    b = (x < rowsz - 1 && visited[(x + 1) * colsz + y] == 0) ? matrix[x + 1][y] : o + 1;
    c = (y > 0 && visited[x * colsz + (y - 1)] == 0) ? matrix[x][y - 1] : o + 1;
    d = (y < colsz - 1 && visited[x * colsz + (y + 1)] == 0) ? matrix[x][y + 1] : o + 1;
    
    k = 0;
    if (k == 0 && o >= a) {
        k = dfs(visited, matrix, rowsz, colsz, x - 1, y, ocean);
    }
    if (k == 0 && o >= b) {
        k = dfs(visited, matrix, rowsz, colsz, x + 1, y, ocean);
    }
    if (k == 0 && o >= c) {
        k = dfs(visited, matrix, rowsz, colsz, x, y - 1, ocean);
    }
    if (k == 0 && o >= d) {
        k = dfs(visited, matrix, rowsz, colsz, x, y + 1, ocean);
    }
    
    visited[x * colsz + y] = 0;
    
    return k;
}
int** pacificAtlantic(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize) {
    int *visited;
    int *buff;
    int **p;
    int i, j, n;
    
    *returnSize = 0;
    if (matrixRowSize == 0) return NULL;
    
    visited = calloc(matrixRowSize * matrixColSize, sizeof(int));
    buff = malloc(matrixRowSize * matrixColSize * 2 * sizeof(int));
    //assert(buff && visited);
    
    n = 0;
    for (i = 0; i < matrixRowSize; i ++) {
        for (j = 0; j < matrixColSize; j ++) {
            if (dfs(visited, matrix, matrixRowSize, matrixColSize, i, j, 0) &&
                dfs(visited, matrix, matrixRowSize, matrixColSize, i, j, 1)) {
                buff[n * 2 + 0] = i;
                buff[n * 2 + 1] = j;
                n ++;
            }
        }
    }
​
    free(visited);
    
    *columnSizes = malloc(n * sizeof(int));
    p = malloc(n * sizeof(int *));
    //assert(colbuff && p && *columnSizes);
    for (i = 0; i < n; i ++) {
        // every column is size 2, there is really no such a need to return this!!!
        (*columnSizes)[i] = 2;
        p[i] = &buff[i * 2];
    }
​
    *returnSize = n;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:16K
Total Submissions:47.6K


Companies Google
Related Topics Depth-first Search Breadth-first Search

*/
