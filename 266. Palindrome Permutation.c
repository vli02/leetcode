/*
266. Palindrome Permutation

Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

bool canPermutePalindrome(char* s) {
    int i, odd;
    int n[128] = { 0 };
    while (*s) n[*(s ++)] ++;
    odd = 0;
    for (i = 0; i < 128; i ++) {
        if (n[i] % 2) {
            if (odd) return false;
            odd = 1;
        }
    }
    return true;
}


/*
Difficulty:Easy
Total Accepted:33.2K
Total Submissions:58.4K


Companies Google Uber Bloomberg
Related Topics Hash Table
Similar Questions 
                
                  
                    Longest Palindromic Substring
                  
                    Valid Anagram
                  
                    Palindrome Permutation II
                  
                    Longest Palindrome
*/
