/*
411. Minimum Unique Word Abbreviation

A string such as "word" contains the following abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary. 

Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

Note:

In the case of multiple answers as shown in the second example below, you may return any one of them.
Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.



Examples:
"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").
*/

int match(int mask, char *target, int l, char **dict, int sz) {
    int i, j, r;
    char *s;
    for (i = 0; i < sz; i ++) {
        s = dict[i];
        if (l == strlen(s)) {
            r = 0;
            for (j = 0; !r && j < l; j ++) {
                if (!(mask & (1 << j)) && target[j] != s[j]) {
                    r = 1;
                }
            }
            if (!r) return 0;
        }
    }
    return 1;
}
void abbrmatch(int mask, int d, int x, int l, char *buff, int *len, char *target, char **dict, int sz) {
    char tmp[32];
    int i, j, k, n;
    if (d == 0) {
        // match
        if (match(mask, target, l, dict, sz)) {
            // make buff
            j = k = n = 0;
            for (i = 0; i < l; i ++) {
                if (mask & (1 << i)) {
                    k ++;
                } else {
                    if (k) {
                        j += sprintf(&tmp[j], "%d", k);
                        n ++;
                        k = 0;
                    }
                    tmp[j ++] = target[i];
                    n ++;
                }
            }
            if (k) {
                j += sprintf(&tmp[j], "%d", k);
                n ++;
                k = 0;
            }
            tmp[j] = 0;
            if (!*len || *len > n) {
                *len = n;
                strcpy(buff, tmp);
            }
        }
    } else {
        // abbr
        for (i = x; i < l; i ++) {
            if (!(mask & (1 << i))) {
                mask |= (1 << i);
                abbrmatch(mask, d - 1, i + 1, l, buff, len, target, dict, sz);
                mask &= ~(1 << i);
            }
        }
    }
}
char* minAbbreviation(char* target, char** dictionary, int dictionarySize) {
    char *p, buff[32];
    int len, mask;
    int k, l;
    k = l = strlen(target);
    mask = len = 0;
    while (!len && k >= 0) {
        abbrmatch(mask, k, 0, l, buff, &len, target, dictionary, dictionarySize);
        k --;
    }
    if (len) {
        p = malloc(32 * sizeof(char));
        //assert(p);
        strcpy(p, buff);
    } else {
        p = NULL;
    }
    return p;
}


/*
Difficulty:Hard
Total Accepted:5.4K
Total Submissions:16.3K


Companies Google
Related Topics Backtracking Bit Manipulation
Similar Questions 
                
                  
                    Generalized Abbreviation
                  
                    Valid Word Abbreviation
                  
                    Word Abbreviation
*/
