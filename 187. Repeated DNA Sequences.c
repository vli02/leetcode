/*
187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.


For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct sn {
    //char *s;
    int found;
    unsigned int c;
    struct sn *shadow;
} sn_t;
#define HF 1000
int map[26] = { 0 };
unsigned int code(const char *s) {
    int i, c;
    //c = 5381;
    c = 0;
    for (i = 0; i < 10; i ++) {
    //    c = c * 33 + s[i];
        c = (c << 2) | map[s[i] - 'A'];
    }
    return c;
}
char** findRepeatedDnaSequences(const char* s, int* returnSize) {
    sn_t *patt[HF] = { 0 }, *e, *shadow;
    unsigned int c;
    char **p, *buff;
    const char *x;
    int sz, n, len;
    
    map['A' - 'A'] = 0x0;
    map['C' - 'A'] = 0x1;
    map['G' - 'A'] = 0x2;
    map['T' - 'A'] = 0x3;
    
    sz = 10; n = 0;
    p = malloc(sz * sizeof(char *));
    //assert(p);
    len = strlen(s);
    while (*s && len >= 10) {
        c = code(s);
        e = patt[c % HF];
        while (e && e->c != c) {
            e = e->shadow;
        }
        if (!e) {  // not yet being searched
            e = malloc(sizeof(sn_t));
            //assert(e);
            //e->s = s;
            e->found = 0;
            e->c = c;
            e->shadow = patt[c % HF];  // save in searched table
            patt[c % HF] = e;
        } else if (!e->found) {  // this is a repeated pattern
            e->found = 1;
            if (n == sz) {
                sz *= 2;
                p = realloc(p, sz * sizeof(char *));
                //assert(p);
            }
            buff = malloc(11 * sizeof(char));
            //assert(buff);
            strncpy(buff, s, 10);
            buff[10] = 0;
            p[n ++] = buff;
        }
        s ++; len --;
    }
    
    *returnSize = n;
​
    for (n = 0; n < HF; n ++) {
        e = patt[n];
        while (e) {
            shadow = e->shadow;
            free(e);
            e = shadow;
        }
    }
​
    return p;
}


/*
Difficulty:Medium
Total Accepted:78.5K
Total Submissions:249.6K


Companies LinkedIn
Related Topics Hash Table Bit Manipulation

*/
