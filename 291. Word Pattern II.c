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

bool patmatch(int *pat, int patlen, int *seglen, char *str, int slen) {
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
bool cut_and_match(int *pat, int patlen, int *dup, int *seglen, int *visited, int xlen, int d, char *str, int slen) {
    int i, t;
    
    if (d == patlen) {  // done cutting, try match
        if (xlen % patlen) return false;
        return patmatch(pat, patlen, seglen, str, slen);
    }
    
    if (visited[pat[d]]) {
        return cut_and_match(pat, patlen, dup, seglen, visited, xlen, d + 1, str, slen);
    } else {
        visited[pat[d]] = 1;
        
        for (i = 1; i * dup[pat[d]] <= xlen; i ++) {
            seglen[pat[d]] = i;
            t = cut_and_match(pat, patlen, dup, seglen, visited, xlen - i * dup[pat[d]], d + 1, str, slen);
            if (t) return true;
        }
        
        visited[pat[d]] = 0;
    }
    
    return false;
}
bool wordPatternMatch(char* pattern, char* str) {
    int bits = 0;
    int pat[100] = { 0 };
    int patlen = 0, slen;
    int i, k;
    int seglen[26] = { 0 };
    int visited[26] = { 0 };
    int dup[26];
    
    if ((!pattern || !*pattern) && (!str || !*str)) return true;
    if (!pattern || !*pattern || !str || !*str) return false;
    
    for (i = 0; pattern[i]; i ++) {
        k = pattern[i] - 'a';
        pat[i] = k;
        if (!(bits & (1 << k))) {
            bits |= (1 << k);
            dup[k] = 1;
        } else {
            dup[k] ++;
        }
    }
    patlen = i;
    
    slen = strlen(str);
    
    return cut_and_match(pat, patlen, dup, seglen, visited, slen, 0, str, slen);
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
