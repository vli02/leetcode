/*
408. Valid Word Abbreviation

Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.


A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.


Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.



Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/

bool validWordAbbreviation(char* word, char* abbr) {
    int n = 0;
    while (*abbr) {
        if (*abbr >= '0' && *abbr <= '9') {
            n = n * 10 + *abbr - '0';
            if (!n) return false; // invalid input
        } else {
            while (n && *word) {
                n --; word ++;
            }
            if (*word != *abbr) return false;
            word ++;
        }
        abbr ++;
    }
    while (n && *word) {
        n --; word ++;
    }
    return (n || *word) ? false : true;
}


/*
Difficulty:Easy
Total Accepted:11.1K
Total Submissions:39.6K


Companies Google
Related Topics String
Similar Questions 
                
                  
                    Minimum Unique Word Abbreviation
                  
                    Word Abbreviation
*/
