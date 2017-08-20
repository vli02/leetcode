/*
418. Sentence Screen Fitting

Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.


Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word is greater than 0 and won't exceed 10.
1 ≤ rows, cols ≤ 20,000.




Example 1: 
Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output: 
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.




Example 2: 
Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output: 
2

Explanation:
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.




Example 3: 
Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output: 
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.
*/

int wordsTyping(char** sentence, int sentenceSize, int rows, int cols) {
    int *sz, t, i, p, n, r;
    int cur;
    
    sz = malloc(sentenceSize * sizeof(int));
    //assert(sz);
    t = 0;
    for (i = 0; i < sentenceSize; i ++) {
        sz[i] = strlen(sentence[i]);
        t += sz[i];
    }
    t += sentenceSize - 1;
    
    p = n = r = 0;
    while (r < rows) {
        r ++;
        cur = 0;
        while (!p && cur + t <= cols) { // batch fitting
            cur += t + 1;
            n ++;
        }
        while (cur + sz[p] <= cols) {
            cur += sz[p] + 1;
            p = (p + 1) % sentenceSize;
            if (!p) {
                n ++;
                while (cur + t <= cols) { // batch fitting
                    cur += t + 1;
                    n ++;
                }
            }
        }
        if (!p) {
            n = n * (rows / r);
            r = r * (rows / r);
        }
    }
    free(sz);
    return n;
}


/*
Difficulty:Medium
Total Accepted:12.3K
Total Submissions:44.5K


Companies Google
Related Topics Dynamic Programming

*/
