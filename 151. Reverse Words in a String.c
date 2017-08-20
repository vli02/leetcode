/*
151. Reverse Words in a String

Given an input string, reverse the string word by word.



For example,
Given s = "the sky is blue",
return "blue is sky the".



Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.


click to show clarification.

Clarification:



What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

void reverse(char *start, char *end) {
    char c;
    while (start < end) {
        c = *start;
        *start = *end;
        *end = c;
        start ++;
        end --;
    }
}
void reverseWords(char *s) {
    int len;
    char *p1, *p2;
    
    if (!s || !*s) return;
    
    len = strlen(s);
    
    while (len && *(s + len - 1) == ' ') {  // skip trailing spaces
        *(s + len - 1) = 0;
        len --;
    }
    
    reverse(s, s + len - 1);
    
    p1 = s;
    p2 = p1 + 1;
    while (*p1 != 0) {
        while (*p2 != 0 && *p2 != ' ') p2 ++;   // find the end of a word
        reverse(p1, p2 - 1);                    // reverse the word
        p1 = p2;
        
        while (*(p1 - 1) == ' ') p1 --;         // there might be muliple spaces after above reverse
        
        while (*p2 == ' ') p2 ++;               // skip multiple spaces
        if (*p2 == 0) *p1 = 0;
        else p1 ++;                             // leave one space
    }
}


/*
Difficulty:Medium
Total Accepted:163.3K
Total Submissions:1M


Companies Microsoft Snapchat Apple Bloomberg Yelp
Related Topics String
Similar Questions 
                
                  
                    Reverse Words in a String II
*/
