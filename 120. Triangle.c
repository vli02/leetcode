/*
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.


For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]



The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).



Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int *x;
    int i, j, k;
    
    if (triangleRowSize == 1) return triangle[0][0];
    
    x = malloc(triangleRowSize * sizeof(int));
    if (!x) return 0;
    
    for (i = triangleRowSize - 1; i >= 0 ; i --) {
        for (j = 0; j < triangleColSizes[i]; j ++) {
            if (i == triangleRowSize - 1) {
                k = 0;
            } else if (x[j] < x[j + 1]) {
                k = x[j];
            } else {
                k = x[j + 1];
            }
            k += triangle[i][j];
            x[j] = k;
        }
    }
    free(x);
    return k;
}


/*
Difficulty:Medium
Total Accepted:109.4K
Total Submissions:323.7K


Related Topics Array Dynamic Programming

*/
