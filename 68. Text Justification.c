/*
68. Text Justification

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 


You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.



Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.



For the last line of text, it should be left justified and no extra space is inserted between words.



For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.



Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]




Note: Each word is guaranteed not to exceed L in length.



click to show corner cases.

Corner Cases:


A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *make_str1(char **words, int *lens, int x, int l, int width) {
    char *s;
    int i, j, k, num_of_space, rem_of_space;
    
    s = malloc((width + 1) * sizeof(char));
    //assert(s);
    
    if (x > 1) {
        num_of_space = (width - l) / (x - 1);
        rem_of_space = (width - l) % (x - 1);
    } else {
        num_of_space = width - l;
        rem_of_space = 0;
    }
    
    k = 0;
    for (i = 0; i < x; i ++) {
        strcpy(&s[k], words[i]);
        k += lens[i];
        for (j = 0; (i == 0 || i != x - 1) && j < num_of_space; j ++) {
            s[k] = ' ';
            k ++;
        }
        if (rem_of_space) {
            s[k] = ' ';
            k ++;
            rem_of_space --;
        }
    }
    s[k] = 0;
    
    return s;
}
char *make_str2(char **words, int *lens, int x, int l, int width) {
    char *s;
    int i, k;
    
    s = malloc(width * sizeof(char));
    //assert(s);
    
    k = 0;
    for (i = 0; i < x; i ++) {
        if (i) {
            s[k] = ' ';
            k ++;
        }
        strcpy(&s[k], words[i]);
        k += lens[i];
    }
    
    while (k < width) {
        s[k] = ' ';
        k ++;
    }
    s[k] = 0;
    
    return s;
}
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int *lens, sz, n, i, l, k;
    char **p = NULL, *s;
    int a, b;
    
    sz = 10;
    n = 0;
    p = malloc(sz * sizeof(char *));
    lens = malloc(wordsSize * sizeof(int));
    //assert(p && lens);
    
    k = 0; a = 0;
    for (i = 0; i < wordsSize; i ++) {
        l = strlen(words[i]);
        //assert(l <= maxWidth);
        lens[i] = l;
        if (k + l + i - a > maxWidth) {
            // form a line
            s = make_str1(&words[a], &lens[a], i - a, k, maxWidth);
            //printf("%s\n", s);
            //free(s);
            if (n == sz) {
                sz *= 2;
                p = realloc(p, sz * sizeof(char *));
                //assert(p);
            }
            p[n ++] = s;
            k = 0; a = i;
        }
        k += l;
    }
    
    s = make_str2(&words[a], &lens[a], i - a, k, maxWidth);
    //printf("%s\n", s);
    //free(s);
    if (n == sz) {
        sz *= 2;
        p = realloc(p, sz * sizeof(char *));
        //assert(p);
    }
    p[n ++] = s;
    
    *returnSize = n;
    
    free(lens);
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:57.2K
Total Submissions:300.4K


Companies LinkedIn Airbnb Facebook
Related Topics String

*/
