/*
843. Guess the Word

This problem is an interactive problem new to the LeetCode platform.

We are given a word list of unique words, each word is 6 letters long, and one word in this list is chosen as secret.

You may call master.guess(word) to guess a word.  The guessed word should have type string and must be from the original list with 6 lowercase letters.

This function returns an integer type, representing the number of exact matches (value and position) of your guess to the secret word.  Also, if your guess is not in the given wordlist, it will return -1 instead.

For each test case, you have 10 guesses to guess the word. At the end of any number of calls, if you have made 10 or less calls to master.guess and at least one of these guesses was the secret, you pass the testcase.

Besides the example test case below, there will be 5 additional test cases, each with 100 words in the word list.  The letters of each word in those testcases were chosen independently at random from 'a' to 'z', such that every word in the given word lists is unique.

Example 1:
Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]

Explanation:

master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.

We made 5 calls to master.guess and one of them was the secret, so we pass the test case.


Note:  Any solutions that attempt to circumvent the judge will result in disqualification.
*/

        }
​
        max_group = groups[0];
        for (j = 1; j < 7; j ++) {
            if (max_group < groups[j]) max_group = groups[j];
        }
​
        if (min_group > max_group) {
            min_group = max_group;
            //printf("groups: %d, %d %d, %d, %d, %d, %d\n", groups[0], groups[1], groups[2], groups[3], groups[4], groups[5], groups[6]);
            g = i;
        }
    }
​
    return g;
}
​
void findSecretWord(char** wordlist, int wordlistSize, Master* master) {
    int match[100 * 100];
    int i, j, k, m, g;
    char *a, *b;
​
    set_t buff[2] = { 0 };
    set_t *p1, *p2, *p3;
    int xp[100] = { 0 };
​

    p2 = &buff[1];
​
    // caculate match matrix
    for (i = 0; i < wordlistSize; i ++) {
        a = wordlist[i];
        for (j = i + 1; j < wordlistSize; j ++) {
            b = wordlist[j];
            m = 0;
            for (k = 0; k < 6; k ++) {
                if (a[k] == b[k]) m ++;
            }
            match[IDX(i, j)] = match[IDX(j, i)] = m;
        }
    }
​
    // all are possible in the beginning
    for (i = 0; i < wordlistSize; i ++) {
        p1->idx[p1->n ++] = i;
    }
​
    while (p1->n > 0) {
        //printf("POSSIBLE: %d\n", p1->n);
        g = solve(p1, xp, match, wordlistSize);
        printf("GUESS: %d, %s\n", g, wordlist[g]);
        m = guess(master, wordlist[g]);
        //printf("MATCH: %d\n", m);
        if (m == 6) return;
        // find out next possible words
        p2->n = 0;                          // reset p2
        for (i = 0; i < p1->n; i ++) {
            if (match[IDX(g, p1->idx[i])] == m) {
                p2->idx[p2->n ++] = p1->idx[i];
            }
        }
        // swap p1, p2
        p3 = p1;
        p1 = p2;
        p2 = p3;
        // exclude g in future guess
        xp[g] = 1;
    }
}


/*
Difficulty:Hard


*/
