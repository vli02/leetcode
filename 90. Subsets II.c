/*
90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.


For example,
If nums = [1,2,2], a solution is:


[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    /* assume input: [1, 2, 2, 3]
       1: []
       2: [1]           <- set 1 plus current number
       3: [2]           <- set 1 plus one 2
          [2, 2]        <- set 1 plus two 2
          [1, 2]        <- set 2 plus one 2
          [1, 2, 2]     <- set 2 plus two 2
       4: [3]
          [1, 3]
          [2, 3]
          [2, 2, 3]
          [1, 2, 3]
          [1, 2, 2, 3]
    */
}


/*
Difficulty:Medium
Total Accepted:116.2K
Total Submissions:321.2K


Companies Facebook
Related Topics Array Backtracking

*/
