/*
16. 3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int i, x, y, k, d, d1;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    d = 0;
    for (i = 0; i < numsSize - 2; i ++) {
        x = i + 1;
        y = numsSize - 1;
        while (x < y) {
            k = nums[i] + nums[x] + nums[y];
            if (k == target) {
                return k;
            } else if (k > target) {
                y --;
            } else {
                x ++;
            }
            d1 = k - target;
            if (d == 0 || abs(d) > abs(d1)) {
                d = d1;
            }
        }
    }
    return target + d;
}


/*
Difficulty:Medium
Total Accepted:136.6K
Total Submissions:439.3K


Companies Bloomberg
Related Topics Array Two Pointers
Similar Questions 
                
                  
                    3Sum
                  
                    3Sum Smaller
*/
