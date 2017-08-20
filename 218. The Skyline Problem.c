/*
218. The Skyline Problem

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).



    




    





The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ? Li, Ri ? INT_MAX, 0 < Hi ? INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

 The number of buildings in any input list is guaranteed to be in the range [0, 10000].
 The input list is already sorted in ascending order by the left x position Li. 
 The output list must be sorted by the x position. 
 There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]



Credits:Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int x;
    int h;
} dot_t;
int cmp(void const *a, void const *b) {
    /* 1. ascending on x.
       2. same on x, descending on height for left edge and
                     acesending on height for right edge.
                     * height of right edge are negative numbers, so
                       descending on height for both left and right edges.
    */
    return  ((dot_t *)a)->x < ((dot_t *)b)->x ? -1 :
            ((dot_t *)a)->x > ((dot_t *)b)->x ?  1 :
            ((dot_t *)b)->h < ((dot_t *)a)->h ? -1 : 1;
}
typedef struct {
    int **p;
    int sz;
    int n;
} res_t;
void add2res(res_t *res, int x, int h) {
    int *p = malloc(2 * sizeof(int));
    //assert(p);
    p[0] = x;
    p[1] = h;
    
    if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(int *));
        //assert(res->p);
    }
    res->p[res->n ++] = p;
}
typedef struct {
    int *p;
    int n;
    int max;
} heap_t;
void add2heap(heap_t *heap, int k) {
    heap->p[heap->n ++] = k;
    if (k > heap->max) heap->max = k;
}
void remove_heap(heap_t *heap, int k) {
    int i, j, m = 0;
    for (i = 0; i < heap->n; i ++) {
        if (heap->p[i] == k) {
            heap->p[i] = heap->p[-- heap->n];
            if (heap->max == k) {
                for (j = i; j < heap->n; j ++) {
                    if (m < heap->p[j]) m = heap->p[j];
                }
                heap->max = m;
            }
            return;
        }
        if (m < heap->p[i]) m = heap->p[i];
    }
}
int heap_max(heap_t *heap) {
    return heap->max;
}
int** getSkyline(int** buildings, int buildingsRowSize, int buildingsColSize, int* returnSize) {
    dot_t *dots, *p;
    res_t res;
    heap_t heap;
    int x1, x2, h, prev;
    int n, i;
    
    n = buildingsRowSize * 2;
    dots = malloc(n * sizeof(dot_t));
    //assert(dots);
    
    res.sz = 100;
    res.n = 0;
    res.p = malloc(res.sz * sizeof(int *));
    //assert(res.p);
    
    heap.n = 0;
    heap.p = malloc((buildingsRowSize + 1) * sizeof(int));
    //assert(heap.p);
    
    // split all buildings to left and right dots
    for (i = 0; i < buildingsRowSize; i ++) {
        x1 = buildings[i][0];
        x2 = buildings[i][1];
        h  = buildings[i][2];
        
        p = &dots[i * 2 + 0];
        p->x = x1;
        p->h = h;
​
        p = &dots[i * 2 + 1];
        p->x = x2;
        p->h = 0 - h;
    }
    
    qsort(dots, n, sizeof(dot_t), cmp);
    
    heap.max = 0;
    add2heap(&heap, 0);
    prev = 0;
    // for each dot...
    for (i = 0; i < n; i ++) {
        p = &dots[i];
        if (p->h > 0) {
            // add p->h to heap
            add2heap(&heap, p->h);
        } else {
            // remove p->h from heap
            remove_heap(&heap, 0 - p->h);
        }
        h = heap_max(&heap);
        if (prev != h) {
            // there is a change on height
            add2res(&res, p->x, h);
            prev = h;
        }
    }
    
    free(dots);
    free(heap.p);
    
    *returnSize = res.n;
    return res.p;
}


/*
Difficulty:Hard
Total Accepted:43.7K
Total Submissions:161K


Companies Microsoft Google Facebook Twitter Yelp
Related Topics Binary Indexed Tree Segment Tree Heap Divide and Conquer

*/
