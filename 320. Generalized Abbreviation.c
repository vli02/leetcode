/*
320. Generalized Abbreviation

Write a function to generate the generalized abbreviations of a word.


    Example:

Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
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
void add2res(res_t *res, char *buff) {
    if (!res->sz) {
        res->sz = 100;
        res->p = malloc(res->sz * sizeof(char *));
        //assert(res->p);
        res->n = 0;
    } else if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = buff;
}
char *abbr(char *word, int l, int *mask) {
    int i, j, x;
    char *buff;
    // generate the abbr
    buff = malloc((l + 1) * sizeof(char));
    //assert(buff);
    j = x = 0;
    for (i = 0; i < l; i ++) {
        if (mask[i]) {
            x ++;
        } else {
            if (x) {
                j += sprintf(&buff[j], "%d", x);
                x = 0;
            }
            buff[j ++] = word[i];
        }
    }
    if (x) {
        j += sprintf(&buff[j], "%d", x);
        x = 0;
    }
    buff[j] = 0;
    return buff;
}
void dfs(char *word, int l, int start, int k, int *mask, res_t *res) {
    int i;
    
    if (k == 0) {
        add2res(res, abbr(word, l, mask));
        return;
    }
    
    for (i = start; i < l; i ++) {
        mask[i] = 1;
        dfs(word, l, i + 1, k - 1, mask, res);
        mask[i] = 0;
    }
}
char** generateAbbreviations(char* word, int* returnSize) {
    int i, l;
    int *mask;
    
    res_t res = { 0 };
    
    *returnSize = 0;
    if (!word) return NULL;
    
    l = strlen(word);
    mask = calloc(l, sizeof(int));
    //assert(mask);
    
    for (i = 0; i <= l; i ++) {
        dfs(word, l, 0, i, mask, &res);
    }
    
    *returnSize = res.n;
    
    return res.p;
}

/*
Difficulty:Medium
Total Accepted:22.8K
Total Submissions:50.8K


Companies Google
Related Topics Backtracking Bit Manipulation
Similar Questions 
                
                  
                    Subsets
                  
                    Unique Word Abbreviation
                  
                    Minimum Unique Word Abbreviation
*/
