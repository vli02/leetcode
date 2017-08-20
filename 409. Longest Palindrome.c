/*
409. Longest Palindrome

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.


Example: 
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

int longestPalindrome(char* s) {
    int n[52] = { 0 };
    int i, k, odd;
    while (*s) {
        if (*s >= 'a') i = *s - 'a';
        else           i = *s - 'A' + 26;
        n[i] ++;
        s ++;
    }
    k = 0;
    odd = 0;
    for (i = 0; i < 52; i ++) {
        odd |= n[i] % 2;
        k += n[i] - (n[i] % 2); // can use part of them!!!
    }
    return k + odd;
}


/*
Difficulty:Easy
Total Accepted:45.6K
Total Submissions:100.4K


Companies Google
Related Topics Hash Table
Similar Questions 
                
                  
                    Palindrome Permutation
*/
