/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.


Return all possible palindrome partitioning of s.


For example, given s = "aab",

Return
[
  ["aa","b"],
  ["a","a","b"]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int start;
    int len;
} buff_t;
typedef struct {
    char ***p;
    int *csz;
    int psz;
    int pn;
} res_t;
void add2res(res_t *res, const char *s, buff_t *buff, int d) {
    int i;
    char *str, **pp;
    if (res->psz == res->pn) {
        res->psz = (res->psz == 0) ? 10 : res->psz * 2;
        res->p = realloc(res->p, res->psz * sizeof(char **));
        res->csz = realloc(res->csz, res->psz * sizeof(int));
        //assert(res->p && res->psz);
    }
    pp = malloc(d * sizeof(char *));
    //assert(pp);
    for (i = 0; i < d; i ++) {
        str = strndup(&s[buff[i].start], buff[i].len);
        pp[i] = str;
    }
    res->p[res->pn] = pp;
    res->csz[res->pn ++] = d;
}
int is_palindrome(const char *s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return 0;
        start ++;
        end --;
    }
    return 1;
}
void bt(const char *s, int start, int sz, buff_t *buff, int d, res_t *res) {
    int i;
    if (start == sz) {
        // done, save result
        add2res(res, s, buff, d);
        return;
    }
    for (i = start; i < sz; i ++) {
        if (is_palindrome(s, start, i)) {
            buff[d].start = start;
            buff[d].len = i - start + 1;
            bt(s, i + 1, sz, buff, d + 1, res);
        }
    }
}
char*** partition(char* s, int** columnSizes, int* returnSize) {
    res_t res = { 0 };
    buff_t *buff;
    int sz;
    
    sz = strlen(s);
    
    buff = malloc(sz * sizeof(buff_t));
    //assert(buff);
    
    bt(s, 0, sz, buff, 0, &res);
    
    //free(buff);
    
    *columnSizes = res.csz;
    *returnSize = res.pn;
    
    return res.p;
}


/*
Difficulty:Medium
Total Accepted:104.5K
Total Submissions:308.3K


Companies Bloomberg
Related Topics Backtracking
Similar Questions 
                
                  
                    Palindrome Partitioning II
*/
