/*
286. Walls and Gates

You are given a m x n 2D grid initialized with these three possible values.


-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.



Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.


For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF



After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

#define INF 2147483647
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
void bfs(q_t *q1, q_t *q2, int **rooms, int rowsz, int colsz, int d) {
    const int offset[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int x, y, i, j, k;
    
    if (!q1->n) return;
    
    do {
        q1->n --;
        x = q1->q[q1->n].x;
        y = q1->q[q1->n].y;
        for (k = 0; k < 4; k ++) {
            i = x + offset[k][0];
            j = y + offset[k][1];
            if (i >= 0 && i < rowsz &&
                j >= 0 && j < colsz &&
                rooms[i][j] == INF) {
                rooms[i][j] = d;
                add2q(q2, i, j);
            }
        }
    } while (q1->n);
    bfs(q2, q1, rooms, rowsz, colsz, d + 1);
}
void wallsAndGates(int** rooms, int roomsRowSize, int roomsColSize) {
    q_t q1, q2;
    int x, y;
    
    q1.n = q2.n = 0;
    q1.sz = q2.sz = 100;
    q1.q = malloc(q1.sz * sizeof(dot_t));
    q2.q = malloc(q2.sz * sizeof(dot_t));
    //assert(q1.q && q2.q);
    
    // start from gate and fan-out
    for (x = 0; x < roomsRowSize; x ++) {
        for (y = 0; y < roomsColSize; y ++) {
            if (rooms[x][y] == 0) {
                add2q(&q1, x, y);
            }
        }
    }
    bfs(&q1, &q2, rooms, roomsRowSize, roomsColSize, 1);
    
    free(q1.q);
    free(q2.q);
}


/*
Difficulty:Medium
Total Accepted:32.8K
Total Submissions:74.7K


Companies Google Facebook
Related Topics Breadth-first Search
Similar Questions 
                
                  
                    Surrounded Regions
                  
                    Number of Islands
                  
                    Shortest Distance from All Buildings
*/
