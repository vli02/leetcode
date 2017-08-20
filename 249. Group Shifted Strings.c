/*
249. Group Shifted Strings

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupStrings(char** strings, int stringsSize, int** columnSizes, int* returnSize) {
    int i, j, k, d;
    char *pattern, *s;
    char **buff, ***p;
    
    *returnSize = 0;
    
    if (stringsSize <= 0) return NULL;
    
    p = malloc(stringsSize * sizeof(char **));
    // this caused runtime error!!! it must be the free in the caller.
    // caller should ask for a free function and let the one who malloc'ed the memory free the memory.
    //buff = malloc((stringsSize + 1) * sizeof(char *));
    *columnSizes = malloc(stringsSize * sizeof(int));
    //assert(p && buff && *columnSizes);
    
    pattern = NULL;
    for (i = 0; i < stringsSize; i ++) {
        s = strings[i];
        if (!s) continue;
        pattern = s;
        (*columnSizes)[*returnSize] = 1;
        // use one malloc in the beginning is a much better way for memory management!!!
        buff = malloc(stringsSize * sizeof(char *));
        //assert(buff);
        p[*returnSize] = buff;
        (*returnSize) ++;
        buff[0] = pattern;
        buff ++;
        for (j = i + 1; j < stringsSize; j ++) {
            s = strings[j];
            if (!s) continue;
            d = s[0] - pattern[0];
            if (d < 0) d = d + 26;
            k = 1;
            while (s[k] && pattern[k] && (s[k] - 'a') == ((pattern[k] - 'a' + d) % 26)) {
                k ++;
            }
            if (!s[k] && !pattern[k]) {
                (*columnSizes)[(*returnSize) - 1] ++;
                buff[0] = s;
                buff ++;
                strings[j] = NULL;
            }
        }
    }
​
    return p;
}


/*
Difficulty:Medium
Total Accepted:25.7K
Total Submissions:62.1K


Companies Google Uber
Related Topics Hash Table String
Similar Questions 
                
                  
                    Group Anagrams
*/
