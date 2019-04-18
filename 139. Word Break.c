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
    bool *buff, *e, result;
    
    l = strlen(s);
    
    buff = calloc((l + 1), sizeof(bool));
    //assert(buff);
    
    buff[0] = true;
    e = &buff[1];
    
    for (i = 0; i < l; i ++) {
        for (j = i; !e[i] && j >= 0; j --) {
            e[i] = e[j - 1] && search(&s[j], i - j + 1, wordDict, wordDictSize);
        }
    }
    
    result = e[l - 1];
    free(buff);
    
    return result;
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
