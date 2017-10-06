/*
516. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.


Example 1:
Input: 
"bbbab"

Output: 
4

One possible longest palindromic subsequence is "bbbb".


Example 2:
Input:
"cbbd"

Output:
2

One possible longest palindromic subsequence is "bb".
*/

#define IDX(I, J, L) ((I) * (L) + J)
​
int helper(char *s, int i, int j, int l, int *memo) {
    int k1, k2, k;
    
    if (i > j) return 0;
    if (i == j) return 1;
    
    if (memo[IDX(i, j, l)]) return memo[IDX(i, j, l)];
    
    if (s[i] == s[j]) {
        // head and tail match
        k = helper(s, i + 1, j - 1, l, memo) + 2;
    } else {
        // head and tail not match, try reducing tail or shifting head
        k1 = helper(s, i, j - 1, l, memo);
        k2 = helper(s, i + 1, j, l, memo);
        k = k1 > k2 ? k1 : k2;
    }
    memo[IDX(i, j, l)] = k;
    
    return k;
}
int longestPalindromeSubseq(char* s) {
    int *memo, l;
    
    if (!s || !*s) return 0;
    
    l = strlen(s);
    
    memo = calloc(l * l, sizeof(int));
    
    l = helper(s, 0, l - 1, l, memo);
        
    free(memo);
    
    return l;
}


/*
Difficulty:Medium
Total Accepted:19K
Total Submissions:44.5K


Companies Amazon Uber
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Longest Palindromic Substring
                  
                    Palindromic Substrings
*/
