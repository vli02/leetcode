/*
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:


Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.



For example,


Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]


As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.



Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.




UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

typedef struct {
    char **q;
    int n;
} q_t;
int one_diff(char *a, char *b) {
    int diff = 0;
    while (*a && diff <= 1) {
        diff += (*a != *b) ? 1 : 0;
        a ++; b ++;
    }
    return diff == 1 ? 1 : 0;
}
int bfs(q_t *q1, q_t *q2, char *end, char **dict, int sz, int *v) {
    int i, d;
    char *a, *b;
    q_t *tmp;
    
    d = 1;
    while (q1->n) {
        while (q1->n) {
            a = q1->q[-- q1->n];
            for (i = 0; i < sz; i ++) {
                if (v[i]) continue;
                b = dict[i];
                if (one_diff(a, b)) {
                    if (!strcmp(b, end)) {  // done!
                        return d;
                    }
                    v[i] = 1;
                    q2->q[q2->n ++] = b;
                }
            }
        }
        tmp = q1;  // switch queues
        q1 = q2;
        q2 = tmp;
        d ++;
    }
    
    return -1;
}
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int *visited, i, n = 0;
    q_t q1 = { 0 }, q2 = { 0 };
    
    visited = calloc(wordListSize, sizeof(int));
    q1.q = malloc(wordListSize * 2 * sizeof(char *));
    //assert(visited && q1);
    q2.q = &q1.q[wordListSize];
    
    q1.q[q1.n ++] = beginWord;  // initialize q1
    
    n = bfs(&q1, &q2, endWord, wordList, wordListSize, visited);
    
    free(visited);
    free(q1.q);
    
    return n + 1;
}

/*
Difficulty:Medium
Total Accepted:128.8K
Total Submissions:664.1K


Companies Amazon LinkedIn Snapchat Facebook Yelp

*/
