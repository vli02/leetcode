/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.



For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

int numSquares(int n) {
    int i, j, k;
    int *dp;
    
    dp = malloc((n + 1) * sizeof(int));
    //assert(dp);
    
    dp[0] = 0;
    for (i = 1; i <= n; i ++) {
        k = dp[i - 1] + 1;      // answer of preceeding number plus 1
        j = 2;
        while (i >= j * j) {    // after j ^ 2
            if (k > dp[i - j * j] + 1) {
                k = dp[i - j * j] + 1;
            }
            j ++;
        }
        dp[i] = k;
    }
    
    k = dp[n];
    free(dp);
    
    return k;
}


/*
Difficulty:Medium
Total Accepted:81.3K
Total Submissions:220.9K


Companies Google
Related Topics Dynamic Programming Breadth-first Search Math
Similar Questions 
                
                  
                    Count Primes
                  
                    Ugly Number II
*/
