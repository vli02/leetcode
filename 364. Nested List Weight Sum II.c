/*
364. Nested List Weight Sum II

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
*/

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
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
void depth(int d, int *max, struct NestedInteger **list, int sz) {
    int i;
    struct NestedInteger *ni;
    for (i = 0; i < sz; i ++) {
        ni = list[i];
        if (!NestedIntegerIsInteger(ni)) {
            depth(d + 1, max, NestedIntegerGetList(ni), NestedIntegerGetListSize(ni));
        } else if (*max < d) {
            *max = d;
        }
    }
}
int sum(int max, int d, struct NestedInteger **list, int sz) {
    int i, s = 0;
    struct NestedInteger *ni;
    for (i = 0; i < sz; i ++) {
        ni = list[i];
        if (NestedIntegerIsInteger(ni)) {
            s += NestedIntegerGetInteger(ni) * (max - d + 1);
        } else {
            s += sum(max, d + 1, NestedIntegerGetList(ni), NestedIntegerGetListSize(ni));
        }
    }
    return s;
}
int depthSumInverse(struct NestedInteger** nestedList, int nestedListSize) {
    int max = 1;
    depth(1, &max, nestedList, nestedListSize);
    return sum(max, 1, nestedList, nestedListSize);
}


/*
Difficulty:Medium
Total Accepted:14.9K
Total Submissions:28.4K


Companies LinkedIn
Related Topics Depth-first Search
Similar Questions 
                
                  
                    Nested List Weight Sum
                  
                    Array Nesting
*/
