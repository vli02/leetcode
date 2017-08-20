/*
170. Two Sum III - Data structure design

Design and implement a TwoSum class. It should support the following operations: add and find.


add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.



For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

typedef struct {
    int *p;
    int sz;
    int n;
} TwoSum;
​
/** Initialize your data structure here. */
TwoSum* twoSumCreate() {
    TwoSum *obj = malloc(sizeof(TwoSum));
    //assert(obj);
    obj->sz = 100;
    obj->p = malloc(obj->sz * sizeof(int));
    //assert(obj->p);
    obj->n = 0;
    return obj;
}
​
/** Add the number to an internal data structure.. */
void twoSumAdd(TwoSum* obj, int number) {
    if (obj->n == obj->sz) {
        // enlarge the buffer
        obj->sz *= 2;
        obj->p = realloc(obj->p, obj->sz * sizeof(int));
        //assert(obj->p);
    }
    obj->p[obj->n ++] = number; // keep the array sorted if there is a need.
}
​
/** Find if there exists any pair of numbers which sum is equal to the value. */
bool twoSumFind(TwoSum* obj, int value) {
    int i, j;
    for (i = 0; i < obj->n - 1; i ++) {
        for (j = i + 1; j < obj->n; j ++) {
            if (obj->p[i] + obj->p[j] == value) return true;
        }
    }
    return false;
}
​
void twoSumFree(TwoSum* obj) {
    free(obj->p);
    free(obj);
}
​
/**
 * Your TwoSum struct will be instantiated and called as such:
 * struct TwoSum* obj = twoSumCreate();
 * twoSumAdd(obj, number);
 * bool param_2 = twoSumFind(obj, value);
 * twoSumFree(obj);
 */


/*
Difficulty:Easy
Total Accepted:28.4K
Total Submissions:116.1K


Companies LinkedIn
Related Topics Hash Table Design
Similar Questions 
                
                  
                    Two Sum
                  
                    Unique Word Abbreviation
                  
                    Two Sum IV - Input is a BST
*/
