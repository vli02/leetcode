/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(char* s) {
    int i, j, l, k = 0;
    char c;
    int pos[128] = { 0 };
    char *p;
    int n = 0;
    
    for (i = 0; s[i]; i ++) {
        n ++;
        c = s[i];
        l = i - pos[c] + 1;
        pos[c] = i + 1;
        n = n < l ? n : l;
        k = k > n ? k : n;
    }
    
    return k;
}


/*
Difficulty:Medium
Total Accepted:330.3K
Total Submissions:1.4M


Companies Amazon Adobe Bloomberg Yelp
Related Topics Hash Table Two Pointers String
Similar Questions 
                
                  
                    Longest Substring with At Most Two Distinct Characters
*/
