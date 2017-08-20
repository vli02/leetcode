/*
288. Unique Word Abbreviation

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n


Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

struct item {
    char *s;
    int l;
    struct item *shadow;
};
#define FACTOR 1000
struct ValidWordAbbr {
    struct item *hash[FACTOR];
    struct item *buff;
};
​
/** Initialize your data structure here. */
struct ValidWordAbbr* ValidWordAbbrCreate(char** dictionary, int dictionarySize) {
    struct ValidWordAbbr *vwa;
    struct item *buff, *p;
    int i, l;
    char *s;
    
    vwa = calloc(1, sizeof(struct ValidWordAbbr));
    buff = malloc(dictionarySize * sizeof(struct item));
    //assert(vwa && buff);
    vwa->buff = buff;
    
    for (i = 0; i < dictionarySize; i ++) {
        s = dictionary[i];
        l = strlen(s);
        p = &buff[i];
        //assert(p);
        p->s = s;
        p->l = l;
        p->shadow = vwa->hash[l % FACTOR];
        vwa->hash[l % FACTOR] = p;
    }
    return vwa;
}
​
bool isUnique(struct ValidWordAbbr* vwa, char* word) {
    int l;
    struct item *p;
​
    l = strlen(word);
    p = vwa->hash[l % FACTOR];
    while (p) {
        if (p->l == l &&
            p->s[0]     == word[0] &&
            p->s[l - 1] == word[l - 1] &&
            strcmp(p->s, word)) {
            return false;
        }
        p = p->shadow;
    }
    
    return true;
}
​
/** Deallocates memory previously allocated for the data structure. */
void ValidWordAbbrFree(struct ValidWordAbbr* vwa) {
    free(vwa->buff);
    free(vwa);
}
​
// Your ValidWordAbbr object will be instantiated and called as such:
// struct ValidWordAbbr* vwa = ValidWordAbbrCreate(words, wordsSize);
// isUnique(vwa, "word");
// isUnique(vwa, "anotherWord");
// ValidWordAbbrFree(vwa);


/*
Difficulty:Medium
Total Accepted:26.9K
Total Submissions:161.2K


Companies Google
Related Topics Hash Table Design
Similar Questions 
                
                  
                    Two Sum III - Data structure design
                  
                    Generalized Abbreviation
*/
