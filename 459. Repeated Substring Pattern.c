/*
459. Repeated Substring Pattern

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.  You may assume the given string consists of lowercase English letters only and its length  will not exceed 10000. 

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.



Example 2:
Input: "aba"

Output: False



Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

bool repeatedSubstringPattern(char* str) {
    int i, j, k;
    int l = strlen(str);
    for (i = 2; i <= l; i ++) {
        if (l % i) continue;
        k = l / i;
        for (j = 1; j < i; j ++) {
            if (strncmp(&str[0], &str[j * k], k)) break;
        }
        if (j == i) return true;
    }
    return false;
}


/*
Difficulty:Easy
Total Accepted:35K
Total Submissions:91.8K


Companies Amazon Google
Related Topics String
Similar Questions 
                
                  
                    Implement strStr()
*/
