/*
251. Flatten 2D Vector

Implement an iterator to flatten a 2d vector.


For example,
Given 2d vector = 
[
  [1,2],
  [3],
  [4,5,6]
]



By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].



Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

struct Vector2D {
    int rowsz;
    int *colsz;
    int **vec;
    int r;
    int c;
};
​
struct Vector2D *vector2DCreate(int** vec2d, int vec2dRowSize, int* vec2dColSizes) {
    struct Vector2D *iter = malloc(sizeof(struct Vector2D));
    //assert(iter);
    iter->rowsz = vec2dRowSize;
    iter->colsz = vec2dColSizes;
    iter->vec = vec2d;
    iter->r = iter->c = 0;
    return iter;
}
​
bool vector2DHasNext(struct Vector2D *iter) {
    while (iter->r < iter->rowsz) {
        if (iter->c < iter->colsz[iter->r]) return true;
        iter->r ++;
        iter->c = 0;
    }
    return false;
}
​
int vector2DNext(struct Vector2D *iter) {
    return iter->vec[iter->r][iter->c ++];
}
​
/** Deallocates memory previously allocated for the iterator */
void vector2DFree(struct Vector2D *iter) {
    free(iter);
}
​
/**
 * Your Vector2D will be called like this:
 * struct Vector2D *i = vector2DCreate(vec2d, rowSize, colSizes);
 * while (vector2DHasNext(i)) printf("%d\n", vector2DNext(i));
 * vector2DFree(i);
 */


/*
Difficulty:Medium
Total Accepted:26.6K
Total Submissions:66K


Companies Google Airbnb Twitter Zenefits
Related Topics Design
Similar Questions 
                
                  
                    Binary Search Tree Iterator
                  
                    Zigzag Iterator
                  
                    Peeking Iterator
                  
                    Flatten Nested List Iterator
*/
