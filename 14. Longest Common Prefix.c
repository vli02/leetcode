/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"


Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Note:

All given inputs are in lowercase letters a-z.
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    int i, n = 0;
    char c;

    if (strsSize == 0) return "";
    
    while (c = strs[0][n]) {
        for (i = 1; i < strsSize; i ++) {
            if (strs[i][n] != c) {
                strs[0][n] = 0;
                return strs[0];
            }
        }
        n ++;
    }
    strs[0][n] = 0;
    return strs[0];
}


/*
Difficulty:Easy


*/
