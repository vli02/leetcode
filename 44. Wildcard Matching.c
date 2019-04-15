/*
44. Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#define MATCH(A, B) ((A) == (B) || ((A) && (B) == '?'))
#define IDX(I, J) ((I + 1) * (plen + 1) + J + 1)

#define ALG 1

bool match_recursive(char *s, char *p, int *retry) {
    if (!*p) return (*s) ? 0 : 1;

    if (*p == '*') {
        do { p ++; } while (*p == '*');
        
        if (!*p) return 1;
        
        while (*s && *retry) {
            if (match_recursive(s, p, retry)) {
                return 1;
            }
            s ++;  // skip one and retry
        }
        *retry = 0; // s reaches the end, still not matching, no need to retry on all previous '*'
        return 0;
    }
    
    if (!MATCH(*s, *p)) return 0;
    
    return match_recursive(s + 1, p + 1, retry);
}
bool match_2_pointers(char *s, char *p) {
    char *saved_s, *saved_p = NULL;

    while (*s) {
        if (*p == '*') {
            do { p ++; } while (*p == '*');
            
            if (!*p) return 1;
            
            saved_s = s + 1;    // save the next s pointer for retry with skipping one
            saved_p = p;        // save the next p pointer for retry with skipping one
            continue;
        }
        
        if (MATCH(*s, *p)) { s ++; p ++; continue; }
        
        if (saved_p) {
            s = saved_s ++;     // go back to previously saved s pointer
                                // and advance the saved pointer for continuously skipping one
            p = saved_p;        // go back to previously saved p pointer and retry 
            continue;
        }
        return 0;
    }
    
    while (*p == '*') p ++;
    
    return (*p) ? 0 : 1;
}
bool match_dp(char *s, char *p) {
    int slen = strlen(s);
    int plen = strlen(p);
    int *dp = calloc((slen + 1) * (plen + 1), sizeof(int));
    int i, j;
    dp[0] = 1;
    for (j = 0; j < plen; j ++) {
        if (p[j] == '*') {
            dp[IDX(-1, j)] = dp[IDX(-1, j - 1)];
        }
    }
    for (i = 0; i < slen; i ++) {
        for (j = 0; j < plen; j ++) {
            if (p[j] != '*') {
                // it is a match if current match and previous s & p are a match
                dp[IDX(i, j)] = MATCH(s[i], p[j]) && dp[IDX(i - 1, j - 1)];
            } else {
                dp[IDX(i, j)] = dp[IDX(i, j - 1)] ||    // '*' match empty
                                dp[IDX(i - 1, j)];      // '*' match as one or multiple of any
            }
        }
    }
    
    i = dp[IDX(slen - 1, plen - 1)];
    
    free(dp);
    
    return i;
}
bool isMatch(char* s, char* p) {
#if ALG == 1    // 8ms, 7M
    int retry = 1;
    return match_recursive(s, p, &retry);
#elif ALG == 2  // 8ms, 7M
    return match_2_pointers(s, p);
#else           // 48ms, 23M
    return match_dp(s, p);
#endif
}


/*
Difficulty:Hard
Total Accepted:97.7K
Total Submissions:487.4K


Companies Google Snapchat Two Sigma Facebook Twitter
Related Topics Dynamic Programming Backtracking Greedy String
Similar Questions 
                
                  
                    Regular Expression Matching
*/
