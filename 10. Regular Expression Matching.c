/*
10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#define NOT_MATCH(A, B) (((B) == '.' && (A) == 0) || ((B) != '.' && (A) != (B)))
#define MATCH(A, B)     ((A) == (B) || (B) == '.')
#define IDX(I, J)       (((I) + 1) * (plen + 1) + (J) + 1)
​
bool match_recursive(char *s, char *p, int *retry) {
    if (*p == 0) return *s == 0;
    if (*(p + 1) == '*') {
        while (*retry) {
            if (match_recursive(s, p + 2, retry)) {
                return true;
            }
            if (NOT_MATCH(*s, *p)) {
                return false;
            }
            s ++;
        }
        *retry = 0;
        return false;
    }
    if (NOT_MATCH(*s, *p)) {
        return false;
    }
    return match_recursive(s + 1, p + 1, retry);
}
bool isMatch(char* s, char* p) {
#if 0  // 22ms
    int retry = 1;
    return match_recursive(s, p, &retry);
#else  // 9ms
    int *dp;
    int i, j;
    int slen, plen;
    
    slen = strlen(s);
    plen = strlen(p);
    
    dp = calloc((slen + 1) * (plen + 1), sizeof(int));
    //assert(dp);
​
    dp[0] = 1;
    for (j = 0; j < plen; j ++) {
        if (p[j] == '*') {
            dp[IDX(-1, j)] = dp[IDX(-1, j - 2)];
        }
    }
    for (i = 0; i < slen; i++) {
        for (j = 0; j < plen; j++) {
            if (p[j] != '*') {
                dp[IDX(i, j)] = dp[IDX(i - 1, j - 1)] && MATCH(s[i], p[j]);
            } else {
                dp[IDX(i, j)] = dp[IDX(i, j - 2)] ||                                 // no s
                                dp[IDX(i, j - 1)] ||                                 // one s
                                (MATCH(s[i], p[j - 1]) && dp[IDX(i - 1, j)]);        // more s
            }
        }
    }
    
    i = dp[IDX(slen - 1, plen - 1)];
    
    free(dp);
    
    return i;
#endif
}


/*
Difficulty:Hard
Total Accepted:147.1K
Total Submissions:610.5K


Companies Google Uber Airbnb Facebook Twitter
Related Topics Dynamic Programming Backtracking String
Similar Questions 
                
                  
                    Wildcard Matching
*/
