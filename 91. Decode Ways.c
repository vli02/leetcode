/*
91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:


'A' -> 1
'B' -> 2
...
'Z' -> 26



Given an encoded message containing digits, determine the total number of ways to decode it.



For example,
Given encoded message "12",
it could be decoded as "AB" (1 2) or "L" (12).



The number of ways decoding "12" is 2.
*/

int numDecodings(char* s) {
    int a, b, c;
    char p, t;
    
    a = 0;
    b = 1;
    c = 0;
    p = '0';
    
    while (t = *s) {
        s ++;
        if (t == '0') {
            if (p != '1' && p != '2') {
                return 0;
            }
            c = a;
        } else {
            c = b;
            if (p == '1' || (p == '2' && t <= '6')) {
                c += a;
            }
        }
        a = b;
        b = c;
        p = t;
    }
​
    return c;
}


/*
Difficulty:Medium
Total Accepted:128.3K
Total Submissions:654.3K


Companies Microsoft Uber Facebook
Related Topics Dynamic Programming String
Similar Questions 
                
                  
                    Decode Ways II
*/
