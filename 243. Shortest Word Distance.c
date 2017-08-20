/*
243. Shortest Word Distance

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].


Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.



Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

int shortestDistance(char** words, int wordsSize, char* word1, char* word2) {
    int *buff, *p1, *p2, l1, l2;
    int i, j, a, b, c, d, m;
    char *w;
    
    buff = malloc(wordsSize * 2 * sizeof(int));
    p1 = &buff[0];
    p2 = &buff[wordsSize];
    l1 = l2 = 0;
    
    for (i = 0; i < wordsSize; i ++) {
        w = words[i];
        if (!strcmp(w, word1)) {
            p1[l1 ++] = i;
        } else if (!strcmp(w, word2)) {
            p2[l2 ++] = i;
        }
    }
    
#if 0
    // O(n^2)
    m = wordsSize;
    for (i = 0; i < l1; i ++) {
        for (j = 0; j < l2; j ++) {
            d = p1[i] - p2[j];
            if (d < 0) d = 0 - d;
            if (d < m) m = d;
        }
    }
#else
    // O(m+n)
    i = j = 0;
    a = p1[i ++];
    b = p2[j ++];
    if (a < b) { m = b - a; c = 1; }
    else       { m = a - b; c = 2; }
    while ((c == 1 && i < l1) ||
           (c == 2 && j < l2)) {
        if (c == 1) {
            do {
                a = p1[i ++];
                if (a < b) {
                    d = b - a;
                } else {
                    c = 2;
                    d = a - b;
                }
                m = m < d ? m : d;
            } while (i < l1 && c == 1);
        } else {
            do {
                b = p2[j ++];
                if (a > b) {
                    d = a - b;
                } else {
                    c = 1;
                    d = b - a;
                }
                m = m < d ? m : d;
            } while (j < l2 && c == 2);
        }
    }
#endif
    
    free(buff);
    
    return m;
}


/*
Difficulty:Easy
Total Accepted:32.4K
Total Submissions:61.8K


Companies LinkedIn
Related Topics Array
Similar Questions 
                
                  
                    Shortest Word Distance II
                  
                    Shortest Word Distance III
*/
