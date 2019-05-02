/*
648. Replace Words

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.




Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.



You need to output the sentence after the replacement.



Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"




Note:

The input will only have lower-case letters.
 1 <= dict words number <= 1000 
 1 <= sentence words number <= 1000  
 1 <= root length <= 100 
 1 <= sentence words length <= 1000
*/

typedef struct trie_s {
    struct trie_s *prev;
    struct trie_s *child[26];
    char *s;
} trie_t;
void add2trie(trie_t *node, char *s, trie_t **link_p) {
    char c, *str = s;
    trie_t *child;
    while (c = *(s ++)) {
        child = node->child[c - 'a'];
        if (!child) {
            child = calloc(1, sizeof(trie_t));
            //assert(child);
            child->prev = *link_p;
            *link_p = child;
            node->child[c - 'a'] = child;
        } else if (child->s) {
            return;
        }
        node = child;
    }
    node->s = str;
}
void trie_free(trie_t *link) {
    trie_t *prev;
    while (link) {
        prev = link->prev;
        free(link);     // oj fails here!!!
        link = prev;
    }
}
trie_t *trie_search(trie_t *node, char *str) {
    char c;
    while (c = *(str ++)) {
        node = node->child[c - 'a'];
        if (!node || node->s) return node;
    }
    return NULL;
}
char* replaceWords(char** dict, int dictSize, char* sentence) {
    trie_t root = { 0 }, *node, *link = NULL;
    char *p, *substr;
    
    // build a trie
    while (dictSize) {
        add2trie(&root, dict[-- dictSize], &link);
    }
    
    p = malloc((strlen(sentence) + 1) * sizeof(char));
    //assert(p);
    p[0] = 0;
    
    // search each word in the trie
    while (*sentence) {
        substr = sentence;       // start of a word
        while (*sentence && *sentence != ' ') {
            sentence ++;
        }
        if (*sentence == ' ') {
            *sentence = 0;
            sentence ++;
        }
        // skip blank spaces
        while (*sentence == ' ') sentence ++;
        
        // search
        node = trie_search(&root, substr);
        if (!node) {
            strcat(p, substr);
        } else {
            strcat(p, node->s);
        }
        strcat(p, " ");
    }
    p[strlen(p) - 1] = 0;
    
    trie_free(link);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:8.4K
Total Submissions:17.7K


Companies Uber
Related Topics Hash Table Trie
Similar Questions 
                
                  
                    Implement Trie (Prefix Tree)
*/
