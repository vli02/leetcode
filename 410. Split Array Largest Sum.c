/*
410. Split Array Largest Sum

Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.


Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)



Examples: 
Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/

#define IDX(I, L, M) ((I) * (L) + M - 1)
int split(int *nums, int sz, int start, int l, int m, int *sum, int *dp) {
    int i, k, k1, k2;
    unsigned int min = 0xffffffff;
    
    if (m == 1) return sum[start]; // sum of nums[start...end]
    
    if (dp[IDX(start, l, m)] != -1) return dp[IDX(start, l, m)];
    
    k1 = 0;
    for (i = start; i <= sz - m; i ++) {
        k1 += nums[i];                                   // first half
        k2 = split(nums, sz, i + 1, l, m - 1, sum, dp);  // second half
        k = k1 > k2 ? k1 : k2;                           // max of first and second
        if (min > k) min = k;                            // min of all possible cuts
    }
    dp[IDX(start, l, m)] = min;
    
    return min;
}
int splitArray(int* nums, int numsSize, int m) {
    // the lower bound is the max number in the array
    // the upper bound is the summary of all in the array
    // use binary search between lower and upper bounds to
    // verify if assume boundary is possible to split the
    // array into m.
    
    // dp/memorization
    int *sum, *dp;
    int k, i;
    
    sum = malloc(numsSize * sizeof(int));
    dp = malloc(numsSize * m * sizeof(int));
    //assert(sum && dp);
    
    k = 0;
    for (i = numsSize - 1; i >= 0; i --) {
        k += nums[i];
        sum[i] = k;
    }
    
    memset(dp, -1, numsSize * m * sizeof(int));
    
    i = split(nums, numsSize, 0, m, m, sum, dp);
    
    free(sum);
    free(dp);
    
    return i;
}


/*
Difficulty:Hard
Total Accepted:13.8K
Total Submissions:37.3K


Companies Baidu Facebook
Related Topics Binary Search Dynamic Programming

*/
