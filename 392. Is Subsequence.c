/*
392. Is Subsequence

Given a string s and a string t, check if s is subsequence of t.



You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).



A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).


Example 1:
s = "abc", t = "ahbgdc"


Return true.


Example 2:
s = "axc", t = "ahbgdc"


Return false.


Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:Special thanks to @pbrother for adding this problem and creating all test cases.
*/

#define IDX(ROW, COL, SZ) ((ROW + 1) * (SZ + 1) + (COL + 1))
​
bool isSubsequence(char* s, char* t) {
#if 0   // 260ms
    int sl, tl, row, col;
    bool *dp, ans = false;

    if (!s || !*s) return true;
    else if (!t || !*t) return false;
    
    sl = strlen(s);
    tl = strlen(t);
    
    dp = calloc((sl + 1) * (tl + 1), sizeof(bool));
    //assert(dp);
    
    for (col = -1; col < tl; col ++) {
        dp[IDX(-1, col, tl)] = true;
    }
    /*for (row = 0; row < sl; row ++) {
        dp[IDX(row, -1, tl)] = false;
    }*/
    
    for (row = 0; row < sl; row ++) {
        for (col = 0; col < tl; col ++) {
            dp[IDX(row, col, tl)] = dp[IDX(row, col - 1, tl)] ||


/*
Difficulty:Medium


*/
