/*
17. Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.



A mapping of digit to letters (just like on the telephone buttons) is given below.


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].



Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

const char *map[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
const int   len[] = {  3,     3,     3,     3,     3,     4,      3,     4     };
​
void dfs(char *p, int d, char *buff, char **pp, int *n) {
    const char *m;
    
    if (!*p) {
        pp[*n] = strdup(buff);
        (*n) ++;
        return;
    }
    
    m = map[(*p) - '2'];
    while (*m) {
        buff[d] = *m;
        dfs(p + 1, d + 1, buff, pp, n);
        m ++;
    }
}
​
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char **pp;
    char *buff;
    char *d;
    
    const char *m;
    int n, k, b, l;
    int i, j;
    
    *returnSize = 0;
    
    if (!digits || !*digits) {
        return NULL;
    }
    
    n = 1;
    d = digits;
    while (*d) {
        n = n * len[*d - '2'];
        d ++;
    }
    
    *returnSize = n;
    l = d - digits;
    pp = malloc(n * sizeof(char *));
    buff = malloc(l + 1);
    //assert(pp && buff);
    buff[l] = 0;
    
#if 1
    n = 0;
    dfs(digits, 0, buff, pp, &n);
    free(buff);
#else
    buff = malloc(n * (l + 1));
    for (i = 0; i < n; i ++) {
        pp[i] = &buff[i * (l + 1)];
        pp[i][l] = 0;
    }
    
    b = n;
    i = 0;
    d = digits;
    while (*d) {
        b = b / len[*d - '2'];
        j = 0;
        k = b;
        do {
            m = map[*d - '2'];
            while (*m) {
                while (j < k) {
                    pp[j][i] = *m;
                    j ++;
                }
                k += b;
                m ++;
            }
        } while (j < n);
        d ++; i ++;
    }
#endif
    
    return pp;
}


/*
Difficulty:Medium
Total Accepted:163.5K
Total Submissions:474.1K


Companies Amazon Dropbox Google Uber Facebook
Related Topics Backtracking String
Similar Questions 
                
                  
                    Generate Parentheses
                  
                    Combination Sum
                  
                    Binary Watch
*/
