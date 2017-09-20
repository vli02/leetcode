/*
290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.




Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.


Credits:Special thanks to @minglotus6 for adding this problem and creating all test cases.
*/

bool wordPattern(char* pattern, char* str) {
    char *bucket[26] = { 0 };
    int   len   [26] = { 0 };
    char c, *p, *s;
    char t, *pat;
    int l;
    
    pat = pattern;
    while (*str && *pattern) {
        s = str;
        l = 0;
        while (*str && *str != ' ') {
            str ++;
        }
        l = str - s;
        if (*str == ' ') {
            *str = 0;  // strcmp is much faster than strncmp, so cut the strings.
            str ++;    // skip single space
        }
        
        c = *(pattern ++) - 'a';
        p = bucket[c];
        if (p) {
            if (strcmp(p, s)) return false;
        } else {
            bucket[c] = s;
            len[c] = l;
            // cannot be same with other pattern
            p = pat;
            while ((t = (*p ++) - 'a') != c) {
                if (len[t] == len[c] &&
                    !strcmp(bucket[t], bucket[c])) return false;
            }
        }
    }
    
    return (!*pattern && !*str) ? true : false;
}

/*
Difficulty:Easy
Total Accepted:82.1K
Total Submissions:248.7K


Companies Dropbox Uber
Related Topics Hash Table
Similar Questions 
                
                  
                    Isomorphic Strings
                  
                    Word Pattern II
*/
