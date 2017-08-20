/*
340. Longest Substring with At Most K Distinct Characters

Given a string, find the length of the longest substring T that contains at most k distinct characters.



For example,

Given s = “eceba” and k = 2,



T is "ece" which its length is 3.
*/

#if 0
int sub_len(char *s, int k) {
    int bits[4] = { 0 };
    int l, b;
    
    l = b = 0;
    while (*s) {
        b = 1 << (*s % 32);
        if (!(bits[(*s) / 32] & b)) {
            if (!k) return l;
            k --;
            bits[(*s) / 32] |= b;
        }
        s ++;
        l ++;
    }
    return l;
}
int lengthOfLongestSubstringKDistinct(char* s, int k) {
    int l, t = 0;
    int len;
    if (!s) return 0;
    len = strlen(s);
    while (len > t) {
        l = sub_len(s, k);
        if (t < l) t = l;
        len --;
        s ++;
    }
    return t;
}
#else
int lengthOfLongestSubstringKDistinct(char* s, int k) {
    int cnt[128] = { 0 };
    int head, tail, d = 0;
    char c;
    
    if (k == 0) return 0;
    
    head = tail = 0;
    while (s[tail]) {
        while (s[tail] && (cnt[s[tail]] > 0 || k > 0)) { // advance k distinct characters
            if (cnt[s[tail]] == 0) {
                k --;  // reduce number if a new character is counted
            }
            cnt[s[tail]] ++;  // record the count
            tail ++;
        }
        
        if (d < tail - head) {
            d = tail - head;
        }
        
        do {
            c = s[head ++];
            cnt[c] --;  // reduce the count
        } while (cnt[c] > 0);  // push out one distinct character from head
        
        k = 1;  // find another one distince character from tail
    }
    
    return d;
}
#endif


/*
Difficulty:Hard
Total Accepted:24.3K
Total Submissions:62.7K


Companies Google
Related Topics Hash Table String
Similar Questions 
                
                  
                    Longest Substring with At Most Two Distinct Characters
                  
                    Longest Repeating Character Replacement
*/
