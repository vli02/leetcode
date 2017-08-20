/*
49. Group Anagrams

Given an array of strings, group anagrams together.


For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note: All inputs will be in lower-case.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    /* make a bit map and compare the bits */
    char ***p, **buff;
    int *c;
    int *b, **k, *kbuff, *lens;
    int i, j, n, x, sz, t;
    char *s;
    
    *returnSize = 0;
    *columnSizes = NULL;
    if (strsSize == 0) return NULL;
    
    p = malloc(strsSize * sizeof(char **));
    c = malloc(strsSize * sizeof(int));
    //assert(p && c);
    
    b = calloc(strsSize, sizeof(int));
    k = calloc(strsSize, sizeof(int *));
    lens = calloc(strsSize, sizeof(int));
    kbuff = calloc(strsSize * 26, sizeof(int));
    //assert(b && k && lens && kuff);
    
    for (i = 0; i < strsSize; i ++) {
        k[i] = &kbuff[i * 26];
    }
    
    n = 0;
    for (i = 0; i < strsSize; i ++) {
        s = strs[i];
        if (!s || b[i] == -1) continue;
        
        if (b[i] == 0) {
            while (*s) {
                k[i][*s - 'a'] ++;
                s ++;
                lens[i] ++;
            }
        }
        b[i] = 1;
        
        sz = 10;
        buff = malloc(sz * sizeof(char *));
        //assert(buff);
        x = 0;
        buff[x ++] = strs[i];
        b[i] = -1;
        
        for (j = i + 1; j < strsSize; j ++) {
            s = strs[j];
            if (!s || b[j] == -1) continue;
            
            if (b[j] == 0) {
                while (*s) {
                    k[j][*s - 'a'] ++;
                    s ++;
                    lens[j] ++;
                }
            }
            b[j] = 1;
            
            if (lens[j] != lens[i]) continue;
            
            for (t = 0; t < 26; t ++) {
                if (k[j][t] != k[i][t]) break;
            }
            
            if (t == 26) {
                if (sz == x) {
                    sz *= 2;
                    buff = realloc(buff, sz * sizeof(char *));
                    //assert(buff);
                }
                buff[x ++] = strs[j];
                b[j] = -1;
            }
        }
        p[n] = buff;
        c[n] = x;
        n ++;
    }
    free(b); free(k[0]); free(k);
    *columnSizes = c;
    *returnSize = n;
    return p;
}


/*
Difficulty:Medium
Total Accepted:144.2K
Total Submissions:415.6K


Companies Amazon Bloomberg Uber Facebook Yelp
Related Topics Hash Table String
Similar Questions 
                
                  
                    Valid Anagram
                  
                    Group Shifted Strings
*/
