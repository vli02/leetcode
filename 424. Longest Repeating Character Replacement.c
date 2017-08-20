/*
424. Longest Repeating Character Replacement

Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.



Example 1:
Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.




Example 2:
Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

int characterReplacement(char* s, int k) {
    int cnt[26] = { 0 };
    int i, max, start, end;
    
    max = start = end = 0;
    
    while (s[end]) {  // O(n) 3ms
        i = s[end ++] - 'A';
        cnt[i] ++;
        max = max > cnt[i] ? max : cnt[i];  // longest length of single character
        if (end - start > max + k) {  // length of window exceeds the limit with all replacement
            i = s[start ++] - 'A'; // shrink the window by advancing start pointer
            cnt[i] --;
        }
    }
    
    return end - start;  // this is the biggest window
}


/*
Difficulty:Medium
Total Accepted:13K
Total Submissions:30.9K


Companies Pocket Gems
Similar Questions Longest Substring with At Most K Distinct Characters

*/
