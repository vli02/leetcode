/*
49. Group Anagrams

Given an array of strings, group anagrams together.


For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note: All inputs will be in lower-case.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct res_s {
    char ***p;
    int *csz;
    int *cl;
    int sz;
    int n;
} res_t;
typedef struct e_s {
    char *key;
    int k;
    struct e_s *shadow;
} e_t;
#define HSZ 1021

int new_buff(res_t *res) {
    int k, buffsz = 10;
    char **buff = malloc(buffsz * sizeof(char *));
    //assert(buff);
    if (res->sz == 0) {
        res->sz = 100;
        res->p = malloc(res->sz * sizeof(char **));
        res->csz = malloc(res->sz * sizeof(int));
        res->cl = malloc(res->sz * sizeof(int));
        //assert(res->p && res->csz && res->cl);
    } else if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char **));
        res->csz = realloc(res->csz, res->sz * sizeof(int));
        res->cl = realloc(res->cl, res->sz * sizeof(int));
        //assert(res->p && res->csz && res->cl);
    }
    k = res->n ++;
    res->p[k] = buff;
    res->csz[k] = buffsz;
    res->cl[k] = 0;
    
    return k;
}
void add2res(res_t *res, int k, char *str) {
    if (res->csz[k] == res->cl[k]) {
        res->csz[k] *= 2;
        res->p[k] = realloc(res->p[k], res->csz[k] * sizeof(char **));
        //assert(res->p[k]);
    }
    res->p[k][res->cl[k] ++] = str;
}
int cmp(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}
int hash_code(char *key) {
    int h = 5381;
    while (*key) {
        h = h * 33 + *key;
        key ++;
    }
    return h;
}
int lookup(e_t **ht, int code, char *key) {
    e_t *e = ht[code % HSZ];
    while (e && strcmp(e->key, key)) {
        e = e->shadow;
    }
    if (e) return e->k;
    return -1;
}
void insert(e_t **ht, int code, char *key, int k) {
    e_t *e = malloc(sizeof(e_t));
    //assert(e);
    e->key = key;
    e->k = k;
    e->shadow = ht[code % HSZ];
    ht[code % HSZ] = e;
}
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    res_t res = { 0 };
    e_t *ebuff[HSZ * 2] = { 0 };
    e_t **ht = &ebuff[HSZ];

    int i, k, code;
    char *str, *key;
    
    for (i = 0; i < strsSize; i ++) {
        str = strs[i];
        key = strdup(str);
        qsort(key, strlen(key), sizeof(char), cmp);
        code = hash_code(key);
        k = lookup(ht, code, key);
        if (k == -1) {
            k = new_buff(&res);
            insert(ht, code, key, k);
        } else {
            free(key);
        }
        add2res(&res, k, str);
    }
    
    // TODO: clean hash table
    
    free(res.csz);
    *columnSizes = res.cl;
    *returnSize = res.n;
    return res.p;
}

/*
Difficulty:Medium
Total Accepted:144.2K
Total Submissions:415.6K


Companies Amazon Bloomberg Uber Facebook Yelp
Related Topics Hash Table String
Similar Questions 
                
                  
                    Valid Anagram
                  
                    Group Shifted Strings
*/
