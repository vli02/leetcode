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

int maxKilledEnemies(char** grid, int gridRowSize, int gridColSize) {
    int rowhit, *colhit;
    int i, j, k, m, n;
    
    colhit = calloc(gridColSize, sizeof(int));
    //assert(colhit);
    
    n = 0;
    
    for (i = 0; i < gridRowSize; i ++) {
        for (j = 0; j < gridColSize; j ++) {
            if (!j || grid[i][j - 1] == 'W') {
                rowhit = 0;
                for (k = j; k < gridColSize && grid[i][k] != 'W'; k ++) {
                    rowhit += (grid[i][k] == 'E') ? 1 : 0;
                }
            }
            if (!i || grid[i - 1][j] == 'W') {
                colhit[j] = 0;
                for (k = i; k < gridRowSize && grid[k][j] != 'W'; k ++) {
                    colhit[j] += (grid[k][j] == 'E') ? 1 : 0;
                }
            }
            if (grid[i][j] == '0') {
                n = rowhit + colhit[j];
                if (m < n) m = n;
            }
        }
    }
    
    free(colhit);
    
    return m;
}

/*
Difficulty:Medium
Total Accepted:16.2K
Total Submissions:41.6K


Companies Google
Related Topics Dynamic Programming

*/
