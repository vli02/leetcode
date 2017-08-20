/*
378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.


Note that it is the kth smallest element in the sorted order, not the kth distinct element.


Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.



Note: 
You may assume k is always valid, 1 ? k ? n2.
*/

int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    int kth;
    int i, j, l, r, c, *last_row;
    
    last_row = malloc(matrixColSize * sizeof(int));
    //assert(last_row);
    memset(last_row, -1, matrixColSize * sizeof(int));
    
    r = c = 0;
    kth = matrix[r][c];
    last_row[c] = r;
    
    while (-- k) {
        r = matrixRowSize - 1; c = matrixColSize - 1;
        kth = matrix[r][c];  // the biggest value
        l = 0;  // line was previous tested
        i = 1;  // line to be tested
        for (j = 0; j < matrixColSize && i != 0; j ++) {
            // for every column, look at the next row of the one was already taken
            i = last_row[j] + 1;
            if (i < matrixRowSize && i != l && kth > matrix[i][j]) {
                kth = matrix[i][j];
                r = i; c = j;
            }
            l = i;
        }
        last_row[c] = r;  // mark this one being taken
    }
    
    free(last_row);
    
    return kth;
}


/*
Difficulty:Medium
Total Accepted:40.4K
Total Submissions:90.6K


Companies Google Twitter
Related Topics Binary Search Heap
Similar Questions 
                
                  
                    Find K Pairs with Smallest Sums
*/
