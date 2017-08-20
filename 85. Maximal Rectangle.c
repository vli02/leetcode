/*
85. Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 6.
*/

int _min(int a, int b) {
    return a < b ? a : b;
}
int _max(int a, int b) {
    return a > b ? a : b;
}
int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int *dp, *left, *right, *height;
    int i, j, l, r, k, m;
​
    dp = malloc(matrixColSize * 3 * sizeof(int));
    //assert(dp);
    left = &dp[0];
    right = &dp[matrixColSize];
    height = &dp[matrixColSize * 2];
    
    for (i = 0; i < matrixColSize; i ++) {
        left[i] = 0;
        right[i] = matrixColSize;
        height[i] = 0;
    }
    
    m = 0;
    for (i = 0; i < matrixRowSize; i ++) {
        l = 0;
        r = matrixColSize;
        for (j = matrixColSize - 1; j >= 0; j --) {
            if (matrix[i][j] == '1') {
                right[j] = _min(right[j], r);  // on this height, from right to left, min index of '1'
            } else {
                right[j] = matrixColSize;
                r = j;  // current row, from right to left, last one which is '0'
            }
        }
        for (j = 0; j < matrixColSize; j ++) {
            if (matrix[i][j] == '1') {
                height[j] ++;
                left[j] = _max(left[j], l);  // on this height, from left to right, max index of '1'
                
                k = (right[j] - left[j]) * height[j];
                m = m > k ? m : k;
            } else {
                height[j] = left[j] = 0;
                l = j + 1;  // current row, from left to right, first one which is '0'
            }
        }
        /*
        for (j = 0; j < matrixColSize; j ++) {
            printf("%d, ", right[j]);
        }
        printf("\n");
        for (j = 0; j < matrixColSize; j ++) {
            printf("%d, ", left[j]);
        }
        printf("\n");
        for (j = 0; j < matrixColSize; j ++) {
            printf("%d, ", height[j]);
        }
        printf("\n\n");
        */
    }
    
    free(dp);
    
    return m;
}


/*
Difficulty:Hard
Total Accepted:68.8K
Total Submissions:246.9K


Companies Facebook
Related Topics Array Hash Table Stack Dynamic Programming
Similar Questions 
                
                  
                    Largest Rectangle in Histogram
                  
                    Maximal Square
*/
