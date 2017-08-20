/*
482. License Key Formatting

Now you are given a string S, which represents a software license key which we would like to format. The string S is composed of alphanumerical characters and dashes. The dashes split the alphanumerical characters within the string into groups. (i.e. if there are M dashes, the string is split into M+1 groups). The dashes in the given string are possibly misplaced.

We want each group of characters to be of length K (except for possibly the first group, which could be shorter, but still must contain at least one character). To satisfy this requirement, we will reinsert dashes. Additionally, all the lower case letters in the string must be converted to upper case.

So, you are given a non-empty string S, representing a license key to format, and an integer K. And you need to return the license key formatted according to the description above.


Example 1:
Input: S = "2-4A0r7-4k", K = 4

Output: "24A0-R74K"

Explanation: The string S has been split into two parts, each part has 4 characters.




Example 2:
Input: S = "2-4A0r7-4k", K = 3

Output: "24-A0R-74K"

Explanation: The string S has been split into three parts, each part has 3 characters except the first part as it could be shorter as said above.



Note:

The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.
*/

char* licenseKeyFormatting(char* S, int K) {
    char *p;
    int l, n, x;
    char *head;
    int i;
    
    p = S;
    l = 0;
    while (*p) {
        if (*p != '-') l ++;  // get length all valid characters
        p ++;
    }
    
    n = l / K;    // total number of groups having full of K characters
    x = l % K;    // extra group in the beginning
​
    p = malloc(l + n + 1);
    //assert(p);
    head = p;
    
    while (*S && x) {  // encode extra group first
        if (*S != '-') {
            *p = (*S >= 'a' && *S <= 'z') ? 'A' + *S - 'a' : *S;
            p ++;
            x --;
        }
        S ++;
    }
    if (p != head && *S) {  // insert '-' if there is an extra group ahead
        *p = '-';
        p ++;
    }
    i = 0;
    while (*S) {  // encode the rest of characters
        if (*S != '-') {
            if (i != 0 && (i % K) == 0) {
                *p = '-';
                p ++;
            }
            *p = (*S >= 'a' && *S <= 'z') ? 'A' + *S - 'a' : *S;
            p ++;
            i ++;
        }
        S ++;
    }
    *p = 0;
    
    return head;
}


/*
Difficulty:Medium
Total Accepted:17.6K
Total Submissions:42.5K


Companies Google

*/
