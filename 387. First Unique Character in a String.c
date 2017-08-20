/*
387. First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.




Note: You may assume the string contain only lowercase letters.
*/

int firstUniqChar(char* s) {
    int num[26] = { 0 };
    int idx[26];
    int i, j;
    
    i = 0;
    while (s[i]) {
        num[s[i] - 'a'] ++;
        idx[s[i] - 'a'] = i;
        i ++;
    }
    j = -1;
    for (i = 0; i < 26; i ++) {
        if (num[i] == 1 && (j == -1 || j > idx[i])) {
            j = idx[i];
        }
    }
    return j;
}


/*
Difficulty:Easy
Total Accepted:70.1K
Total Submissions:150.5K


Companies Amazon Bloomberg Microsoft

*/
