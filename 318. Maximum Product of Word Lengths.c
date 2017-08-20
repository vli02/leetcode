/*
318. Maximum Product of Word Lengths

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
    You may assume that each word will contain only lower case letters.
    If no such two words exist, return 0.



    Example 1:


    Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
    Return 16
    The two words can be "abcw", "xtfn".


    Example 2:


    Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
    Return 4
    The two words can be "ab", "cd".


    Example 3:


    Given ["a", "aa", "aaa", "aaaa"]
    Return 0
    No such pair of words.    


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

int maxProduct(char** words, int wordsSize) {
    char *s;
    int *b, *l; // bits and length
    int i, j;
    int x, k = 0;
    
    if (wordsSize < 2) return 0;
    
    b = calloc(wordsSize * 2, sizeof(int));
    //assert(b);
    
    l = &b[wordsSize];
    
    i = 0;
    while (i < wordsSize) {
        s = words[i];
        while (s && *s) {
            b[i] |= 1 << (*s - 'a');
            l[i] ++;
            s ++;
        }
​
        j = 0;
        while (j < i) {
            if ((b[j] & b[i]) == 0) {
                x = l[j] * l[i];
                if (k < x) k = x;
            }
            j ++;
        }
        i ++;
    }
    
    free(b);
    
    return k;
}


/*
Difficulty:Medium
Total Accepted:51.8K
Total Submissions:117.1K


Companies Google
Related Topics Bit Manipulation

*/
