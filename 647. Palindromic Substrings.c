/*
647. Palindromic Substrings

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


 

Note:


	The input string length won't exceed 1000.
*/

#define IDX(I, J, L) ((I) * (L) + J)
​
int countSubstrings(char* s) {
    int i, j, l;
    int *mem, p, ans;
    
    if (!s || !*s) return 0;
    
    l = strlen(s);
    mem = calloc(l * l, sizeof(int));
    //assert(mem);
    
    ans = 0;
    for (i = 0; i < l; i ++) {
        for (j = 0; j <= i; j ++) {
            if (s[i] == s[j] &&
               (i - j <= 1 || mem[IDX(i - 1, j + 1, l)] != 0)) {
                p = 1;
                ans ++;
            } else {
                p = 0;
            }
            mem[IDX(i, j, l)] = p;
        }
    }

    free(mem);
    
    return ans;
}


/*
Difficulty:Medium


*/
