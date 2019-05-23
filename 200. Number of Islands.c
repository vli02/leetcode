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

const int offset[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1, }, { 0, 1 } };
#if 0   // dfs
void cs(char **grid, int i, int j, int gridSize, int *gridColSize) {
    int x, y, k;

    grid[i][j] = 0;

    for (k = 0; k < 4; k ++) {
        x = i + offset[k][0];
        y = j + offset[k][1];
        if (x >= 0 && x < gridSize &&
            y >= 0 && y < gridColSize[x] &&
            grid[x][y] == '1') {
            cs(grid, x, y, gridSize, gridColSize);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int i, j;
    int n = 0;
    
    for (i = 0; i < gridSize; i ++) {
        for (j = 0; j < gridColSize[i]; j ++) {
            if (grid[i][j] == '1') {
                cs(grid, i, j, gridSize, gridColSize);
                n ++;
            }
        }
    }
    return n;
}
#else   // bfs
typedef struct {
    int *q;
    int left;
    int right;
} q_t;
void add2q(q_t *q, int x, int y) {
    q->q[q->right ++] = x;
    q->q[q->right ++] = y;
}
#define IDX(X, Y, M)  ((X) * (M) + (Y))
void bfs(q_t *qa, q_t *qb, int *v, char type, char **grid, int rowsz, int *colsz, int m, int *k) {
    int o, i, j, x, y;
    while (qa->left < qa->right) {
        i = qa->q[qa->left ++];
        j = qa->q[qa->left ++];
        for (o = 0; o < 4; o ++) {
            x = i + offset[o][0];
            y = j + offset[o][1];
            if (x < 0 || x >= rowsz ||
                y < 0 || y >= colsz[x] ||
                v[IDX(x, y, m)]) continue;
            v[IDX(x, y, m)] = 1;
            if (type == '0') {
                if (grid[x][y] == '0') add2q(qa, x, y);
                else {
                    add2q(qb, x, y);
                    bfs(qb, qa, v, '1', grid, rowsz, colsz, m, k);
                }
            } else {
                if (grid[x][y] == '0') add2q(qb, x, y);
                else add2q(qa, x, y);
            }
        }
    }
    if (type == '1') {
        (*k) ++;
        bfs(qb, qa, v, '0', grid, rowsz, colsz, m, k);
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    q_t q0 = { 0 }, q1 = { 0 };
    int *v, m, t, i, k;
    
    if (gridSize == 0) return 0;
    
    for (i = 0, m = 0, t = 0; i < gridSize; i ++) {
        k = gridColSize[i];
        if (m < k) m = k;
        t += k;
    }
    
    q0.q = malloc(t * 2 * sizeof(q0.q[0]));
    q1.q = malloc(t * 2 * sizeof(q1.q[0]));
    v = calloc(gridSize * m, sizeof(int));
    //assert(q0.q && q1.q && v);
    
    k = 0;
    v[IDX(0, 0, m)] = 1;
    if (grid[0][0] == '0') {
        add2q(&q0, 0, 0);
        bfs(&q0, &q1, v, '0', grid, gridSize, gridColSize, m, &k);
    } else {
        add2q(&q1, 0, 0);
        bfs(&q1, &q0, v, '1', grid, gridSize, gridColSize, m, &k);
    }
    
    free(q0.q);
    free(q1.q);
    free(v);
    
    return k;
}
#endif


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
