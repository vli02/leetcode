/*
161. One Edit Distance

Given two strings S and T, determine if they are both one edit distance apart.
*/

bool isOneEditDistance(char* s, char* t) {
    int sl = strlen(s);
    int tl = strlen(t);
    int i, m;
    
    m = sl - tl;
    if (m > 1 || m < -1) return false;
    
    for (i = 0; i < sl && i < tl; i ++) {
        if (s[i] == t[i]) continue;
        if (!m) return !strcmp(&s[i + 1], &t[i + 1]);
        if (m > 0) return !strcmp(&s[i + 1], &t[i]);
        return !strcmp(&s[i], &t[i + 1]);
    }
    
    return m != 0;
}


/*
Difficulty:Medium
Total Accepted:35.4K
Total Submissions:113.4K


Companies Snapchat Uber Facebook Twitter
Related Topics String
Similar Questions 
                
                  
                    Edit Distance
*/
