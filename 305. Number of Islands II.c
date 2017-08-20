/*
305. Number of Islands II

A 2d grid map of m rows and n columns is initially filled with water.
We may perform an addLand operation which turns the water at position (row, col) into a land.
Given a list of positions to operate, count the number of islands after each addLand operation.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example:
Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0

Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0

Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0

We return the result as an array: [1, 1, 2, 3]

Challenge:
Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define IDX(I, L, J) ((I) * (L) + J)
void expand(int *land, int m, int n, int x, int y, int g) {
    const int offset[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int i, j, o, s;
​
    land[IDX(x, n, y)] = g;
    
    for (o = 0; o < 4; o ++) {
        i = x + offset[o][0];
        j = y + offset[o][1];
        if (i >= 0 && i < m &&
            j >= 0 && j < n) {
            s = land[IDX(i, n, j)];
            if (s != 0 && s != g) {
                expand(land, m, n, i, j, g);
            }
        }
    }
}
int fill_it(int k, int *s, int *land, int m, int n, int x, int y) {
    const int offset[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int i, j, o;
    int g;
    
    g = 0;
    for (o = 0; o < 4; o ++) {
        i = x + offset[o][0];
        j = y + offset[o][1];
        if (i >= 0 && i < m &&
            j >= 0 && j < n &&
            g < land[IDX(i, n, j)]) {
            g = land[IDX(i, n, j)];
        }
    }
    
    if (g == 0) { // all surrounding are water
        (*s) ++;
        k ++;
        land[IDX(x, n, y)] = *s;
    } else {
        land[IDX(x, n, y)] = g;
        for (o = 0; o < 4; o ++) {
            i = x + offset[o][0];
            j = y + offset[o][1];
            if (i >= 0 && i < m &&
                j >= 0 && j < n &&
                land[IDX(i, n, j)] &&
                land[IDX(i, n, j)] != g) {
                expand(land, m, n, i, j, g);
                k --;
            }
        }
    }
    
    return k;
}
​
int* numIslands2(int m, int n, int** positions, int positionsRowSize, int positionsColSize, int* returnSize) {
    int *land;
    int *p;
    int i, x, y;
    int k, s;
​
    land = calloc(m * n, sizeof(int));
    p = malloc(positionsRowSize * sizeof(int));
    //assert(land && p);
​
    k = s = 0;
    for (i = 0; i < positionsRowSize; i ++) {
        x = positions[i][0];
        y = positions[i][1];
        if (x < m && y < n && land[x * n + y] == 0) {
            k = fill_it(k, &s, land, m, n, x, y);
        }
        p[i] = k;
    }
    
    free(land);
    
    *returnSize = positionsRowSize;
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:23.5K
Total Submissions:60.3K


Companies Google
Related Topics Union Find
Similar Questions 
                
                  
                    Number of Islands
*/
