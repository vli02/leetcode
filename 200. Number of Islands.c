/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110110101100000000
Answer: 1
Example 2:
11000110000010000011
Answer: 3

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

void cs(char **grid, int i, int j, int gridRowSize, int gridColSize) {
    int offset[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1, }, { 0, 1 } };
    int x, y, k;
    
    for (k = 0; k < 4; k ++) {
        x = i + offset[k][0];
        y = j + offset[k][1];
        if (x >= 0 && x < gridRowSize &&
            y >= 0 && y < gridColSize &&
            grid[x][y] == '1') {
            grid[x][y] = 0;
            cs(grid, x, y, gridRowSize, gridColSize);
        }
    }
}
​
int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int i, j;
    int n = 0;
    
    for (i = 0; i < gridRowSize; i ++) {
        for (j = 0; j < gridColSize; j ++) {
            if (grid[i][j] == '1') {
                cs(grid, i, j, gridRowSize, gridColSize);
                n ++;
            }
        }
    }
    return n;
}


/*
Difficulty:Medium
Total Accepted:115.7K
Total Submissions:335K


Companies Amazon Microsoft Google Facebook Zenefits
Related Topics Depth-first Search Breadth-first Search Union Find
Similar Questions 
                
                  
                    Surrounded Regions
                  
                    Walls and Gates
                  
                    Number of Islands II
                  
                    Number of Connected Components in an Undirected Graph
*/
