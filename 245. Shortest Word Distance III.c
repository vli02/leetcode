/*
245. Shortest Word Distance III

This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.
For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].


Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.



Note:
You may assume word1 and word2 are both in the list.
*/

int shortestWordDistance(char** words, int wordsSize, char* word1, char* word2) {
    int *buff, *p1, *p2, l1, l2;
    int i, j, d, m;
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
    
    m = wordsSize;
    if (l2) {
        for (i = 0; i < l1; i ++) {
            for (j = 0; j < l2; j ++) {
                d = p1[i] - p2[j];
                if (d < 0) d = 0 - d;
                if (d < m) m = d;
            }
        }
    } else {
        for (i = 1; i < l1; i ++) {
            d = p1[i] - p1[i - 1];
            if (d < m) m = d;
        }
    }
    
    free(buff);
    
    return m;
}


/*
Difficulty:Medium
Total Accepted:20.9K
Total Submissions:41.6K


Companies LinkedIn
Related Topics Array
Similar Questions 
                
                  
                    Shortest Word Distance
                  
                    Shortest Word Distance II
*/
