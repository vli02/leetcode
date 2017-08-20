/*
416. Partition Equal Subset Sum

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.


Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.



Example 1:
Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].



Example 2:
Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

bool canPartition(int* nums, int numsSize) {
    int t, s, i, k, *dp;
    
    t = 0;
    for (i = 0; i < numsSize; i ++) {
        t += nums[i];
    }
    
    if (t & 1) return false;
​
    t >>= 1;
    
    dp = calloc(t + 1, sizeof(int));
    //assert(dp);
    
    dp[0] = 1;
    for (i = 0; !dp[t] && i < numsSize; i ++) {
        k = nums[i];
        for (s = t; !dp[t] && s > 0; s --) {
            if (!dp[s] && s >= k) {
                dp[s] = dp[s - k];
            }
        }
    }
    
    i = dp[t];
    
    free(dp);
    
    return i;
}


/*
Difficulty:Medium
Total Accepted:25.4K
Total Submissions:65K


Companies eBay
Related Topics Dynamic Programming

*/
