/*
301. Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ). 



Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]



Credits:Special thanks to @hpplayer for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **p;
    int psz, pn;
} res_t;
char *substr(char *s, int l, int i) {
    char *buff = malloc(l * sizeof(char));
    //assert(buff);
    strncpy(buff, s, i - 0);
    strcpy(&buff[i - 0], &s[i + 1]);
    return buff;
}
void reverse(char *buff, int l) {
    int i, j;
    char x;
    for (i = 0, j = l - 1; i < j; i ++, j --) {
        x = buff[i];
        buff[i] = buff[j];
        buff[j] = x;
    }
}
void add_result(res_t *res, char *s) {
    if (res->psz == 0) {
        res->psz = 10;
        res->p = malloc(res->psz * sizeof(char *));
        //assert(res->p);
    } else if (res->psz == res->pn) {
        res->psz *= 2;
        res->p = realloc(res->p, res->psz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->pn ++] = s;
}
void remove1(char *s, int l, int si, int sj, res_t *res, char c1, char c2) {
    int i, j, d = 0;
    char *buff;
    
    for (j = sj; j < l; j ++) {
        if      (s[j] == c1) d ++;
        else if (s[j] == c2) d --;
        if (d < 0) {
            // found one invalid parenthese
            for (i = si; i <= j; i ++) {
                if (s[i] == c2 && (i == si || s[i - 1] != c2)) {
                    // make a new stirng by removing this invalid parenthese
                    buff = substr(s, l, i);
                    remove1(buff, l - 1, i, j, res, c1, c2);
                }
            }
            free(s);  // free the invalid string
            return;
        }
    }
    reverse(s, l);
    if (c1 == '(') {
        remove1(s, l, 0, 0, res, c2, c1);
        return;
    }
    // done, s is a valid one
    add_result(res, s);
}
char** removeInvalidParentheses(char* s, int* returnSize) {
    res_t res = { 0 };
    char *buff;
    int l;
    
    l = strlen(s);
    buff = malloc((l + 1) * sizeof(char));
    //assert(buff);
    strcpy(buff, s);
    
    remove1(buff, l, 0, 0, &res, '(', ')');
    
    *returnSize = res.pn;
    
    return res.p;
}


/*
Difficulty:Hard
Total Accepted:44.6K
Total Submissions:127.3K


Companies Facebook
Related Topics Depth-first Search Breadth-first Search
Similar Questions 
                
                  
                    Valid Parentheses
*/
