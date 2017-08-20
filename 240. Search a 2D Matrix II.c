/*
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:



Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.




For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]


Given target = 5, return true.
Given target = 20, return false.
*/

bool search(int** matrix, int top, int left, int bottom, int right, int target) {
    int row, col;
    int i;
​
    if (target < matrix[top][left] ||
        target > matrix[bottom][right]) return false;
​
    if (top == bottom) {
        // can use binary search
        for (i = left; i <= right; i ++) {
            if (matrix[top][i] == target) return true;
        }
        return false;
    }
    if (left == right) {
        // can use binary search
        for (i = top; i <= bottom; i ++) {
            if (matrix[i][left] == target) return true;
        }
        return false;
    }
​
    row = top + (bottom - top) / 2;
    col = left + (right - left) / 2;
    if (target == matrix[row][col]) return true;
    if (target <  matrix[row][col]) return (search(matrix, top, left, row, right, target) ||
                                            search(matrix, row + 1, left, bottom, col - 1, target));
    return (search(matrix, row + 1, left, bottom, right, target) ||
            search(matrix, top, col + 1, row, right, target));
}
​
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
#if 0  // 100+ ms
    return search(matrix, 0, 0, matrixRowSize - 1, matrixColSize - 1, target);
#else  // 40+ ms
    int r = 0;
    int c = matrixColSize - 1;
    while (r <= matrixRowSize - 1 &&
           c >= 0) {
        if (matrix[r][c] == target) return true;
        if (matrix[r][c] < target) r ++;
        else c --;
    }
    return false;
#endif
}


/*
Difficulty:Medium
Total Accepted:82K
Total Submissions:212.7K


Companies Amazon Google Apple
Related Topics Binary Search Divide and Conquer
Similar Questions 
                
                  
                    Search a 2D Matrix
*/
