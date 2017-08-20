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

int one_diff(char *a, char *b) {
    int diff = 0;
    while (*a && diff <= 1) {
        diff += (*a != *b) ? 1 : 0;
        a ++; b ++;
    }
    return diff == 1 ? 1 : 0;
}
int bfs(char **q1, char **q2, char *end, char **dict, int sz, int *v, char **buff) {
    int i, j, d;
    int q1n, q2n;
    char *a, *b, **tmp;
    
    d = 1;
    q1n = 1;
    q2n = 0;
    do {
        for (i = 0; i < q1n; i ++) {
            a = q1[i];
            for (j = 0; j < sz; j ++) {
                if (v[j]) continue;
                b = dict[j];
                if (one_diff(a, b)) {
                    if (!strcmp(b, end)) {  // done!
                        return d;
                    }
                    v[j] = 1;
                    q2[q2n ++] = b;
                }
            }
        }
        tmp = q1;  // switch queues
        q1 = q2;
        q2 = tmp;
        q1n = q2n;
        q2n = 0;
        d ++;
    } while (q1n);
    
    return -1;
}
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int *visited, i, n = 0;
    char **buff, **q1, **q2;
​
    visited = calloc(wordListSize, sizeof(int));
    buff = malloc(wordListSize * sizeof(char *));
    q1 = malloc(wordListSize * 2 * sizeof(char *));
    //assert(visited && buff && q1);
    q2 = &q1[wordListSize];
    
    q1[0] = beginWord;
    
    n = bfs(q1, q2, endWord, wordList, wordListSize, visited, buff);
    
    free(visited);
    free(buff);
    free(q1);
    
    return n + 1;
}


/*
Difficulty:Medium
Total Accepted:128.8K
Total Submissions:664.1K


Companies Amazon LinkedIn Snapchat Facebook Yelp

*/
