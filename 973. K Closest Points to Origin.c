/*
973. K Closest Points to Origin

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 


Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].



Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


 

Note:


	1 <= K <= points.length <= 10000
	-10000 < points[i][0] < 10000
	-10000 < points[i][1] < 10000
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int i;
    int d;
} p_t;
int cmp(const void *a, const void *b) {
    const p_t *p1 = a;
    const p_t *p2 = b;
    if (p1->d < p2->d) return -1;
    else if (p1->d == p2->d) return 0;
    return 1;
}
void swap(void *a, void *b) {
    p_t *p1 = a;
    p_t *p2 = b;
    p_t t = *p1;
    *p1 = *p2;
    *p2 = t;
}
void hsort(void *p, int n, int l,
           int (*f)(const void *, const void *),
           void (*s)(void *, void *)) {
    int d;
    const void *t;
    
    if (n < 2) return;
    
    t = p;
    while (n -- > 1) {
        p += l;
        if (f(t, p) < 0) {
            t = p;
        }
    }
    
    if (t != p) {
        s(t, p);
    }
}
int** kClosest(int** points, int pointsRowSize, int *pointsColSizes, int K, int** columnSizes, int* returnSize) {
    p_t *a;
    int i, x, y, d;
    int **p, *col, *buff;
    
    a = malloc((K + 1) * sizeof(p_t));
    //assert(a);
    
    for (i = 0; i <= K && i < pointsRowSize; i ++) {
        x = points[i][0]; y = points[i][1];
        d = x * x + y * y;
        a[i].i = i;
        a[i].d = d;
    }
    if (i > K) {
        // TODO: optimize by using binary search tree for heap sort
        hsort(a, K + 1, sizeof(p_t), cmp, swap);
    }
    while (i < pointsRowSize) {
        x = points[i][0]; y = points[i][1];
        d = x * x + y * y;
        if (d < a[K].d) {   // replace the point on the top of the heap
            a[K].i = i;
            a[K].d = d;
            hsort(a, K + 1, sizeof(p_t), cmp, swap);
        }
        i ++;
    }
    
    buff = malloc(K * 2 * sizeof(int));
    p = malloc(K * sizeof(int *));
    col = malloc(K * sizeof(int));
    
    for (i = 0; i < K; i ++) {
        buff[i * 2    ] = points[a[i].i][0];
        buff[i * 2 + 1] = points[a[i].i][1];
        p[i] = &buff[i * 2];
        col[i] = 2;
    }
    
    *columnSizes = col;
    *returnSize = K;
    
    free(a);
    
    return p;
}


/*
Difficulty:Medium


*/
