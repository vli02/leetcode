/*
377. Combination Sum IV

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.



Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers? 

Credits:Special thanks to @pbrother for adding this problem and creating all test cases.
*/

int combinationSum4(int* nums, int numsSize, int target) {
    int i, k, n;
#if 0
    if (target == 0) return 1;
    n = 0;
    for (i = 0; i < numsSize; i ++) {
        k = nums[i];
        if (target >= k) {
            n += combinationSum4(nums, numsSize, target - k);
        }
    }
#else
    int t, *dp;
    dp = calloc((target + 1), sizeof(int));
    dp[0] = 1;
    for (t = 1; t <= target; t ++) {    // outer loop target inner loop number => result has dup
        for (i = 0; i < numsSize; i ++) {  // outer loop number inner loop target => result uniq
            k = nums[i];
            if (t >= k) {
                dp[t] += dp[t - k];
                //printf("%d,%d: %d\n", t, k, dp[t]);
            }
        }
    }
    n = dp[target];
    free(dp);
#endif
    return n;
}


/*
Difficulty:Medium
Total Accepted:40.4K
Total Submissions:96.3K


Companies Google Snapchat Facebook
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Combination Sum
*/
