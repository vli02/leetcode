/*
291. Word Pattern II

Given a pattern and a string str, find if str follows the same pattern.
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:

pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.




Notes:
You may assume both pattern and str contains only lowercase letters.
*/

bool patmatch(int *seglen, char *pat, int patlen, char *str, int slen) {
    char *buckets[26] = { 0 };
    int i, j, k;
    
    i = j = 0;
    while (j < slen) { // parse entire str
        if (!buckets[pat[i]]) {
            for (k = 0; k < patlen; k ++) {
                if (buckets[pat[k]] &&
                    seglen[pat[i]] == seglen[pat[k]] &&
                    !strncmp(&str[j], buckets[pat[k]], seglen[pat[k]])) {
                    return false;
                }
            }
            buckets[pat[i]] = &str[j];
        } else if (strncmp(&str[j], buckets[pat[i]], seglen[pat[i]])) {
            return false;
        }
        j += seglen[pat[i]];
        i = (i + 1) % patlen;
    }
    if (i == 0 && j == slen) return true;
    return false;
}
​
bool rematch(int n, int d, int *seglen, int *dup, char *pat, int patlen, char *str, int slen) {
    int i;
    int plen = slen;
    
    for (i = 0; i < patlen; i ++) {
        if (pat[i] != pat[n]) {
            plen -= seglen[pat[i]];
        }
    }
    
    if (n == 0) {
        for (i = 1; i <= plen/(dup[pat[n]] + 1); i ++) {
            seglen[pat[n]] = i;
            if (patmatch(seglen, pat, patlen, str, slen)) return true;
        }
        seglen[pat[n]] = 1;
        return false;
    }
    
    for (i = d ? 1 : 2; i <= plen/(dup[pat[n]] + 1); i ++) {
        seglen[pat[n]] = i;
        if (rematch(n - 1, d + 1, seglen, dup, pat, patlen, str, slen)) return true;
    }
    seglen[pat[n]] = 1;
    
    return false;
}
​
bool wordPatternMatch(char* pattern, char* str) {
    int bits = 0;
    char pat[100] = { 0 };
    int patlen = 0, slen;
    int i, k;
    int seglen[26];
    int visited[26] = { 0 };
    int dup[26] = { 0 };
    
    if ((!pattern || !*pattern) && (!str || !*str)) return true;
    if (!pattern || !*pattern || !str || !*str) return false;
    
    for (i = 0; pattern[i]; i ++) {
        k = pattern[i] - 'a';
        pat[i] = k;
        if (!(bits & (1 << k))) {
            bits |= (1 << k);
        } else {
            dup[k] ++;
        }
    }
    patlen = i;
    
    slen = strlen(str);
    if (slen < patlen) return false;
    
    for (i = 0; i < sizeof(seglen)/sizeof(seglen[0]); i ++) {
        seglen[i] = 1;
    }
    
    for (i = 0; i < patlen; i ++) {
        if (!visited[pat[i]] && rematch(i, 0, seglen, dup, pat, patlen, str, slen)) return true;
        visited[pat[i]] = 1;
    }
    
    return false;
}


/*
Difficulty:Hard
Total Accepted:16.3K
Total Submissions:42.7K


Companies Dropbox Uber
Related Topics Backtracking
Similar Questions 
                
                  
                    Word Pattern
*/
