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

typedef struct elem_s {
    char *word;
    int *pos, sz, n;
    struct elem_s *next;
} elem_t;

#define HF 1021

typedef struct {
    elem_t *ht[HF];
    elem_t *buff;
    int n;
} WordDistance;

unsigned int hash_code(const char *key) {
    unsigned int hc = 5381;
    while (*key) {
        hc = hc * 33 + *key;
        key ++;
    }
    return hc % HF;
}

elem_t *lookup(elem_t **ht, unsigned int hc, const char *word) {
    elem_t *p = ht[hc];
    while (p) {
        if (!strcmp(p->word, word)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

WordDistance* wordDistanceCreate(char** words, int wordsSize) {
    WordDistance *obj;
    char *word;
    elem_t *p;
    unsigned int i, hc;
    
    obj = calloc(1, sizeof(WordDistance));
    //assert(obj);
    obj->buff = malloc(sizeof(elem_t) * wordsSize);
    //assert(obj->buff);
    obj->n = 0;
    
    for (i = 0; i < wordsSize; i ++) {
        word = words[i];
        hc = hash_code(word);
        p = lookup(obj->ht, hc, word);
        if (!p) {
            p = &obj->buff[obj->n ++];
            p->n = 0;
            p->sz = 10;
            p->pos = malloc(p->sz * sizeof(int));
            //assert(p->pos);
            
            p->word = word;
            
            p->next = obj->ht[hc];
            obj->ht[hc] = p;
        } else if (p->n == p->sz) {
            p->sz *= 2;
            p->pos = realloc(p->pos, p->sz * sizeof(int));
            //assert(p->pos);
        }
        p->pos[p->n ++] = i;
    }
    
    return obj;
}

int wordDistanceShortest(WordDistance* obj, char* word1, char* word2) {
    elem_t *p1, *p2;
    int i, j, a, b, c, d, m;
        
    p1 = lookup(obj->ht, hash_code(word1), word1);
    //assert(p1 && p1->n > 0);
    p2 = lookup(obj->ht, hash_code(word2), word2);
    //assert(p2 && p2->n > 0);
    
    i = j = 0;
    a = p1->pos[i ++];
    b = p2->pos[j ++];
    if (a < b) {
        m = b - a;
        c = 1;
    } else {
        m = a - b;
        c = 2;
    }
    
    while ((c == 1 && i < p1->n) ||
           (c == 2 && j < p2->n)) {
        if (c == 1) {
            do {
                a = p1->pos[i ++];
                if (a < b) {
                    d = b - a;
                } else {
                    d = a - b;
                    c = 2;
                }
                m = m < d ? m : d;
            } while (c == 1 && i < p1->n);
        } else {
            do {
                b = p2->pos[j ++];
                if (a < b) {
                    d = b - a;
                    c = 1;
                } else {
                    d = a - b;
                }
                m = m < d ? m : d;
            } while (c == 2 && j < p2->n);
        }
    }
    
    return m;
}

void wordDistanceFree(WordDistance* obj) {
    int i;
    elem_t *p;
    for (i = 0; i < obj->n; i ++) {
        p = &obj->buff[i];
        free(p->pos);
    }
    free(obj->buff);
    free(obj);
}

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
