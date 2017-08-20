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
void abbr(char *word, int l, int start, int k, int *mask, char ***p, int *sz, int *n) {
    int i, j, x;
    char *buff;
    
    if (k == 0) {
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
        if (*n == *sz) {
            (*sz) *= 2;
            (*p) = realloc(*p, (*sz) * sizeof(char *));
            //assert(*p);
        }
        (*p)[*n] = buff;
        (*n) ++;
        return;
    }
    
    for (i = start; i < l; i ++) {
        mask[i] = 1;
        abbr(word, l, i + 1, k - 1, mask, p, sz, n);
        mask[i] = 0;
    }
}
char** generateAbbreviations(char* word, int* returnSize) {
    int i, l;
    int *mask;
​
    int sz, n;
    char **p;
    
    *returnSize = 0;
    if (!word) return NULL;
    
    sz = 100;
    p = malloc(sz * sizeof(char *));
    //assert(p);
​
    n = 0;
    l = strlen(word);
    mask = calloc(l, sizeof(int));
    //assert(mask);
    
    for (i = 0; i <= l; i ++) {
        abbr(word, l, 0, i, mask, &p, &sz, &n);
    }
    
    *returnSize = n;
    
    return p;
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
