/*
345. Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.


Example 1:
Given s = "hello", return "holle".



Example 2:
Given s = "leetcode", return "leotcede".



Note:
The vowels does not include the letter "y".
*/

#define IS_VOWEL(C) ((C) == 'a' || (C) == 'A' || \
                     (C) == 'e' || (C) == 'E' || \
                     (C) == 'i' || (C) == 'I' || \
                     (C) == 'o' || (C) == 'O' || \
                     (C) == 'u' || (C) == 'U')
​
char* reverseVowels(char* s) {
    char *a, *b, c;
    
    if (!s || !*s) return s;
    
    a = s;
    b = &s[strlen(s) - 1];
    
    while (a < b) {
        if (IS_VOWEL(*a) && IS_VOWEL(*b)) {
            // swap
            c = *a;
            *a = *b;
            *b = c;
            a ++;
            b --;
        } else if (IS_VOWEL(*a)) {
            b --;
        } else if (IS_VOWEL(*b)) {
            a ++;
        } else {
            a ++;
            b --;
        }
    }
    return s;
}


/*
Difficulty:Easy
Total Accepted:82.8K
Total Submissions:215.1K


Companies Google
Related Topics Two Pointers String
Similar Questions 
                
                  
                    Reverse String
*/
