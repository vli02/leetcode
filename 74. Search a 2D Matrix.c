/*
74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:



Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.




For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]


Given target = 3, return true.
*/

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int s, x, z, y, mr, mc;
    int a, b, c;
    s = 0; x = matrixRowSize - 1;
    while (s <= x) {
        mr = s + (x - s) / 2;
        a = matrix[mr][0];
        b = matrix[mr][matrixColSize - 1];
        if (target >= a && target <= b) {
            z = 0; y = matrixColSize - 1;
            while (z <= y) {
                mc = z + (y - z) / 2;
                c = matrix[mr][mc];
                if (target == c) return true;
                if (target <  c) y = mc - 1;
                else             z = mc + 1;
            }
            return false;
        }
        if (target < a) x = mr - 1;
        else            s = mr + 1;
    }
    
    return false;
}


/*
Difficulty:Medium
Total Accepted:129.6K
Total Submissions:369.7K


Related Topics Array Binary Search
Similar Questions Search a 2D Matrix II

*/
