/*
212. Word Search II

Given a 2D board and a list of words from the dictionary, find all words in the board.


Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



For example,
Given words = ["oath","pea","eat","rain"] and board = 
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]


Return ["eat","oath"].



Note:
You may assume that all inputs are consist of lowercase letters a-z.


click to show hint.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node_s {
    struct node_s *child[26];
    char *word;
} node_t;

typedef struct {
    char **p;
    int n;
    int sz;
} res_t;

void add2res(res_t *res, char *word) {
    if (res->sz == 0) {
        res->sz = 10;
    } else if (res->sz == res->n) {
        res->sz *= 2;
    }
    res->p = realloc(res->p, res->sz * sizeof(char *));
    //assert(res->p);
    res->p[res->n ++] = word;
}

void add2trie(node_t *node, char *word) {
    node_t *t;
    char *p = word;
    int k;
    while (*p) {
        k = *p - 'a';
        t = node->child[k];
        if (!t) {
            t = calloc(1, sizeof(node_t));
            //assert(t);
            node->child[k] = t;
        }
        node = t;
        p ++;
    }
    node->word = word;
}

void free_trie(node_t *node) {
    int i;
    node_t *t;
    for (i = 0; i < 26; i ++) {
        t = node->child[i];
        if (t) {
            free_trie(t);
        }
    }
    free(node);
}

void dfs(char **board, int rowsz, int colsz, int x, int y, node_t *node, res_t *res) {
    char c;
    node_t *t;
    int i, j, k;
    const int offset[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    
    c = board[x][y];
    
    // already visited
    if (c == '.') return;
    
    t = node->child[c - 'a'];

    // not a match
    if (!t) return;
    
    // found a match
    node = t;
    
    if (node->word) {
        add2res(res, node->word);
        node->word = NULL;          // done with this word
    }
    
    board[x][y] = '.';
    
    for (k = 0; k < 4; k ++) {
        i = x + offset[k][0];
        j = y + offset[k][1];
        
        if (i >= 0 && i < rowsz && j >= 0 && j < colsz) {
            dfs(board, rowsz, colsz, i, j, node, res);
        }
    }
    
    board[x][y] = c;
}

char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {
    res_t res = { 0 };
    node_t *root;
    int i, j;
    
    root = calloc(1, sizeof(node_t));
    //assert(root);
    
    // build trie
    for (i = 0; i < wordsSize; i ++) {
        add2trie(root, words[i]);
    }
    
    // search
    for (i = 0; i < boardRowSize; i ++) {
        for (j = 0; j < boardColSize; j ++) {
            dfs(board, boardRowSize, boardColSize, i, j, root, &res);
        }
    }
    
    // free trie
    free_trie(root);
    
    *returnSize = res.n;
    return res.p;
}

/*
Difficulty:Hard
Total Accepted:47.7K
Total Submissions:203.9K


Companies Microsoft Google Airbnb
Related Topics Backtracking Trie
Similar Questions 
                
                  
                    Word Search
*/
