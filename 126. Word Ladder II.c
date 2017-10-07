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
typedef struct {
    node_t **q;
    int n;
} q_t;
typedef struct {
    char ***p;
    int psz;
    int pn;
    int d;
} res_t;
void add2res(res_t *res, char **buff, int l) {
    int sz = l * sizeof(char *);
    char **p = malloc(sz);
    //assert(p);
    memcpy(p, buff, sz);
    
    if (res->psz == res->pn) {
        res->psz = !res->psz ? 10 : res->psz * 2;
        res->p = realloc(res->p, res->psz * sizeof(char **));
        //assert(res->p);
    }
    res->p[res->pn ++] = p;
}
int one_diff(char *a, char *b) {
    int diff = 0;
    while (*a && diff <= 1) {
        diff += (*a != *b) ? 1 : 0;
        a ++; b ++;
    }
    return diff == 1 ? 1 : 0;
}
void add2prev(node_t *b, int idx) {
    if (b->psz == b->pn) {
        b->psz = !b->psz ? 5 : b->psz * 2;
        b->p = realloc(b->p, b->psz * sizeof(int));
        //assert(b->p);
    }
    b->p[b->pn ++] = idx;
}
void bt(node_t *nodes, node_t *n, char **buff, res_t *res, int l, int d) {
    int i;
    
    if (n->idx == -1) {  // done
        buff[d] = n->s;
        add2res(res, buff, l);
        return;
    }
    buff[d] = n->s;
    for (i = 0; i < n->pn; i ++) {
        bt(nodes, &nodes[n->p[i]], buff, res, l, d - 1);
    }
}
void bfs(q_t *q1, q_t *q2, node_t *nodes, int sz, char *end, int *visited, res_t *res) {
    node_t *done, *a, *b;
    q_t *q3;
    int d = 1, i;
    
    char **buff;
    
    done = NULL;
    while (q1->n && !done) {
        while (q1->n) {
            a = q1->q[-- q1->n];
            for (i = 0; i < sz; i ++) {
                if (visited[i] > 1) continue;
                b = &nodes[i];
                if (one_diff(a->s, b->s)) {
                    if (!done && !strcmp(b->s, end)) done = b;
                    if (!visited[i]) {
                        q2->q[q2->n ++] = b;
                        visited[i] = 1;     // 1 means it is just added into q2
                    }
                    add2prev(b, a->idx);    // add a as a preceeding node of b
                }
            }
        }
        for (i = 0; !done && i < q2->n; i ++) {
            b = q2->q[i];
            visited[b->idx] ++;  // done for this layer, make them all 2
        }
        q3 = q1;
        q1 = q2;
        q2 = q3;
        d ++;
    }
    
    if (!done) return;
    
    res->d = d;
    
    // backtrace done node to make buff
    buff = malloc(d * sizeof(char *));
    //assert(buff);
    
    bt(nodes, done, buff, res, d, d - 1);
    
    free(buff);
}
char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int** columnSizes, int* returnSize) {
    int *visited, i;
    node_t *n, *nodes;
    q_t q1 = { 0 }, q2 = { 0 };
    res_t res = { 0 };
    
    visited = calloc(wordListSize, sizeof(int));
    nodes = malloc((wordListSize + 1) * sizeof(node_t));
    q1.q = malloc(wordListSize * 2 * sizeof(node_t *));
    //assert(visited && nodes && q1.q);
    q2.q = &q1.q[wordListSize];
    
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
    
    q1.q[q1.n ++] = &nodes[0];
    
    bfs(&q1, &q2, &nodes[1], wordListSize, endWord, visited, &res);
    
    free(visited);
    free(q1.q);
    for (i = 1; i <= wordListSize; i ++) {
        n = &nodes[i];
        if (n->p) free(n->p);
    }
    free(nodes);
    
    if (res.pn) {
        *columnSizes = malloc(res.pn * sizeof(int));
        //assert(*columnSizes);
    }
    for (i = 0; i < res.pn; i ++) {
        (*columnSizes)[i] = res.d;
    }
    
    *returnSize = res.pn;
    
    return res.p;
}

/*
Difficulty:Hard
Total Accepted:69.4K
Total Submissions:490.1K


Companies Amazon Yelp
Related Topics Array Backtracking Breadth-first Search String

*/
