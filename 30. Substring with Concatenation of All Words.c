/*
30. Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.



For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]



You should return the indices: [0,9].
(order does not matter).
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    // 1. sort all words
    // 2. caculate each uniq words appears how many times
    /* for (i = 0; i < length of string; i ++) {
        substr = s[i ... length of one word]
        if (substr is not one of the words or it appears more than what we have) continue;
        increase the count of this word
        if all words are found, add i into result
    } */
    return NULL;
}


/*
Difficulty:Hard
Total Accepted:82.6K
Total Submissions:376.3K


Related Topics Hash Table Two Pointers String
Similar Questions Minimum Window Substring

*/
