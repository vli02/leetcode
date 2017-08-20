/*
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Above is a 3 x 7 grid. How many possible unique paths are there?


Note: m and n will be at most 100.
*/

int uniquePaths(int m, int n) {
    int path[100][100];
    int i, j;
    i = 0;
    
    if (!m || !n) return 0;
    
    while (i < m) {
        j = 0;
        while (j < n) {
            if (i == 0 && j == 0) {
                path[i][j] = 1;
            } else if (i == 0 || j == 0) {
                path[i][j] = 1;
            } else {
                path[i][j] = path[i][j - 1] + path[i - 1][j];
            }
            j ++;
        }
        i ++;
    }
    return path[m - 1][n - 1];
}


/*
Difficulty:Medium
Total Accepted:147.3K
Total Submissions:358.4K


Companies Bloomberg
Related Topics Array Dynamic Programming
Similar Questions 
                
                  
                    Unique Paths II
                  
                    Minimum Path Sum
                  
                    Dungeon Game
*/
