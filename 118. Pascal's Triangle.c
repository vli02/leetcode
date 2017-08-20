/*
118. Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.


For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int i, j;
    int *buff, **p;
    p = malloc(numRows * sizeof(int *));
    *columnSizes = malloc(numRows * sizeof(int));
    //assert(p && *columnSizes);
    for (i = 1; i <= numRows; i ++) {
        buff = malloc(i * sizeof(int));
        //assert(buff);
        p[i - 1] = buff;
        (*columnSizes)[i - 1] = i;
        buff[0] = 1;
        for (j = 1; j < i - 1; j ++) {
            buff[j] = p[i - 2][j - 1] + p[i - 2][j];
        }
        buff[i - 1] = 1;
    }
    return p;
}


/*
Difficulty:Easy
Total Accepted:137.9K
Total Submissions:357.7K


Companies Apple Twitter
Related Topics Array
Similar Questions 
                
                  
                    Pascal's Triangle II
*/
