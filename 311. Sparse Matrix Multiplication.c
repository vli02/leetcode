/*
311. Sparse Matrix Multiplication

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** multiply(int** A, int ARowSize, int AColSize, int** B, int BRowSize, int BColSize) {
    int **result, *buff;
    int i, j, k;
    
    result = malloc(ARowSize * sizeof(int *));
    //assert(result);
    for (i = 0; i < ARowSize; i ++) {
        buff = calloc(BColSize, sizeof(int));
        //assert(buff);
        result[i] = buff;
        for (j = 0; j < AColSize; j ++) {
            if (A[i][j] != 0) {
                //printf("\nAij: %d\n", A[i][j]);
                for (k = 0; k < BColSize; k ++) {
                    //printf("Bjk: %d, ", B[j][k]);
                    buff[k] += A[i][j] * B[j][k];
                }
            }
        }
    }
    
    return result;
}


/*
Difficulty:Medium
Total Accepted:30.5K
Total Submissions:60.1K


Companies LinkedIn Facebook
Related Topics Hash Table

*/
