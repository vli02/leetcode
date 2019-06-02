/*
986. Interval List Intersections

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)


 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.


 

Note:


	0 <= A.length < 1000
	0 <= B.length < 1000
	0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9


NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int **p;
    int *c;
    int n;
    int sz;
} res_t;
void add2res(res_t *res, int x, int y) {
    int *buff = malloc(2 * sizeof(int));
    //assert(buff);
    buff[0] = x; buff[1] = y;
    if (res->sz == res->n) {
        if (res->sz == 0) res->sz = 10;
        else res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(int *));
        res->c = realloc(res->c, res->sz * sizeof(int));
        //assert(res->p);
    }
    res->p[res->n] = buff;
    res->c[res->n ++] = 2;
}
int _min(int a, int b) {
    if (a < b) return a;
    return b;
}
int _max(int a, int b) {
    if (a > b) return a;
    return b;
}
int** intervalIntersection(int** A, int ASize, int* AColSize, int** B, int BSize, int* BColSize, int* returnSize, int** returnColumnSizes){
    res_t res = { 0 };
    int i, j, x, y;
    int *a, *b;
    i = 0, j = 0;
    while (i < ASize && j < BSize) {
        a = A[i]; b = B[j];
        x = _max(a[0], b[0]);
        y = _min(a[1], b[1]);
        
        if (x <= y) add2res(&res, x, y);
        
        if (a[1] > b[1]) j ++;
        else i ++;
    }
    
    *returnColumnSizes = res.c;
    *returnSize = res.n;
    
    return res.p;
}


/*
Difficulty:Medium


*/
