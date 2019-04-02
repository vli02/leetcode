/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.



Example:
Input: "cbbd"

Output: "bb"
*/

char* longestPalindrome(char* s) {
    int sz;
    int i, j, k, l;
    int where = 0, len = 0;
    
    if (!s || !*s) return s;
    
    sz = strlen(s);
​
    for (i = 0, j = 0, k = 0; len < (sz - k) * 2; i = k, j = k) {
        while (j + 1 < sz && s[j] == s[j + 1]) {
            j ++;  // skip all repeating characters
        }
        k = j + 1; // where to start next try
        while (i > 0 && j + 1 < sz && s[i - 1] == s[j + 1]) {
            i --;  // expand dual direction
            j ++;
        }
        l = j - i + 1; // what we have fond so far
        if (len < l) {
            len = l;
            where = i;
        }
    }
    s = s + where;
    s[len] = 0;
    return s;
}


/*
Difficulty:Medium
Total Accepted:222.3K
Total Submissions:883.5K


Companies Amazon Microsoft Bloomberg
Related Topics String
Similar Questions 
                
                  
                    Shortest Palindrome
                  
                    Palindrome Permutation
                  
                    Palindrome Pairs
                  
                    Longest Palindromic Subsequence
                  
                    Palindromic Substrings
*/
