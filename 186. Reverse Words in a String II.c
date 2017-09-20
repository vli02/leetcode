/*
186. Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.



The input string does not contain leading or trailing spaces and the words are always separated by a single space.



For example,
Given s = "the sky is blue",
return "blue is sky the".



Could you do it in-place without allocating extra space?


Related problem: Rotate Array
*/

void swap(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}
void reverse(char *s, int start, int end, int w) {
    int i, j;
    
    for (i = start, j = end; i <= j; i ++, j --) {
        swap(&s[i], &s[j]);
        if (w && s[i] == ' ') {
            reverse(s, start, i - 1, 0);
            start = i + 1;
        }
        if (w && s[j] == ' ') {
            reverse(s, j + 1, end, 0);
            end = j - 1;
        }
    }
    
    if (w && start < end) reverse(s, start, end, 0);
}
void reverseWords(char *s) {
    reverse(s, 0, strlen(s) - 1, 1);
}


/*
Difficulty:Medium
Total Accepted:30.2K
Total Submissions:110.3K


Companies Microsoft Amazon Uber
Related Topics String
Similar Questions 
                
                  
                    Reverse Words in a String
                  
                    Rotate Array
*/
