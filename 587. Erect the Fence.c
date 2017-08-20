/*
587. Erect the Fence

There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:




Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 



 Note: 

All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100. 
The garden has at least one tree. 
All coordinates are distinct. 
Input points have NO order. No order required for output.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 * }
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    struct Point *p;
    struct Point *base;
} pa_t;
int pacmp(struct Point *p1, struct Point *p2, struct Point *p0) {
    int k;
    k = (p1->y - p0->y) * (p2->x - p0->x) -
        (p1->x - p0->x) * (p2->y - p0->y);   // delta of polar angle
    return k;
}
int cmp(const void *a, const void *b) {
    struct Point *p1 = ((pa_t *)a)->p;
    struct Point *p2 = ((pa_t *)b)->p;
    struct Point *p0 = ((pa_t *)a)->base;
    int k = pacmp(p1, p2, p0);
    if (k == 0) {
        k = (p1->x - p0->x) * (p1->x - p0->x) +
            (p1->y - p0->y) * (p1->y - p0->y) -
            (p2->x - p0->x) * (p2->x - p0->x) -
            (p2->y - p0->y) * (p2->y - p0->y);  // delta of distance
    }
    return k;
}
​
#define PUSH(P) do { \
    if (psz == pn) { \
        psz *= 2; \
        stack = realloc(stack, psz * sizeof(struct Point)); \
        /*assert(stack);*/ \
    } \
    stack[pn ++] = *(P); \
} while (0)
​
#define POP() do { \
    -- pn; \
} while (0)
​
#define TOP() &stack[pn - 1]
​
#define TOPTOP() &stack[pn - 2]
​
struct Point* outerTrees(struct Point* points, int pointsSize, int* returnSize) {
    int i, j, k;
    struct Point swap, *base, *p, *q, *stack;
    pa_t *pas;
    int psz, pn;
    
    if (pointsSize <= 3) {
        *returnSize = pointsSize;
        return points;
    }
    
    // graham's scan
    // 1. find bottom-left as base
    base = &points[0];
    for (i = 1; i < pointsSize; i ++) {
        p = &points[i];
        if (p->y < base -> y ||
            (p->y == base->y && p->x < base->x)) {
            base = p;
        }
    }
    swap = points[0];   // put bottom-left to the head of the array
    points[0] = *base;
    *base = swap;
    
    // 2. polar angle sorting
    pas = malloc((pointsSize - 1) * sizeof(pa_t));
    //assert(pas);
    base = &points[0];
    for (i = 0; i < pointsSize - 1; i ++) {
        p = &points[i + 1];
        pas[i].p = p;
        pas[i].base = base;
    }
    qsort(pas, pointsSize - 1, sizeof(pa_t), cmp);
    
    // 3. scan
    psz = 100;
    stack = malloc(psz * sizeof(struct Point));
    //assert(stack);
    pn = 0;
    
    PUSH(base);
    PUSH(pas[0].p);
    PUSH(pas[1].p);
    for (i = 2; i < pointsSize - 1; i ++) {
        p = pas[i].p;
        while (pn > 1 && pacmp(p, TOP(), TOPTOP()) < 0) POP();
        PUSH(p);
    }
    
    // add those which has the same polar angle and smaller distance to base
    q = TOP();
    for (i = pointsSize - 2; i >= 0; i --) {
        p = pas[i].p;
        if (p->x == q->x && p->y == q->y) continue;
        if (!pacmp(p, q, base)) PUSH(p);
        else break;
    }
    
    free(pas);
    
    *returnSize = pn;
    return stack;
}


/*
Difficulty:Hard
Total Accepted:2.1K
Total Submissions:6.7K


Companies Google
Related Topics Geometry

*/
