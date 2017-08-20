/*
221. Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.


Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*/

int test_square(char **matrix, int row, int col, int k) {
    int x;
    for (x = 0; x <= k; x ++) {
        if (matrix[row + x][col + k] == '0' ||
            matrix[row + k][col + x] == '0') return 0;
    }
    return 1;
}
int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int max = 0;
    int i, j, k;
    for (i = 0; i < matrixRowSize; i ++) {
        for (j = 0; j < matrixColSize; j ++) {
            k = 0;
            while (i + k < matrixRowSize &&
                   j + k < matrixColSize &&
                   test_square(matrix, i, j, k)) {
                k ++;
            }
            max = max < k ? k : max;
        }
    }
    return max * max;
}


/*
Difficulty:Medium
Total Accepted:65.3K
Total Submissions:226.4K


Companies Apple Airbnb Facebook
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Maximal Rectangle
*/
