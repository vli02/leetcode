/*
344. Reverse String

Write a function that takes a string as input and returns the string reversed.


Example:
Given s = "hello", return "olleh".
*/

char* reverseString(char* s) {
    int i = 0;
    int j;
    char c;
    
    if (!s) return s;
    j = strlen(s);
    if (j < 2) return s;
    
    j --;
    while (i < j) {
        c = s[j];
        s[j] = s[i];
        s[i] = c;
        i ++;
        j --;
    }
    return s;
}


/*
Difficulty:Easy
Total Accepted:172.7K
Total Submissions:291.9K


Related Topics Two Pointers String
Similar Questions Reverse Vowels of a String Reverse String II

*/
