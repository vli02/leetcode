/*
407. Trapping Rain Water II

Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.


Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.


Example:
Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.





The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.




After the rain, water are trapped between the blocks. The total volume of water trapped is 4.
*/

#define DUMP(I, J, K, M, R, C) do { } while (0)
#if 0
int fill(int *ignored, int *visited, int k, int **map, int rowsz, int colsz, int i, int j, int *pm, int *px, int *py) {
    int s, x, z, y;
    int h, m, w;
​
    if (i == 0 || i == rowsz - 1 ||
        j == 0 || j == colsz - 1 ||
        ignored[i * colsz + j]) {
        return -1; // it leaks!
    }
    
    if (visited[i * colsz + j] == k) {
        return 0;
    }
    
    visited[i * colsz + j] = k;
    
    h = map[i][j];
    
    s = map[i - 1][j];            m = s;
    x = map[i + 1][j]; if (m > x) m = x;
    z = map[i][j - 1]; if (m > z) m = z;
    y = map[i][j + 1]; if (m > y) m = y;
    
    w = 0;
    
    if (m > h) {
        w = m - h; // multiple drops
        *px = i;
        *py = j;
    } else {
        if (w == 0 && m == s) {
            w = fill(ignored, visited, k, map, rowsz, colsz, i - 1, j, pm, px, py);
        }
        if (w == 0 && m == x) {
            w = fill(ignored, visited, k, map, rowsz, colsz, i + 1, j, pm, px, py);
        }
        if (w == 0 && m == z) {
            w = fill(ignored, visited, k, map, rowsz, colsz, i, j - 1, pm, px, py);
        }
        if (w == 0 && m == y) {
            w = fill(ignored, visited, k, map, rowsz, colsz, i, j + 1, pm, px, py);
        }
    }
    
done:
    if (w == -1) {
        ignored[i * colsz + j] = -1; // mark leak
    } else {
        if (w == 0 && *pm > h) {
            *pm = h;
            *px = i;
            *py = j;
        }
    }
    
    return w;
}
int trapRainWater(int** heightMap, int heightMapRowSize, int heightMapColSize) {
    int i, j, k;
    int x, y, m;
    int w, total;
    
    int *visited = calloc(heightMapRowSize * heightMapColSize, sizeof(int));
    int *ignored = calloc(heightMapRowSize * heightMapColSize, sizeof(int));
    //assert(visited && ignored);
​
DUMP(0, 0, 0, heightMap, heightMapRowSize, heightMapColSize);
    total = 0;
    
    k = 1;
    for (i = 1; i < heightMapRowSize - 1; i ++) {
        j = 1; 
        while (j < heightMapColSize - 1) {
            x = i; y = j;
            do {
                m = heightMap[x][y];
                w = fill(ignored, visited, k, heightMap, heightMapRowSize, heightMapColSize, x, y, &m, &x, &y);
                if (w >= 0) {
                    if (w == 0) {
                        w = 1;
                    }
                    heightMap[x][y] += w;
                    total += w;
DUMP(x, y, w, heightMap, heightMapRowSize, heightMapColSize);
                }
                k ++;
            } while (w != -1);
            j ++;
        }
    }
    
    free(visited);
    
    return total;
}
#else
#define IDX(X, Y) ((X) * colsz + (Y))
const int offset[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int get_weight(int *visited, int *buff, int **map, int x, int y, int rowsz, int colsz) {
    int i, j, k;
    int w;
    int base = -1;
​
    memset(visited,  0, rowsz * colsz * sizeof(int));
    memset(buff,    -1, rowsz * colsz * sizeof(int));
    
    while (x != 0 && x != rowsz - 1 &&
           y != 0 && y != colsz - 1) {
        
        visited[IDX(x, y)] = 1;
​
        for (k = 0; k < 4; k ++) {
            i = x + offset[k][0];
            j = y + offset[k][1];
            if (visited[IDX(i, j)]) continue;
            w = map[i][j];
            if (w < base) w = base; // propagate highest bar along the path
            buff[IDX(i, j)] = w;
        }
        
        // locate lowest bar in surrounding and rebase to the lowest
        base = -1;
        for (i = 0; i < rowsz; i ++) {
            for (j = 0; j < colsz; j ++) {
                w = buff[IDX(i, j)];
                if (w == -1 || visited[IDX(i, j)]) continue;
                if (base == -1 || base > w) {
                    base = w;  // lowest bar in surrounding so far
                    x = i;
                    y = j;
                }
            }
        }
    }
    
    return base;
}
typedef struct surr_s {
    int x;
    int y;
    int h;
    struct surr_s *left;
    struct surr_s *right;
    struct surr_s *dup;
} surr_t;
int cmp(const void *a, const void *b) {
    return (*(surr_t *)b).h - (*(surr_t *)a).h;
}
int get_weight2(int *visited, surr_t *surr, int **map, int x, int y, int rowsz, int colsz) {
    int low = -1, last = 0, this;
    int i, j, k;
    int w, base = 0;
​
    memset(visited,  0, rowsz * colsz * sizeof(int));
    
    while (x != 0 && x != rowsz - 1 &&
           y != 0 && y != colsz - 1) {
        
        visited[IDX(x, y)] |= 0x1;
        
        for (k = 0; k < 4; k ++) {
            i = x + offset[k][0];
            j = y + offset[k][1];
            if (visited[IDX(i, j)]) continue;
            visited[IDX(i, j)] |= 0x2;
            w = map[i][j];
            if (w < base) w = base; // propagate highest bar along the path
            if (low != -1) {
                this = low;
                low = -1;
            } else {
                this = last ++;
            }
            surr[this].x = i;
            surr[this].y = j;
            surr[this].h = w;
        }
        
        base = -1;
        for (i = 0; i < last; i ++) {
            if (visited[IDX(surr[i].x, surr[i].y)] & 0x1) continue;
            w = surr[i].h;
            if (base == -1 || base > w) {
                base = w;  // lowest bar in surrounding so far
                x = surr[i].x;
                y = surr[i].y;
                low = i;
            }
        }
        /*qsort(surr, last, sizeof(surr[0]), cmp);  // TLE 2!!!
        low = last - 1;
        if (surr[low].x == x &&
            surr[low].y == y) {
            low --; last --;
        }
        x = surr[low].x;
        y = surr[low].y;
        base = surr[low].h;*/
    }
    
    return base;
}
void insert(surr_t **pp, surr_t *node) {
    surr_t *p = *pp;
    if (!p) *pp = node;
    else if (p->h == node->h) { node->dup = p->dup; p->dup = node; }
    else if (p->h >  node->h) insert(&p->left, node);
    else                      insert(&p->right, node);
}
int get_weight3(int *visited, surr_t *surr, int **map, int x, int y, int rowsz, int colsz) {
    int i, j, k;
    int w, base = 0;
    surr_t *parent, *p, *node, *root = NULL;
    
    memset(visited,  0, rowsz * colsz * sizeof(int));
    
    while (x != 0 && x != rowsz - 1 &&
           y != 0 && y != colsz - 1) {
        
        visited[IDX(x, y)] |= 0x1;
        
        for (k = 0; k < 4; k ++) {
            i = x + offset[k][0];
            j = y + offset[k][1];
            if (visited[IDX(i, j)]) continue;
            visited[IDX(i, j)] |= 0x2;
            w = map[i][j];
            if (w < base) w = base; // propagate highest bar along the path
            node = &surr[IDX(i, j)];
            node->x = i;
            node->y = j;
            node->h = w;
            node->left = node->right = node->dup = NULL;
            insert(&root, node);        // still TLE!!! OMG
        }
        parent = NULL;
        node = root;
        while (node->left) {
            parent = node;
            node = node->left; // lowest bar in surrounding so far
        }
        if (node->dup) { // take node out of the tree
            p = node->dup;
            node->dup = p->dup;
            node = p;
        } else if (!parent) {
            root = node->right;
        } else {
            parent->left = node->right;
        }
        x = node->x;
        y = node->y;
        base = node->h;  // the lowest one in the surrounding
    }
    
    return base;
}
int trapRainWater(int** heightMap, int heightMapRowSize, int heightMapColSize) {
    int x, y;
    int *visited, *weight, *buff;
    int rowsz = heightMapRowSize;
    int colsz = heightMapColSize;
    int w, water = 0;
    
    surr_t *root, *link, *surr;
    
    visited = malloc(rowsz * colsz * sizeof(int));
    weight = malloc(rowsz * colsz * sizeof(int));
    buff = malloc(rowsz * colsz * sizeof(int));
    surr = malloc(rowsz * colsz * sizeof(surr[0]));
    //assert(visited && weight && buff && surr);
    
    memset(weight, -1, rowsz * colsz * sizeof(int));
​
    for (x = 1; x < rowsz - 1; x ++) {
        for (y = 1; y < colsz - 1; y ++) {
            //w = get_weight(visited, buff, heightMap, x, y, rowsz, colsz);
            //w = get_weight2(visited, surr, heightMap, x, y, rowsz, colsz);
            w = get_weight3(visited, surr, heightMap, x, y, rowsz, colsz);
            //printf("[%d, %d]: %d\n", x, y, w);
            if (w > heightMap[x][y]) {
                water += w - heightMap[x][y];
            }
        }
    }
    free(visited);
    free(weight);
    free(buff);
    free(surr);
    
    return water;
}
#endif


/*
Difficulty:Hard
Total Accepted:10.9K
Total Submissions:29.5K


Companies Google Twitter
Related Topics Breadth-first Search Heap
Similar Questions 
                
                  
                    Trapping Rain Water
*/
