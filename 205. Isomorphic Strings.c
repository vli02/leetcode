/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

bool isIsomorphic(char* s, char* t) {
    char a[128] = { 0 };
    char b[128] = { 0 };
    while (*s) {
        //printf("%c:%c\n", *s, *t);
        if (a[*s] == 0 && b[*t] == 0) {
            a[*s] = *t;
            b[*t] = *s;
        } else if (a[*s] == *t && b[*t] == *s) {
        } else {
            return false;
        }
        s ++;
        t ++;
    }
    return true;
}


/*
Difficulty:Easy
Total Accepted:110.2K
Total Submissions:326.3K


Companies LinkedIn
Related Topics Hash Table
Similar Questions 
                
                  
                    Word Pattern
*/
