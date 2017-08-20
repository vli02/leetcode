/*
361. Bomb Enemy

Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb. The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
 Note that you can only put the bomb at an empty cell. 

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)



Credits:Special thanks to @memoryless for adding this problem and creating all test cases.
*/

int count_E(char **grid, int i, int j, int rowsz, int colsz) {
    int k, n;
    n = 0;
    for (k = j - 1; k >= 0 && grid[i][k] != 'W'; k --) {
        if (grid[i][k] == 'E') {
            n ++;
        }
    }
    for (k = j + 1; k < colsz && grid[i][k] != 'W'; k ++) {
        if (grid[i][k] == 'E') {
            n ++;
        }
    }
    for (k = i - 1; k >= 0 && grid[k][j] != 'W'; k --) {
        if (grid[k][j] == 'E') {
            n ++;
        }
    }
    for (k = i + 1; k < rowsz && grid[k][j] != 'W'; k ++) {
        if (grid[k][j] == 'E') {
            n ++;
        }
    }
    return n;
}
int maxKilledEnemies(char** grid, int gridRowSize, int gridColSize) {
    int i, j, n, max;
    
    max = 0;
    
    for (i = 0; i < gridRowSize; i ++) {
        for (j = 0; j < gridColSize; j ++) {
            if (grid[i][j] == '0') {
                n = count_E(grid, i, j, gridRowSize, gridColSize);
                if (n > max) {
                    max = n;
                }
            }
        }
    }
    return max;
}


/*
Difficulty:Medium
Total Accepted:16.2K
Total Submissions:41.6K


Companies Google
Related Topics Dynamic Programming

*/
