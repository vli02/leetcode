/*
317. Shortest Distance from All Buildings

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.


For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

#define IDX(I, L, J) ((I) * (L) + J)
typedef struct {
    int x;
    int y;
} dot_t;
typedef struct {
    dot_t *q;
    int sz;
    int n;
} q_t;
void add2q(q_t *q, int x, int y) {
    if (q->sz == q->n) {
        q->sz *= 2;
        q->q = realloc(q->q, q->sz * sizeof(dot_t));
        //assert(q->q);
    }
    q->q[q->n].x = x;
    q->q[q->n].y = y;
    q->n ++;
}
void bfs(int **grid, int rowsz, int colsz, q_t *q1, q_t *q2, int *v, int *dist, int *n, int d) {
    const int offset[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int x, y, i, j, k;
    
    if (q1->n == 0) return;
    
    do {
        q1->n --;
        x = q1->q[q1->n].x;
        y = q1->q[q1->n].y;
        for (k = 0; k < 4; k ++) {
            i = x + offset[k][0];
            j = y + offset[k][1];
            if (i >= 0 && i < rowsz &&
                j >= 0 && j < colsz &&
                v[IDX(i, colsz, j)] == 0) {
                v[IDX(i, colsz, j)] = 1;
                if (grid[i][j] == 1) {
                    (*n) ++;
                    (*dist) += d;
                } else if (grid[i][j] == 0) {
                    add2q(q2, i, j);
                }
            }
        }
    } while (q1->n);
    
    bfs(grid, rowsz, colsz, q2, q1, v, dist, n, d + 1);
}
int shortestDistance(int** grid, int gridRowSize, int gridColSize) {
    q_t q1, q2;
    int num_of_buildings = 0;
    int *v;
    int min = -1;
    int i, j, n, dist;
    
    for (i = 0; i < gridRowSize; i ++) {
        for (j = 0; j < gridColSize; j ++) {
            num_of_buildings += (grid[i][j] == 1) ? 1 : 0;
        }
    }
    
    q1.n = q2.n = 0;
    q1.sz = q2.sz = 100;
    q1.q = malloc(q1.sz * sizeof(dot_t));
    q2.q = malloc(q2.sz * sizeof(dot_t));
    v = malloc(gridRowSize * gridColSize * sizeof(int));
    //assert(v && q1.q && q2.q);
    
    for (i = 0; i < gridRowSize; i ++) {
        for (j = 0; j < gridColSize; j ++) {
            if (grid[i][j] == 0) {
                n = dist = q1.n = q2.n = 0;         // reset
                memset(v, 0, gridRowSize * gridColSize * sizeof(int));
                v[IDX(i, gridColSize, j)] = 1;
                add2q(&q1, i, j);
                bfs(grid, gridRowSize, gridColSize, &q1, &q2, v, &dist, &n, 1);
                if (n == num_of_buildings && (min == -1 || min > dist)) min = dist;
            }
        }
    }
    
done:
    free(v);
    free(q1.q);
    free(q2.q);
    
    return min;
}


/*
Difficulty:Hard
Total Accepted:17.3K
Total Submissions:51K


Companies Google Zenefits
Related Topics Breadth-first Search
Similar Questions 
                
                  
                    Walls and Gates
                  
                    Best Meeting Point
*/
