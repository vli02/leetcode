/*
15. 3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i, x, y, k;
    int **p, sz, n;
    
    sz = 10;
    p = malloc(sz * sizeof(int *));
    //assert(p);
    n = 0;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (i = 0; i < numsSize - 2; i ++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        x = i + 1;
        y = numsSize - 1;
        while (x < y) {
            k = nums[i] + nums[x] + nums[y];
            if (k == 0) {
                // found one
                if (n == sz) {
                    sz *= 2;
                    p = realloc(p, sz * sizeof(int *));
                    //assert(p);
                }
                p[n] = malloc(3 * sizeof(int));
                p[n][0] = nums[i];
                p[n][1] = nums[x];
                p[n][2] = nums[y];
                n ++;
                x ++;
                while (x < y && nums[x] == nums[x - 1]) x ++;
                y --;
                while (x < y && nums[y] == nums[y + 1]) y --;
            } else if (k < 0) {
                x ++;
                while (x < y && nums[x] == nums[x - 1]) x ++;
            } else {
                y --;
                while (x < y && nums[y] == nums[y + 1]) y --;
            }
        }
    }
    
    *returnSize = n;
    return p;
}


/*
Difficulty:Medium
Total Accepted:231.6K
Total Submissions:1.1M


Companies Amazon Microsoft Bloomberg Facebook Adobe Works Applications
Related Topics Array Two Pointers
Similar Questions 
                
                  
                    Two Sum
                  
                    3Sum Closest
                  
                    4Sum
                  
                    3Sum Smaller
*/
