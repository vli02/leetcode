/*
269. Alien Dictionary

There is a new alien language which uses the latin alphabet. 
However, the order among letters are unknown to you. 
You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.



Example 1:
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]



The correct order is: "wertf".


Example 2:
Given the following words in dictionary,
[
  "z",
  "x"
]



The correct order is: "zx".


Example 3:
Given the following words in dictionary,
[
  "z",
  "x",
  "z"
]



The order is invalid, so return "".

Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

typedef struct node_s {
    int key;
    int entry_cnt;
    struct node_s *child[26];
} node_t;
int has_cycle(node_t *node, int visited, int no_cycle) {
    int i;
    node_t *p;
    
    if (no_cycle & (1 << node->key)) return 0;
    if (visited  & (1 << node->key)) return 1;
    
    visited |=  (1 << node->key);
    
    for (i = 0; i < 26; i ++) {
        p = node->child[i];
        if (p && has_cycle(p, visited, no_cycle)) {
            return 1;
        }
    }
    
    //visited  &= ~(1 << node->key);
    no_cycle |=  (1 << node->key);  // done with this node
    
    return 0;
}
void make_buff(node_t *node, char *buff, int *l) {
    int i;
    node_t *p;
    
    for (i = 0; i < 26; i ++) {
        p = node->child[i];
        if (p && p->entry_cnt > 0) {
            p->entry_cnt --;
            if (p->entry_cnt == 0) {
                buff[(*l) ++] = 'a' + p->key - 1;
                make_buff(p, buff, l);
            }
        }
    }
}
char* alienOrder(char** words, int wordsSize) {
    node_t node[26] = { 0 };
    node_t root = { 0 };
    node_t *p1, *p2;
    int visited = 0;
    int no_cycle = 0;
    char *buff;
    
    int i, j, k, l = 0;
    char *s1, *s2, c1, c2;
    
    buff = calloc(27, sizeof(char)); // include a null terminator
    //assert(buff);
    
    root.key = 30;
    root.entry_cnt = 1;

    // build prefix tree
    for (i = 1; i < wordsSize; i ++) {
        s1 = words[i - 1];
        s2 = words[i];
        j = 0;
        while (s1[j] && s1[j] == s2[j]) {
            j ++;
        }
        if (s1[j]) {
            if (!s2[j]) goto done; // "abc", "ab"
            c1 = s1[j] - 'a';
            c2 = s2[j] - 'a';
            p1 = &node[c1];
            p2 = &node[c2];
            if (!p1->child[c2]) {  // make c2 as a child of c1
                p1->child[c2] = p2;
                p2->key = c2 + 1;
                p2->entry_cnt ++;
                if (p1->key == 0) {  // put c1 into the tree
                    root.child[c1] = p1;
                    p1->key = c1 + 1;
                    p1->entry_cnt ++;
                }
            }
        }
    }
    
    if (has_cycle(&root, visited, no_cycle)) goto done;
    
    // put the rest of characters into the tree
    for (i = 0; i < wordsSize; i ++) {
        s1 = words[i];
        j = 0;
        while (s1[j]) {
            c1 = s1[j] - 'a';
            p1 = &node[c1];
            if (p1->key == 0) {
                root.child[c1] = p1;
                p1->key = c1 + 1;
                p1->entry_cnt = 1;
            }
            j ++;
        }
    }
    
    make_buff(&root, buff, &l);
    
done:
    return buff;
}


/*
Difficulty:Hard
Total Accepted:27.3K
Total Submissions:114K


Companies Google Airbnb Facebook Twitter Snapchat Pocket Gems
Related Topics Graph Topological Sort
Similar Questions 
                
                  
                    Course Schedule II
*/
