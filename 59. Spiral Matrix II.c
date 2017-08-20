/*
59. Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.


For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int left, right, top, bottom;
    int i, row, col;
    int op = 0;
    
    int **p;
    p = malloc(n * sizeof(int *)); // really no such a need to use multiple malloc!!!
    //assert(p);
    for (i = 0; i < n; i ++) {
        p[i] = malloc(n * sizeof(int));
        //assert(p[i]);
    }
    
    i = 1;
    left = 0; right = n;
    top = 0; bottom = n;
    
    while (left < right && top < bottom) {
        switch (op) {
            case 0:
                row = top; col = left;
                while (col < right) {
                    p[row][col] = i ++;
                    col ++;
                }
                top ++;
                break;
            case 1:
                row = top; col = right - 1;
                while (row < bottom) {
                    p[row][col] = i ++;
                    row ++;
                }
                right --;
                break;
            case 2:
                row = bottom - 1; col = right - 1;
                while (col >= left) {
                    p[row][col] = i ++;
                    col --;
                }
                bottom --;
                break;
            case 3:
                row = bottom - 1; col = left;
                while (row >= top) {
                    p[row][col] = i ++;
                    row --;
                }
                left ++;
                break;
        }
        op = (op + 1) % 4;
    }
​
    return p;
}


/*
Difficulty:Medium
Total Accepted:84.2K
Total Submissions:212.5K


Related Topics Array
Similar Questions Spiral Matrix

*/
