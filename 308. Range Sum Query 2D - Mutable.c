/*
308. Range Sum Query 2D - Mutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).



The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.


Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10



Note:

The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

typedef struct NumMatrix {
    // use a mutex for multiple threaded program since it is mutable.
    int rowsz;
    int colsz;
    int **matrix;
    int *stree;
} NumMatrix;
​
#define IDX(X, Y) ((X) * (p->colsz + 1) + (Y))
​
void update(NumMatrix *p, int i, int j, int diff) {
    int x, y;
    
    if (diff == 0) return;
    
    for (x = i; x <= p->rowsz; x += x & (-x)) {
        for (y = j; y <= p->colsz; y += y & (-y)) {
            p->stree[IDX(x, y)] += diff;
        }
    }
}
int sum(NumMatrix *p, int i, int j) {
    int x, y;
    int s = 0;
    
    for (x = i; x > 0; x -= x & (-x)) {
        for (y = j; y > 0; y -= y & (-y)) {
            s += p->stree[IDX(x, y)];
        }
    }
    
    return s;
}
/** Initialize your data structure here. */
struct NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    struct NumMatrix *p;
    int i, j;
    
    p = malloc(sizeof(struct NumMatrix));
    //assert(p);
    p->rowsz = matrixRowSize;
    p->colsz = matrixColSize;
    p->matrix = matrix;
    p->stree = calloc((p->rowsz + 1) * (p->colsz + 1), sizeof(int));
    //assert(p->stree);
    
    for (i = 0; i < p->rowsz; i ++) {
        for (j = 0; j < p->colsz; j ++) {
            update(p, i + 1, j + 1, matrix[i][j]);
        }
    }
    
    return p;
}
​
void numMatrixUpdate(struct NumMatrix* numMatrix, int row, int col, int val) {
    if (row < numMatrix->rowsz && col < numMatrix->colsz) {
        // lock
        update(numMatrix, row + 1, col + 1, val - numMatrix->matrix[row][col]);
        numMatrix->matrix[row][col] = val;
        // unlock
    }
}
​
int numMatrixSumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {
    int s;
    // lock
    s = sum(numMatrix, row2 + 1, col2 + 1) + sum(numMatrix, row1, col1) -
        sum(numMatrix, row1, col2 + 1) - sum(numMatrix, row2 + 1, col1);
    // unlock
    return s;
}
​
/** Deallocates memory previously allocated for the data structure. */
void numMatrixFree(struct NumMatrix* numMatrix) {
    free(numMatrix->stree);
    free(numMatrix);
}
​
// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// update(numMatrix, 1, 1, 10);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);


/*
Difficulty:Hard
Total Accepted:15.4K
Total Submissions:68.2K


Companies Google
Related Topics Binary Indexed Tree Segment Tree
Similar Questions 
                
                  
                    Range Sum Query 2D - Immutable
                  
                    Range Sum Query - Mutable
*/
