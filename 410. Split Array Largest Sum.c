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

#define ROW 1000
#define COL 51

long split(int *nums, int sz, int start, int m, long sum[ROW], long dp[ROW][COL]) {
    int i;
    long k, k1, k2;
    unsigned long min = 0xffffffff;
    
    if (m == 1) return sum[start]; // sum of nums[start...end]
    
    if (dp[start][m] != -1) return dp[start][m];
    
    k1 = 0;
    for (i = start; i <= sz - m; i ++) {
        k1 += nums[i];                                  // first half
        k2 = split(nums, sz, i + 1, m - 1, sum, dp);    // second half
        k = k1 > k2 ? k1 : k2;                          // max of first and second
        if (min > k) min = k;                           // min of all possible cuts
    }
    dp[start][m] = min;
    
    return min;
}
int splitArray(int* nums, int numsSize, int m) {
    // the lower bound is the max number in the array
    // the upper bound is the summary of all in the array
    // use binary search between lower and upper bounds to
    // verify if assume boundary is possible to split the
    // array into m.
    
    // dp/memorization
    long sum[ROW], dp[ROW][COL], k;
    int i;
    
    k = 0;
    for (i = numsSize - 1; i >= 0; i --) {
        k += nums[i];
        sum[i] = k;
    }
    
    memset(dp, -1, ROW * COL * sizeof(dp[0][0]));
    
    return split(nums, numsSize, 0, m, sum, dp);;
}


/*
Difficulty:Hard
Total Accepted:13.8K
Total Submissions:37.3K


Companies Baidu Facebook
Related Topics Binary Search Dynamic Programming

*/
