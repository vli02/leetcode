/*
339. Nested List Weight Sum

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
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
int sum(int d, struct NestedInteger** list, int sz) {
    struct NestedInteger *ni;
    int i, s = 0;
    
    for (i = 0; i < sz; i ++) {
        ni = list[i];
        if (NestedIntegerIsInteger(ni)) {
            s += NestedIntegerGetInteger(ni) * d;
        } else {
            s += sum(d + 1, NestedIntegerGetList(ni), NestedIntegerGetListSize(ni));
        }
    }
    return s;
}
int depthSum(struct NestedInteger** nestedList, int nestedListSize) {
    return sum(1, nestedList, nestedListSize);
}


/*
Difficulty:Easy
Total Accepted:23.7K
Total Submissions:38.4K


Companies LinkedIn
Related Topics Depth-first Search
Similar Questions 
                
                  
                    Nested List Weight Sum II
                  
                    Array Nesting
*/
