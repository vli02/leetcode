/*
494. Target Sum

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 

Find out how many ways to assign symbols to make sum of integers equal to target S.  


Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.



Note:

The length of the given array is positive and will not exceed 20. 
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

int findTargetSumWays(int* nums, int numsSize, int S) {
    // 1. Backtracking is pretty straightforward, refer to Expression Add Operators.
    // 2. 0-1 knapsack dp solution:
    int i, T = 0;
    int *dp, s, k;
    
    for (i = 0; i < numsSize; i ++) {
        T += nums[i];
    }
    
    if (T < S || ((T + S) & 1)) return 0;
    
    s = (T + S) >> 1;
    dp = calloc(s + 1, sizeof(int));
    //assert(dp);
    
    dp[0] = 1;
    for (i = 0; i < numsSize; i ++) {
        for (k = s; k >= nums[i]; k --) {
            dp[k] += dp[k - nums[i]];
            //printf("%d,%d: %d\n", i, k, dp[k]);
        }
    }
    
    i = dp[s];
    
    free(dp);
    
    return i;
}


/*
Difficulty:Medium
Total Accepted:26.4K
Total Submissions:60.7K


Companies Google Facebook
Related Topics Depth-first Search Dynamic Programming
Similar Questions 
                
                  
                    Expression Add Operators
*/
