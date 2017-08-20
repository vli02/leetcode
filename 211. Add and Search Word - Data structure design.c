/*
211. Add and Search Word - Data structure design

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)



search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.


For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true



Note:
You may assume that all words are consist of lowercase letters a-z.


click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/

typedef struct dict_s {
    int is_leaf;
    struct dict_s *child[26];
} WordDictionary;
​
/** Initialize your data structure here. */
WordDictionary* wordDictionaryCreate() {
    WordDictionary *obj;
    
    obj  = calloc(1, sizeof(WordDictionary));
    //assert(obj);
    
    return obj;
}
​
/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    int k;
    
    if (!word || !*word) return;
    
    while (*word) {
        k = *word - 'a';
        if (!obj->child[k]) {
            obj->child[k] = calloc(1, sizeof(WordDictionary));
            //assert(obj->child[k]);
        }
        obj = obj->child[k];
        word ++;
    }
    obj->is_leaf = 1;
}
​
/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char* word) {
    int k;
    
    while (obj && *word) {
        if (*word == '.') {
            for (k = 0; k < 26; k ++) {
                if (wordDictionarySearch(obj->child[k], word + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            k = *word - 'a';
            obj = obj->child[k];
            word ++;
        }
    }
    
    return (obj && obj->is_leaf) ? true : false;
}
​
void wordDictionaryFree(WordDictionary* obj) {
    int i;
    for (i = 0; i < 26; i ++) {
        if (obj->child[i]) wordDictionaryFree(obj->child[i]);
    }
    free(obj);
}
​
/**
 * Your WordDictionary struct will be instantiated and called as such:
 * struct WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:56.8K
Total Submissions:249.4K


Companies Facebook
Related Topics Backtracking Trie Design
Similar Questions 
                
                  
                    Implement Trie (Prefix Tree)
*/
