/*
126. Word Ladder II

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:


Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.



For example,


Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]


Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]




Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.




UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int idx;
    char *s;
    int *p;
    int psz;
    int pn;
} node_t;
int one_diff(char *a, char *b) {
    int diff = 0;
    while (*a && diff <= 1) {
        diff += (*a != *b) ? 1 : 0;
        a ++; b ++;
    }
    return diff == 1 ? 1 : 0;
}
void bt(node_t *nodes, node_t *n, char **buff, char ****p, int *psz, int *pn, int l, int d) {
    int i;
    
    if (n->idx == -1) {  // done
        buff[d] = n->s;
        if (*psz == *pn) {
            *psz = !*psz ? 10 : *psz * 2;
            *p = realloc(*p, (*psz) * sizeof(char **));
            //assert(*p);
        }
        (*p)[*pn] = malloc(l * sizeof(char *));
        //assert((*p)[*pn]);
        memcpy((*p)[*pn], buff, l * sizeof(char *));
        (*pn) ++;
        return;
    }
    buff[d] = n->s;
    for (i = 0; i < n->pn; i ++) {
        bt(nodes, &nodes[n->p[i]], buff, p, psz, pn, l, d - 1);
    }
}
void bfs(node_t **q1, node_t **q2, node_t *nodes, int sz, char *end, int *visited, int *len, char ****p, int *psz, int *pn) {
    node_t *done, *a, *b, **q3;
    int q1n = 1, q2n = 0;
    int d = 1, i, j;
    
    char **buff;
    
    done = NULL;
    do {
        for (i = 0; i < q1n; i ++) {
            a = q1[i];
            for (j = 0; j < sz; j ++) {
                if (visited[j] > 1) continue;
                b = &nodes[j];
                if (one_diff(a->s, b->s)) {
                    if (!done && !strcmp(b->s, end)) done = b;
                    if (!visited[j]) {
                        q2[q2n ++] = b;
                        visited[j] = 1;  // 1 means it is just added into q2
                    }
                    if (b->psz == b->pn) {
                        b->psz = !b->psz ? 5 : b->psz * 2;
                        b->p = realloc(b->p, b->psz * sizeof(int));
                        //assert(b->p);
                    }
                    b->p[b->pn ++] = a->idx;  // add as a preceeding node
                }
            }
        }
        for (j = 0; !done && j < q2n; j ++) {
            b = q2[j];
            visited[b->idx] ++;  // done for this layer, make them all 2
        }
        q3 = q1;
        q1 = q2;
        q2 = q3;
        q1n = q2n;
        q2n = 0;
        d ++;
    } while (q1n && !done);
    
    if (!done) return;
    
    *len = d;
    
    // backtrace done node to make buff
    buff = malloc(d * sizeof(char *));
    //assert(buff);
    
    bt(nodes, done, buff, p, psz, pn, *len, d - 1);
    
    free(buff);
}
char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int** columnSizes, int* returnSize) {
    int *visited;
    node_t *n, *nodes, **q1, **q2;
    node_t root = { 0 };
    int i, len = 0;
    
    char ***p;
    int psz, pn;
    
    p = NULL;
    psz = pn = 0;
    
    visited = calloc(wordListSize, sizeof(int));
    nodes = malloc((wordListSize + 1) * sizeof(node_t));
    q1 = malloc(wordListSize * 2 * sizeof(node_t *));
    //assert(visited && nodes && q1);
    q2 = &q1[wordListSize];
    
    n = &nodes[0];
    n->idx = -1;
    n->s = beginWord;
    for (i = 0; i < wordListSize; i ++) {
        n = &nodes[i + 1];
        n->idx = i;
        n->s = wordList[i];
        n->p = NULL;
        n->psz = 0;
        n->pn = 0;
    }
    
    q1[0] = &nodes[0];
    
    bfs(q1, q2, &nodes[1], wordListSize, endWord, visited, &len, &p, &psz, &pn);
    
    free(visited);
    free(q1);
    for (i = 1; i <= wordListSize; i ++) {
        n = &nodes[i];
        if (n->p) free(n->p);
    }
    free(nodes);
    
    if (pn) {
        *columnSizes = malloc(pn * sizeof(int));
        //assert(*columnSizes);
    }
    for (i = 0; i < pn; i ++) {
        (*columnSizes)[i] = len;
    }
    
    *returnSize = pn;
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:69.4K
Total Submissions:490.1K


Companies Amazon Yelp
Related Topics Array Backtracking Breadth-first Search String

*/
