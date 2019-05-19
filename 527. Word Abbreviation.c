/*
527. Word Abbreviation

Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.


Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
 If the abbreviation doesn't make the word shorter, then keep it as original.


Example:
Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]




Note: 

 Both n and the length of each word will not exceed 400.
 The length of each word is greater than 1.
 The words consist of lowercase English letters only.
 The return answers should be in the same order as the original array.
*/

typedef struct {
    int idx;
    char *p;
    int len;
    char *s;
} s_t;

int cmp(const void *a, const void *b) {
    const s_t *s1 = a;
    const s_t *s2 = b;
    if (s1->len < s2->len) return -1;
    if (s1->len > s2->len) return 1;
    if (s1->p[s1->len - 1] < s2->p[s2->len - 1]) return -1;
    if (s1->p[s1->len - 1] > s2->p[s2->len - 1]) return 1;
    return strncmp(s1->p, s2->p, s1->len - 1);
}
int cmp2(const void *a, const void *b) {
    const s_t *s1 = a;
    const s_t *s2 = b;
    if (s1->idx < s2->idx) return -1;
    if (s1->idx > s2->idx) return 1;
    return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** wordsAbbreviation(char ** dict, int dictSize, int* returnSize){
    s_t s[401], *a, *b, *c;
    int i, j, k, m, n, prefix;
    
    char **pp;
    
    for (i = 0; i < dictSize; i ++) {
        s[i].idx = i;
        s[i].p = dict[i];
        s[i].len = strlen(dict[i]);
    }
    
    qsort(s, dictSize, sizeof(s[0]), cmp);
    
    for (i = 0; i < dictSize; i ++) {
        b = &s[i];
        if (i > 0) {
            a = &s[i - 1];
            if (a->len != b->len ||
                a->p[a->len - 1] != b->p[b->len - 1]) {
                a = NULL;
            }
        } else a = NULL;
        
        if (i != dictSize - 1) {
            c = &s[i + 1];
            if (c->len != b->len ||
                c->p[c->len - 1] != b->p[b->len - 1]) {
                c = NULL;
            }
        } else c = NULL;
        
        m = n = 0;
        while (m < b->len && (a && b->p[m] == a->p[m])) m ++;
        while (n < b->len && (c && b->p[n] == c->p[n])) n ++;
        prefix = m > n ? m : n;
        
        if (prefix + 3 >= b->len) {
            b->s = strdup(b->p);
        } else {
            b->s = malloc(prefix + 10 + 3);
            //assert(b->s);
            strncpy(b->s, b->p, prefix + 1);
            k = sprintf(&b->s[prefix + 1], "%d", b->len - prefix - 2);
            b->s[prefix + 1 + k] = b->p[b->len - 1];
            b->s[prefix + 1 + k + 1] = 0;
        }
    }
    
    qsort(s, dictSize, sizeof(s[0]), cmp2);
    
    pp = malloc(dictSize * sizeof(char *));
    //assert(pp);
    for (i = 0; i < dictSize; i ++) {
        pp[i] = s[i].s;
    }
    
    *returnSize = dictSize;
    return pp;
}


/*
Difficulty:Hard


*/
