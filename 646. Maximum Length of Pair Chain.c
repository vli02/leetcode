/*
646. Maximum Length of Pair Chain

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.



Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion. 



Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.



Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]



Note:

The number of given pairs will be in the range [1, 1000].
*/

int cmp(const void *a, const void *b) {
    int x = (*(int **)a)[0], y = (*(int **)b)[0];
    //printf("cmp: %d:%d\n", x, y);
    
    if (x < y) return -1;
    else if (x > y) return 1;
    return 0;
}
int findLongestChain(int** pairs, int pairsRowSize, int pairsColSize) {
    int i, j, max, *dp;
    
    dp = malloc(pairsRowSize * sizeof(int));
    //assert(dp);
    
    qsort(pairs, pairsRowSize, sizeof(int *), cmp);
    
    max = 1;
    for (i = 0; i < pairsRowSize; i ++) {
        dp[i] = 1;
        for (j = 0; j < i; j ++) {
            if (pairs[i][0] > pairs[j][1] &&
                dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (max < dp[i]) max = dp[i];
            }
        }
    }
    
    free(dp);
    
    return max;
}

/*
Difficulty:Medium
Total Accepted:10.1K
Total Submissions:21.3K


Companies Amazon
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Longest Increasing Subsequence
                  
                    Increasing Subsequences
*/
