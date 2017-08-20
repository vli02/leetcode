/*
281. Zigzag Iterator

Given two 1d vectors, implement an iterator to return their elements alternately.


For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6]



By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].



Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?


Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
[1,2,3]
[4,5,6,7]
[8,9]

It should return [1,4,8,2,5,9,3,6,7].
*/

struct ZigzagIterator {
    int sz;
    int *p;
    int pos;
};
​
struct ZigzagIterator *zigzagIteratorCreate(int* v1, int v1Size, int* v2, int v2Size) {
    struct ZigzagIterator *iter;
    int *p;
    int sz, i, j;
    
    sz = v1Size + v2Size;
    p = malloc(sz * sizeof(int));
    iter = malloc(sizeof(struct ZigzagIterator));
    //assert(p && iter);
    
    i = j = 0;
    while (i < v1Size || j < v2Size) {
        if (i < v1Size) {
            p[i + j] = v1[i];
            i ++;
        }
        if (j < v2Size) {
            p[i + j] = v2[j];
            j ++;
        }
    }
    
    iter->sz = sz;
    iter->p = p;
    iter->pos = 0;
    
    return iter;
}
​
bool zigzagIteratorHasNext(struct ZigzagIterator *iter) {
    return iter->pos < iter->sz ? true : false;
}
​
int zigzagIteratorNext(struct ZigzagIterator *iter) {
    return iter->p[iter->pos ++];
}
​
/** Deallocates memory previously allocated for the iterator */
void zigzagIteratorFree(struct ZigzagIterator *iter) {
    free(iter->p);
    free(iter);
}
​
/**
 * Your ZigzagIterator will be called like this:
 * struct ZigzagIterator *i = zigzagIteratorCreate(v1, v1Size, v2, v2Size);
 * while (zigzagIteratorHasNext(i)) printf("%d\n", zigzagIteratorNext(i));
 * zigzagIteratorFree(i);
 */


/*
Difficulty:Medium
Total Accepted:27.5K
Total Submissions:54.5K


Companies Google
Related Topics Design
Similar Questions 
                
                  
                    Binary Search Tree Iterator
                  
                    Flatten 2D Vector
                  
                    Peeking Iterator
                  
                    Flatten Nested List Iterator
*/
