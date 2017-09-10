/*
329. Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.


From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).


Example 1:
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]




Return 4

The longest increasing path is [1, 2, 6, 9].


Example 2:
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]




Return 4

The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

#define IDX(I, J, L) ((I) * (L) + (J))
int depth(int **matrix, int rowsz, int colsz, int *dep, int row, int col) {
    int s, x, z, y;
    int d = 0;
    
    d = dep[IDX(row, col, colsz)];
    if (d) {
        return d;
    }
    
    if (row == 0 || matrix[row][col] <= matrix[row - 1][col]) {
        s = 1;
    } else {
        s = depth(matrix, rowsz, colsz, dep, row - 1, col) + 1;
    }
    
    if (row == rowsz - 1 || matrix[row][col] <= matrix[row + 1][col]) {
        x = 1;
    } else {
        x = depth(matrix, rowsz, colsz, dep, row + 1, col) + 1;
    }
    
    if (col == 0 || matrix[row][col] <= matrix[row][col - 1]) {
        z = 1;
    } else {
        z = depth(matrix, rowsz, colsz, dep, row, col - 1) + 1;
    }
    
    if (col == colsz - 1 || matrix[row][col] <= matrix[row][col + 1]) {
        y = 1;
    } else {
        y = depth(matrix, rowsz, colsz, dep, row, col + 1) + 1;
    }
    
    d = s;
    d = d > x ? d : x;
    d = d > z ? d : z;
    d = d > y ? d : y;
    dep[IDX(row, col, colsz)] = d;
    
    return d;
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j;
    int *dep;
    int d, max = 0;
    
    if (matrixRowSize <= 0 || matrixColSize <= 0) return 0;
    
    dep = calloc(matrixRowSize * matrixColSize, sizeof(int));
    //assert(dep);
    
    for (i = 0; i < matrixRowSize; i ++) {
        for (j = 0; j < matrixColSize; j ++) {
            d = depth(matrix, matrixRowSize, matrixColSize, dep, i, j);
            max = max < d ? d : max;
        }
    }
    
    free(dep);

    return max;
}

/*
Difficulty:Hard
Total Accepted:38.2K
Total Submissions:105K


Companies Google
Related Topics Depth-first Search Topological Sort Memoization

*/
