/*
833. Find And Replace in String

To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".


Example 2:

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
"ec" doesn't starts at index 2 in the original S, so we do nothing.


Notes:


	0 <= indexes.length = sources.length = targets.length <= 100
	0 < indexes[i] < S.length <= 1000
	All characters in given inputs are lowercase letters.
*/

typedef struct {
    int i;
    char *s;
    char *t;
} e_t;
int cmp(const void *a, const void *b) {
    const e_t *e1 = a;
    const e_t *e2 = b;
    if (e1->i < e2->i) return -1;
    if (e1->i > e2->i) return 1;
    return 0;
}
char * findReplaceString(char * S, int* indexes, int indexesSize, char ** sources, int sourcesSize, char ** targets, int targetsSize){
    int sz, i, j, l, k;
    char *buff, *newbuff, *p, *o, *s, *t;
    
    e_t e[100];
    for (i = 0; i < indexesSize; i ++) {
        e[i].i = indexes[i];
        e[i].s = sources[i];
        e[i].t = targets[i];
    }
    
    qsort(e, indexesSize, sizeof(*e), cmp);
    
    sz = 1000;
    buff = malloc(sz * sizeof(char));
    //assert(buff);
    
    o = S;
    p = buff;
    p[0] = 0;
    
    for (i = 0; i < indexesSize; i ++) {
        j = e[i].i;
        l = j - (o - S);
        if (l > 0) {
            if (p - buff + l >= sz) {
                sz *= 2;
                newbuff = realloc(buff, sz * sizeof(char));
                //assert(newbuff);
                p = &newbuff[p - buff];
                buff = newbuff;
            }
            strncpy(p, o, l);
            o += l;
            p += l;
            p[0] = 0;   // add null
        }
        s = e[i].s;
        l = strlen(s);
        t = e[i].t;
        if (!strncmp(o, s, l)) {
            k = strlen(t);
            if (p - buff + k >= sz) {
                sz *= 2;
                newbuff = realloc(buff, sz * sizeof(char));
                //assert(newbuff);
                p = &newbuff[p - buff];
                buff = newbuff;
            }
            strcat(p, t);
            o += l;
            p += k;
        }
    }
    
    l = strlen(S) - (o - S);
    if (l > 0) {
        if (p - buff + l >= sz) {
            sz *= 2;
            newbuff = realloc(buff, sz * sizeof(char));
            //assert(newbuff);
            p = &newbuff[p - buff];
            buff = newbuff;
        }
        strcat(p, o);
    }
    
    return buff;
}


/*
Difficulty:Medium


*/
