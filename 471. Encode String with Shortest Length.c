/*
471. Encode String with Shortest Length

Given a non-empty string, encode the string such that its encoded length is the shortest.


The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.


Note:

k will be a positive integer and encoded string will not be empty or have extra space.
You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.



Example 1:
Input: "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.



Example 2:
Input: "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.



Example 3:
Input: "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".



Example 4:
Input: "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".



Example 5:
Input: "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".
*/

typedef struct patt_s {
    char *s;
    int len;
} patt_t;
#define IDX(I, J) (((I) * len) + J)
int patt_split(char *s, int len, int *j) {
    int i, l, k, match;
    for (i = len; i >= 2; i --) {
        if (!(len % i)) {
            match = 1;
            l = len / i;
            for (k = 1; match && k < i; k ++) {
                if (strncmp(&s[0], &s[k * l], l)) {
                    match = 0;
                }
            }
            if (match) { *j = l - 1; return i; }
        }
    }
    return 0;
}
char* encode(char* s) {
    patt_t *dp, *p, *p1, *p2;
    char *buff;
    int len = strlen(s);
​
    int l, i, j, k;
    int n, pl, nl;
    
    dp = malloc(len * len * sizeof(patt_t));
    //assert(dp);
    
    for (l = 0; l < len; l ++) {
        for (i = 0; i < len - l; i ++) {  // start pointer
            j = i + l;                    // end pointer
            p = &dp[IDX(i, j)];
            
            p->len = l + 1;
            buff = malloc(p->len + 1);
            //assert(buff);
            strncpy(buff, &s[i], p->len);
            buff[p->len] = 0;
            p->s = buff;
​
            if (l < 4) continue;
            
            for (k = i; k < j; k ++) {
                p1 = &dp[IDX(i, k)];
                p2 = &dp[IDX(   k + 1, j)];
                if (p->len > p1->len + p2->len) {
                    p->len = p1->len + p2->len;
                    buff = malloc(p->len + 1);
                    //assert(buff);
                    strcpy(buff, p1->s);
                    strcat(buff, p2->s);
                    free(p->s);
                    p->s = buff;
                }
            }
            
            n = patt_split(&s[i], l + 1, &j);
            if (n > 1) {
                p1 = &dp[IDX(i, i + j)];
                buff = malloc(12 + 1 + p1->len + 1 + 1);
                //assert(buff);
                nl = sprintf(buff, "%d[", n);
                strncpy(&buff[nl], p1->s, p1->len);
                nl += p1->len;
                buff[nl ++] = ']';
                buff[nl] = 0;
                
                if (p->len > nl) {
                    free(p->s);
                    p->len = nl;
                    p->s = buff;
                } else {
                    free(buff);
                }
            }
        }
    }
    
    p = &dp[IDX(0, len - 1)];
    s = p->s;
    p->s = NULL;
    
    // clean up all memory
    for (i = 0; i < len * len; i ++) {
        p = &dp[i];
        //if (p->s) { printf("%s\n", p->s); }
        //if (p->s) free(p->s);
    }
    free(dp);
    
    return s;
}


/*
Difficulty:Hard
Total Accepted:4.9K
Total Submissions:11.6K


Companies Google
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Decode String
*/
