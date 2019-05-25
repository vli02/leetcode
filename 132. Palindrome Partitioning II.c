/*
132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.


Return the minimum cuts needed for a palindrome partitioning of s.


For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

int _min(int a, int b) {
    return a < b ? a : b;
}
int minCut(char* s) {
    int *dp, n, i, k;
    
    n = strlen(s);
    
    dp = malloc((n + 1) * sizeof(int));     // number of cuts on length
    //assert(dp);
    
    dp[0] = -1;
    for (i = 0; i < n; i ++) {
        dp[i + 1] = dp[i] + 1;
    }
    
    for (i = 0; i < n; i ++) {
        dp[i + 1] = _min(dp[i + 1], dp[i] + 1);
        
        for (k = 1;                 // "aba"
             i - k >= 0 &&
             i + k < n &&
             s[i - k] == s[i + k];
             k ++) {
            dp[i + k + 1] = _min(dp[i + k + 1], dp[i - k] + 1);
        }
        
        for (k = 1;                 // "aaaa"
             i - k + 1 >= 0 &&
             i + k < n &&
             s[i - k + 1] == s[i + k];
             k ++) {
            dp[i + k + 1] = _min(dp[i + k + 1], dp[i - k + 1] + 1);
        }
    }
    
    i = dp[n];
    
    free(dp);
    
    return i;
}


/*
Difficulty:Hard
Total Accepted:71.7K
Total Submissions:296.7K


Related Topics Dynamic Programming
Similar Questions Palindrome Partitioning

*/
