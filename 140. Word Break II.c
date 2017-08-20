/*
140. Word Break II

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.



Return all such possible sentences.



For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].



A solution is ["cats and dog", "cat sand dog"].



UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **p;
    int sz;
    int n;
} res_t;
typedef struct {
    char *b;
    int sz;
    int n;
} buff_t;
void add2res(res_t *res, char *str) {
    if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = str;
}
void add2buff(buff_t *buff, int n, char *s, int l) {
    buff->n = n;
    if (buff->sz <= buff->n + l + 2) {
        buff->sz *= 2 + l + 2;
        buff->b = realloc(buff->b, buff->sz * sizeof(char));
        //assert(buff->b);
    }
    strncpy(&buff->b[buff->n], s, l);
    buff->n += l;
    buff->b[buff->n] = ' ';
    buff->n ++;
}
int *newvec() {
    int *vec = malloc(12 * sizeof(int));
    //assert(vec);
    vec[0] = 12;
    vec[1] = 0;
    return vec;
}
void add2vec(int *vec, int i) {
    if (vec[0] == vec[1]) {
        vec[0] *= 2;
        vec = realloc(vec, vec[0] * sizeof(int));
        //assert(vec);
    }
    vec[2 + vec[1] ++] = i;
}
void bt(res_t *res, buff_t *buff, char *s, int **dp, int start, int end) {
    int i, k, n, *vec;
    
    if (start == end) {
        buff->b[-- buff->n] = 0;
        add2res(res, strdup(buff->b));
        return;
    }
    
    n = buff->n;
    
    vec = dp[start];
    for (i = 0; i < vec[1]; i ++) {
        k = vec[2 + i];
        add2buff(buff, n, &s[start], k - start);
        bt(res, buff, s, dp, k, end);
    }
}
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    res_t res;
    buff_t buff;
    
    int *wsz, **dp, *vec;
    int len, i, j, k;
​
    res.sz = 10;
    res.n = 0;
    res.p = malloc(res.sz * sizeof(char *));
    //assert(res.p);
    
    wsz = calloc(wordDictSize, sizeof(int));
    len = strlen(s);
    dp = calloc(len + 1, sizeof(int *));
    //assert(dp && used && len);
    
    buff.sz = 100;
    buff.n = 0;
    buff.b = malloc(buff.sz * sizeof(char));
    //assert(buff.b);
    
    for (i = 0; i < wordDictSize; i ++) {
        wsz[i] = strlen(wordDict[i]);
    }
    
    dp[0] = newvec();
    for (i = 0; i < len; i ++) {
        if (dp[i]) {    // a valid point to cut
            for (j = 0; j < wordDictSize; j ++) {
                if (!strncmp(&s[i], wordDict[j], wsz[j])) {
                    k = i + wsz[j];
                    add2vec(dp[i], k);
                    if (!dp[k]) dp[k] = newvec();
                }
            }
        }
    }
    
    if (dp[len]) {
        bt(&res, &buff, s, dp, 0, len);
    }
    
    free(wsz);
    for (i = 1; i <= len; i ++) {
        if (dp[i]) free(dp[i]);
    }
    free(dp);
    free(buff.b);
​
    *returnSize = res.n;
    
    return res.p;
}


/*
Difficulty:Hard
Total Accepted:92K
Total Submissions:395K


Companies Dropbox Google Uber Snapchat Twitter
Related Topics Dynamic Programming Backtracking
Similar Questions 
                
                  
                    Word Break
                  
                    Concatenated Words
*/
