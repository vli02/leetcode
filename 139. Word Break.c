/*
139. Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.


For example, given
s = "leetcode",
dict = ["leet", "code"].



Return true because "leetcode" can be segmented as "leet code".



UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

bool search(char *s, int l, char **wordDict, int wordDictSize) {
    int i;
    char *word;
    for (i = 0; i < wordDictSize; i ++) {
        word = wordDict[i];
        if (word && l == strlen(word) && !strncmp(s, word, l)) return true;
    }
    return false;
}
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int i, j, l;
    int *e;
    
    l = strlen(s);
    
    e = malloc((l + 1) * sizeof(int));
    if (!s) return true;
    
    e[0] = true;
    for (i = 0; i < l; i ++) {
        e[i + 1] = false;
        for (j = 0; !e[i + 1] && j <= i; j ++) {
            e[i + 1] = e[j] && search(&s[j], i - j + 1, wordDict, wordDictSize);
        }
    }
    
    i = e[l];
    free(e);
    
    return i;
}


/*
Difficulty:Medium
Total Accepted:156.4K
Total Submissions:523.6K


Companies Google Uber Facebook Amazon Yahoo Bloomberg Pocket Gems
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Word Break II
*/
