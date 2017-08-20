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
    int *pat, np;
    char *next;
    int i, j, k, l;
    
    if (!pattern || !*pattern || !str || !*str) return false;
    //if (!strcmp(pattern, str)) return true;
    
    l = strlen(pattern);
    pat = calloc(l, sizeof(int));
    
    i = j = 0;
    
    next = str;
    while (*next) {
        while (*next && *next != ' ') {
            next++;
        }
        if (*next == ' ') {
            *next = 0;
            next ++;
        }
        np = 0;
        if (*pattern) {
            if (!pat[i]) {
                pat[i] = *pattern - 'a' + 1;
                np = 1;
            }
            pattern ++;
            i ++;
        } else {
            j = j % i;
        }
        if (!bucket[pat[j] - 1]) {
            for (k = 0; np && k < i - 1; k ++) {
                if (!strcmp(bucket[pat[k] - 1], str)) {
                    free(pat);
                    return false;
                }
            }
            bucket[pat[j] - 1] = str;
        } else if (strcmp(bucket[pat[j] - 1], str)) {
            free(pat);
            return false;
        }
        j ++;
        str = next;
    }
    free(pat);
    return (j % l == 0) ? true : false;
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
