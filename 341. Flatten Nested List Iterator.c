/*
341. Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].



Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedIterator {
    int stack_sz;
    int sp;
    struct NestedInteger **stack;
    int val;
};
​
#define PUSH(I, P) do { (I)->stack[(I)->sp ++] = (P); } while (0)
#define POP(I, P)  do { (P) = (I)->stack[-- (I)->sp]; } while (0)
​
struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator *iter;
    struct NestedInteger **stack, *p;
    int i, sz;
    
    sz = nestedListSize + 100;
    stack = malloc(sz * sizeof(struct NestedInteger *));
    iter = malloc(sizeof(struct NestedIterator));
    //assert(stack && iter);
    iter->stack_sz = sz;
    iter->stack = stack;
    iter->sp = 0;
    
    while (nestedListSize > 0) {
        p = nestedList[-- nestedListSize];
        if (p) PUSH(iter, p);
    }
    
    return iter;
}
​
bool nestedIterHasNext(struct NestedIterator *iter) {
    struct NestedInteger **list;
    struct NestedInteger *p;
    int n;
    
    while (iter->sp) {
        POP(iter, p);
        if (NestedIntegerIsInteger(p)) {
            //PUSH(iter, p);
            iter->val = NestedIntegerGetInteger(p);
            return true;
        }
        n = NestedIntegerGetListSize(p);
        if (iter->sp + n >= iter->stack_sz) {
            iter->stack_sz += n;
            iter->stack = realloc(iter->stack, iter->stack_sz * sizeof(struct NestedInteger *));
            //assert(iter->stack);
        }
        list = NestedIntegerGetList(p);
        while (n > 0) {
            p = list[-- n];
            if (p) PUSH(iter, p);
        }
    }
    return false;
}
​
int nestedIterNext(struct NestedIterator *iter) {
    //printf("%d,", iter->val);
    return iter->val;  // has next is always called prior
}
​
/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    free(iter->stack);
    free(iter);
}
​
/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */


/*
Difficulty:Medium
Total Accepted:40.9K
Total Submissions:98.5K


Companies Google Facebook Twitter
Related Topics Stack Design
Similar Questions 
                
                  
                    Flatten 2D Vector
                  
                    Zigzag Iterator
                  
                    Mini Parser
                  
                    Array Nesting
*/
