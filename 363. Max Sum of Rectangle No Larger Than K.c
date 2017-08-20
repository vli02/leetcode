/*
363. Max Sum of Rectangle No Larger Than K

Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2



The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:

The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?



Credits:Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/

int lower_bound(int *set, int len, int x) {
    int i;
    for (i = 0; i < len; i ++) {
        if (set[i] >= x) break;  // first one not less than k
    }
    return i;
}
int maxSumSubmatrix(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    int *sum_on_row, sum, max;
    int *predecessor, len, i, j;
    int left, right, row;
    int *buff;
    
    buff = malloc((matrixRowSize * 2 + 1) * sizeof(int));
    //assert(buff);
    sum_on_row = &buff[0];
    predecessor = &buff[matrixRowSize];
    
    max = 0x80000000;
    for (left = 0; left < matrixColSize; left ++) {
        memset(sum_on_row, 0, matrixRowSize * sizeof(int));
        for (right = left; right < matrixColSize; right ++) {
            len = 0;
            predecessor[len ++] = 0;
            sum = 0;
            for (row = 0; row < matrixRowSize; row ++) {
                sum_on_row[row] += matrix[row][right];
                sum += sum_on_row[row];
                
                // find max sum no larger than k
                i = lower_bound(predecessor, len, sum - k);
                if (i < len) {
                    if (max < sum - predecessor[i]) {
                        max = sum - predecessor[i];
                    }
                }
                i = lower_bound(predecessor, len, sum);
                for (j = len; j > i; j --) {
                    predecessor[j] = predecessor[j - 1];
                }
                /*if (i < len) {
                    memcpy(&predecessor[i + 1], &predecessor[i], (len - i) * sizeof(int));
                }*/
                predecessor[i] = sum;
                len ++;
            }
        }
    }
    
    free(buff);
    
    return max;
}


/*
Difficulty:Hard
Total Accepted:14.5K
Total Submissions:43.7K


Companies Google
Related Topics Binary Search Dynamic Programming Queue

*/
