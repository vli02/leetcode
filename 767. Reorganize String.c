/*
767. Reorganize String

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"


Example 2:

Input: S = "aaab"
Output: ""


Note:


	S will consist of lowercase letters and have length in range [1, 500].
*/

typedef struct {
    char c;
    int n;
} e_t;
int cmp(const void *a, const void *b) {
    e_t *p1 = a;
    e_t *p2 = b;
    return (p1->n < p2->n) ? 1 :
           (p1->n > p2->n) ? -1 : 0;
}
char * reorganizeString(char * S){
    e_t e[27] = { 0 }, x;
    char c, *p, *buff;
    int i, t, sz;
    
    buff = malloc(501);
    //assert(buff);
    buff[0] = 0;
    
    while (c = *(S ++)) {
        i = c - 'a';
        e[i].c = c;
        e[i].n ++;
    }
    
    qsort(&e, 26, sizeof(e_t), cmp);
    
    for (i = 25; i >= 0; i --) if (e[i].n > 0) break;
    
    sz = i + 1;
    
    p = buff;
    *p = 0;
    
    while (e[0].n > 0) {
        *p = e[0].c;
        p ++;
        e[0].n --;
        
        if (e[1].n > 0) {
            *p = e[1].c;
            p ++;
            e[1].n --;
        } else if (e[0].n > 0) {
            buff[0] = 0;
            break;
        }
        
        qsort(&e, sz, sizeof(e_t), cmp);    // use heap to optimze
    }
    
    *p = 0;
    return buff;
}    


/*
Difficulty:Medium


*/
