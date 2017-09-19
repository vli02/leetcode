/*
249. Group Shifted Strings

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct res_s {
    char ***p;
    int *l;
    int n;
} res_t;
typedef struct e_s {
    int k;
    char *key;
    struct e_s *shadow;
} e_t;
#define HSZ 1021
int new_buff(res_t *res, int sz) {
    int n;
    char **buff = malloc(sz * sizeof(char *));  // more than enough
    //assert(buff);
    res->p[res->n] = buff;
    res->l[res->n] = 0;
    n = res->n;
    res->n ++;
    return n;
}
void add2res(res_t *res, int k, char *str) {
    res->p[k][res->l[k]] = str;
    res->l[k] ++;
}
int hash_code(char *key) {
    int h = 5381;
    while (*key) {
        h = h * 33 + *key;
        key ++;
    }
    return h;
}
void normalize_key(char *key) {
    int offset = *key - 'a';
    while (*key) {
        *key -= offset;
        if (*key < 'a') *key += 26;
        key ++;
    }
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
    e->k = k;
    e->key = key;
    e->shadow = ht[code % HSZ];
    ht[code % HSZ] = e;
}
char*** groupStrings(char** strings, int stringsSize, int** columnSizes, int* returnSize) {
    int i, k, code;
    char *str, *key;
    res_t res;
    e_t *e, *ebuff[HSZ * 2] = { 0 };
    e_t **ht = &ebuff[HSZ];
    
    res.p = malloc(stringsSize * sizeof(char **)); // enough
    res.l = malloc(stringsSize * sizeof(int));
    //assert(res.p && res.l);
    res.n = 0;
    
    for (i = 0; i < stringsSize; i ++) {
        str = strings[i];
        key = strdup(str);
        normalize_key(key);
        code = hash_code(key);
        k = lookup(ht, code, key);
        if (k == -1) {
            k = new_buff(&res, stringsSize);
            insert(ht, code, key, k);
        } else {
            free(key);
        }
        add2res(&res, k, str);
    }
    
    // TODO: clean up hash table
    
    *returnSize = res.n;
    *columnSizes = res.l;
    return res.p;
}


/*
Difficulty:Medium
Total Accepted:25.7K
Total Submissions:62.1K


Companies Google Uber
Related Topics Hash Table String
Similar Questions 
                
                  
                    Group Anagrams
*/
