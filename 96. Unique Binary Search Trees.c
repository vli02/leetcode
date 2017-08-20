/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?


For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

int numTrees(int n) {
    int *dp;
    int i, j;
    
    dp = calloc((n + 1), sizeof(int));
    //assert(dp);
    
    dp[0] = dp[1] = 1;
    
    for (i = 2; i <= n; i ++) {
        for (j = 1; j <= i; j ++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    
    i = dp[n];
    free(dp);
    
    return i;
}


/*
Difficulty:Medium
Total Accepted:125.7K
Total Submissions:307K


Companies Snapchat
Related Topics Tree Dynamic Programming
Similar Questions 
                
                  
                    Unique Binary Search Trees II
*/
