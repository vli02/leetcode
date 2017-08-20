/*
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.



For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]


You should return [1,2,3,6,9,8,7,4,5].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int top, bottom, left, right, where;
    int i;
    int *p = (int *)malloc(matrixRowSize * matrixColSize * sizeof(int));
    if (!p) {
        return p;
    }
    
    i = 0;
    top = 0;
    left = 0;
    bottom = matrixRowSize;
    right = matrixColSize;
    
    while (i < matrixRowSize * matrixColSize) {
        if (top < bottom) {
            where = left;
            while (where < right) {         // on top, left -> right
                p[i++] = matrix[top][where];
                where ++;
            }
            top ++;
        }
        if (right > left) {
            where = top;
            while (where < bottom) {        // on right, top -> bottom
                p[i++] = matrix[where][right - 1];
                where ++;
            }
            right --;
        }
        if (bottom > top) {                 // on bottom, right -> left
            where = right;
            while (where > left) {
                p[i++] = matrix[bottom - 1][where - 1];
                where --;
            }
            bottom --;
        }
        if (left < right) {                 // on left, bottom -> top
            where = bottom;
            while (where > top) {
                p[i++] = matrix[where - 1][left];
                where --;
            }
            left ++;
        }
    }
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:106.2K
Total Submissions:409K


Companies Microsoft Google Uber
Related Topics Array
Similar Questions 
                
                  
                    Spiral Matrix II
*/
