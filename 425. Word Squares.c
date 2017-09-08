/*
425. Word Squares

Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y


Note:

There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.



Example 1:
Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).



Example 2:
Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct node_s {
    int sz;
    int n;
    char **s;
    struct node_s *child[26];
} node_t;
void free_trie(node_t *node) {
    int i;
    if (!node) return;
    for (i = 0; i < 26; i ++) {
        free_trie(node->child[i]);
    }
    free(node->s);
    free(node);
}
void trie_search(node_t *root, char **buff, char *prefix, int d, int l, char ****p, int *psz, int *n) {
    int i, j, k;
    node_t *node, *child;
    char **x;
    
    if (d == l) {  // found one!
        if (*psz == *n) {
            *psz = !*psz ? 10 : *psz * 2;
            *p = realloc(*p, (*psz) * sizeof(char **));
            //assert(*p);
        }
        x = malloc(l * sizeof(char *));
        //assert(x);
        memcpy(x, buff, d * sizeof(char *));
        (*p)[(*n) ++] = x;
        return;
    }
    
    for (i = 0; i < d; i ++) {  // build prefix
        prefix[i] = buff[i][d];
    }
    
    node = root;
    for (i = 0; node && i < d; i ++) {  // trie lookup
        node = node->child[prefix[i] - 'a'];
    }
    
    if (!node) return;
    
    for (i = 0; i < 26; i ++) {
        child = node->child[i];
        if (!child) continue;
        for (j = 0; j < child->n; j ++) {
            buff[d] = child->s[j];
            trie_search(root, buff, prefix, d + 1, l, p, psz, n);
        }
    }
}
void add_word(node_t *p, char *word) {
    if (!p->sz) {
        p->sz = 10;
        p->s = malloc(p->sz * sizeof(char *));
        //assert(p->s);
    } else if (p->sz == p->n) {
        p->sz *= 2;
        p->s = realloc(p->s, p->sz * sizeof(char *));
        //assert(p->s);
    }
    p->s[p->n ++] = word;
}
char*** wordSquares(char** words, int wordsSize, int** columnSizes, int* returnSize) {
    node_t root = { 0 }, *node, *p;
    char *word, *s, c, *prefix, **buff;
    int i, j, k, n, l;
    
    char ***ret = NULL;
    int psz = 0;
    *returnSize = 0;
    
    // build the trie
    for (i = 0; i < wordsSize; i ++) {
        word = s = words[i];
        node = &root;
        while (*s) {
            c = (*s ++) - 'a';
            p = node->child[c];
            if (!p) {
                p = calloc(1, sizeof(node_t));
                //assert(p);
                node->child[c] = p;
            }
            add_word(p, word);
            node = p;
        }
    }
    
    l = strlen(words[0]);
    buff = malloc(l * sizeof(char *));
    prefix = malloc(l * sizeof(char));
    //assert(buff && prefix);
    
    for (i = 0; i < wordsSize; i ++) {
        buff[0] = words[i];
        trie_search(&root, buff, prefix, 1, l, &ret, &psz, returnSize);
    }
    
    if (*returnSize) {
        *columnSizes = malloc(*returnSize * sizeof(int));
        //assert(*columnSize);
        for (i = 0; i < *returnSize; i ++) {
            (*columnSizes)[i] = l;
        }
    }
    
    free(prefix);
    free(buff);
    for (i = 0; i < 26; i ++) {
        free_trie(root.child[i]);
    }
    
    return ret;
}

/*
Difficulty:Hard
Total Accepted:9K
Total Submissions:21.1K


Companies Google
Related Topics Backtracking Trie
Similar Questions 
                
                  
                    Valid Word Square
*/
