/*
244. Shortest Word Distance II

This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].



Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.



Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

typedef struct {
    char **words;
    int sz;
    int *buff;
} WordDistance;
​
WordDistance* wordDistanceCreate(char** words, int wordsSize) {
    WordDistance *obj = malloc(sizeof(WordDistance));
    //assert(obj);
    obj->words = words;
    obj->sz = wordsSize;
    obj->buff = malloc(wordsSize * 2 * sizeof(int));
    //assert(obj->buff);
​
    return obj;
}
​
int wordDistanceShortest(WordDistance* obj, char* word1, char* word2) {
    int *p1, *p2, l1, l2;
    int i, j, d, m;
    char *w;
    
    p1 = &obj->buff[0];
    p2 = &obj->buff[obj->sz];
    l1 = l2 = 0;
    
    for (i = 0; i < obj->sz; i ++) {
        w = obj->words[i];
        if (!strcmp(w, word1)) {
            p1[l1 ++] = i;
        } else if (!strcmp(w, word2)) {
            p2[l2 ++] = i;
        }
    }
    
    m = obj->sz;
    for (i = 0; i < l1; i ++) {
        for (j = 0; j < l2; j ++) {
            d = p1[i] - p2[j];
            if (d < 0) d = 0 - d;
            if (d < m) m = d;
        }
    }
    
    return m;
}
​
void wordDistanceFree(WordDistance* obj) {
    free(obj->buff);
    free(obj);
}
​
/**
 * Your WordDistance struct will be instantiated and called as such:
 * struct WordDistance* obj = wordDistanceCreate(words, wordsSize);
 * int param_1 = wordDistanceShortest(obj, word1, word2);
 * wordDistanceFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:23K
Total Submissions:60.6K


Companies LinkedIn
Related Topics Hash Table Design
Similar Questions 
                
                  
                    Merge Two Sorted Lists
                  
                    Shortest Word Distance
                  
                    Shortest Word Distance III
*/
