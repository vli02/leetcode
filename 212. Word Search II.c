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
#ifndef DUMP
#define DUMP() do { } while (0)
#endif
#define IDX(I, J) ((I) * colsz + (J))
const int offset[][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int cmp(const void *a, const void *b) {
    const char *s1 = a, *s2 = b;
    while (*s1 && *s2 && *s1 == *s2) {
        s1 ++; s2 ++;
    }
    return *s1 - *s2;
}
int search(int *visited, char **board, int i, int j, int rowsz, int colsz, char *str, int d, int *e) {
    int r, c, k;
    
    if (*e < d) *e = d;
    
    if (board[i][j] != str[d]) return 0;
    
    if (!str[d + 1]) return 1;
    
    visited[IDX(i, j)] = 1;
    
    for (k = 0; k < 4; k ++) {
        r = i + offset[k][0];
        c = j + offset[k][1];
        if (r >= 0 && r < rowsz &&
            c >= 0 && c < colsz &&
            visited[IDX(r, c)] == 0) {
            if (search(visited, board, r, c, rowsz, colsz, str, d + 1, e)) return 1;
        }
    }
    
    visited[IDX(i, j)] = 0;
    
    return 0;
}
int skip(char **x, int *l, int xp, char **p, int n, char *str) {
    int i;
    for (i = 0; i < xp; i ++) {
        if (!strncmp(x[i], str, l[i] + 1)) return 1;
    }
    for (i = 0; i < n; i ++) {
        if (!strcmp(p[i], str)) return 1;
    }
    return 0;
}
char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {
    int i, j, k, f, *visited, *l, e, xp = 0;
    char *str, **p, **x;
    
    *returnSize = 0;
    
    visited = malloc(boardRowSize * boardColSize * sizeof(int));
    p = malloc(wordsSize * sizeof(char *));
    x = malloc(wordsSize * sizeof(char *));
    l = malloc(wordsSize * sizeof(int));
    //assert(visited && p && x && l);
    
    //qsort(words, wordsSize, sizeof(char *), cmp);
    //DUMP();
    
    for (k = 0; k < wordsSize; k ++) {
        str = words[k];
        if (skip(x, l, xp, p, *returnSize, str)) continue;
        f = 0; e = 0;
        for (i = 0; !f && i < boardRowSize; i ++) {
            for (j = 0; !f && j < boardColSize; j ++) {
                memset(visited, 0, boardRowSize * boardColSize * sizeof(int));
                f = search(visited, board, i, j, boardRowSize, boardColSize, str, 0, &e);
                if (f) {
                    //printf("%2d: %s\n", *returnSize, str);
                    p[*returnSize] = str;
                    (*returnSize) ++;
                }
            }
        }
        if (!f) {
            //printf("%s, %d\n", str, e);
            x[xp   ] = str;
            l[xp ++] = e;
        }
    }
    
    free(visited);
    free(x);
    free(l);
    
    return p;
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
