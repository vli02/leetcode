/*
171. Excel Sheet Column Number

Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

int titleToNumber(char* s) {
    int k = 0;
    while (s && *s) {
        k = k * 26 + (*s) - 'A' + 1;
        s ++;
    }
    return k;
}


/*
Difficulty:Easy
Total Accepted:136.5K
Total Submissions:289.8K


Companies Microsoft Uber
Related Topics Math
Similar Questions 
                
                  
                    Excel Sheet Column Title
*/
