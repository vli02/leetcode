/*
336. Palindrome Pairs

Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.



    Example 1:
    Given words = ["bat", "tab", "cat"]
    Return [[0, 1], [1, 0]]
    The palindromes are ["battab", "tabbat"]


    Example 2:
    Given words = ["abcd", "dcba", "lls", "s", "sssll"]
    Return [[0, 1], [1, 0], [3, 2], [2, 4]]
    The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct node_s {
    struct node_s *child[26];
    int idx;
    int *list;
    int lsz;
    int ln;
} node_t;
void trie_free(node_t *node) {
    int i;
    if (!node) return;
    for (i = 0; i < 26; i ++) {
        trie_free(node->child[i]);
    }
    if (node->list) free(node->list);
    free(node);
}
int is_palindrome(char *s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i ++;
        j --;
    }
    return 1;
}
void add2list(node_t *node, int idx) {
    if (node->lsz == node->ln) {
        node->lsz = !node->lsz ? 10 : node->lsz * 2;
        node->list = realloc(node->list, node->lsz * sizeof(int));
        //assert(node->list);
    }
    node->list[node->ln ++] = idx;
}
void add2p(int ***p, int *psz, int *pn, int i, int j) {
    int *pair = malloc(2 * sizeof(int));
    //assert(pair);
    pair[0] = i;
    pair[1] = j;
    
    if (*psz == *pn) {
        *psz = !*psz ? 10 : *psz * 2;
        *p = realloc(*p, (*psz) * sizeof(int *));
        //assert(*p);
    }
    (*p)[(*pn) ++] = pair;
}
void trie_add(node_t *node, char *s, int idx) {
    int i, k, l;
    node_t *child;
    
    l = strlen(s);
    for (i = l - 1; i >= 0; i --) {
        if (is_palindrome(s, 0, i)) {  // the rest form a palindrome
            add2list(node, idx);
        }
        k = s[i] - 'a';
        child = node->child[k];
        if (!child) {
            child = calloc(1, sizeof(node_t));
            //assert(child);
            node->child[k] = child;
        }
        node = child;
    }
    node->idx = idx;  // mark the end of the word
}
void trie_search(node_t *node, char *s, int l, int idx, int ***p, int *psz, int *pn) {
    int i, k;
    for (i = 0; i < l; i ++) {
        if (node->idx && node->idx != idx && is_palindrome(s, i, l - 1)) {
            add2p(p, psz, pn, idx - 1, node->idx - 1);
        }
        node = node->child[s[i] - 'a'];
        if (!node) return;
    }
    if (node->idx && node->idx != idx) {  // both words end and match
        add2p(p, psz, pn, idx - 1, node->idx - 1);
    }
    for (i = 0; i < node->ln; i ++) {  // the rest of words
        k = node->list[i];
        if (k != idx) {
            add2p(p, psz, pn, idx - 1, k - 1);
        }
    }
}
int** palindromePairs(char** words, int wordsSize, int** columnSizes, int* returnSize) {
    int **p, psz, pn;
    int i, j;
    node_t *root;
    char *s;
    
    root = calloc(1, sizeof(node_t));
    //assert(root);
    
    // build the trie
    for (i = 0; i < wordsSize; i ++) {
        trie_add(root, words[i], i + 1);
    }
    
    psz = 100;
    pn = 0;
    p = malloc(psz * sizeof(int *));
    //assert(p);
    
    // search the trie
    for (i = 0; i < wordsSize; i ++) {
        s = words[i];
        trie_search(root, s, strlen(s), i + 1, &p, &psz, &pn);
    }
    
    trie_free(root);
    
    if (pn) {
        *columnSizes = malloc(pn * sizeof(int));
        //assert(*columnSizes);
        for (i = 0; i < pn; i ++) {
            (*columnSizes)[i] = 2;
        }
    } else {
        free(p);
        p = NULL;
    }
    
    *returnSize = pn;
    return p;
}


/*
Difficulty:Hard
Total Accepted:26.9K
Total Submissions:103K


Companies Google Airbnb
Related Topics Hash Table String Trie
Similar Questions 
                
                  
                    Longest Palindromic Substring
                  
                    Shortest Palindrome
*/
