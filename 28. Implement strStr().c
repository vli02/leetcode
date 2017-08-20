/*
28. Implement strStr()

Implement strStr().


Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(char* haystack, char* needle) {
    int i, j, l1, l2;
    
    if (!haystack || !needle) return -1;
    
    l2 = strlen(needle);
    if (!l2) return 0;
    
    l1 = strlen(haystack);
    
    for (i = 0; i <= l1 - l2; i ++) {
        for (j = 0; j < l2 && haystack[i + j] == needle[j]; j ++) {
        }
        if (j == l2) return i;
    }
    
    return -1;
}


/*
Difficulty:Easy
Total Accepted:197.8K
Total Submissions:703.9K


Companies Pocket Gems Microsoft Apple Facebook
Related Topics Two Pointers String
Similar Questions 
                
                  
                    Shortest Palindrome
                  
                    Repeated Substring Pattern
*/
