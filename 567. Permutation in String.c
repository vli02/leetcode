/*
567. Permutation in String

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").



Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False



Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

bool checkInclusion(char* s1, char* s2) {
    int cnt[26] = { 0 };
    int total = 0;
    int i, j;
    char c, k;
    
    while (c = *(s1 ++)) {
        c -= 'a';
        cnt[c] ++;
        total ++;
    }
​
    i = j = 0;
    while (c = s2[j ++]) {
        c -= 'a';
        if (cnt[c] > 0) total --;
        if (total == 0) return true;  // where i is the start index, j - i is the length
        cnt[c] --;
        while (cnt[c] < 0) {
            k = s2[i ++];
            k -= 'a';
            cnt[k] ++;
            if (cnt[k] > 0) total ++;
        }
    }
    
    return false;
}


/*
Difficulty:Medium
Total Accepted:9.5K
Total Submissions:26.1K


Companies Microsoft
Related Topics Two Pointers
Similar Questions 
                
                  
                    Minimum Window Substring
                  
                    Find All Anagrams in a String
*/
