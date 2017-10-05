/*
639. Decode Ways II

A message containing letters from A-Z is being encoded to numbers using the following mapping way:


'A' -> 1
'B' -> 2
...
'Z' -> 26



Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.




Given the encoded message containing digits and the character '*', return the total number of ways to decode it.



Also, since the answer may be very large, you should return the output mod 109 + 7.


Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".



Example 2:
Input: "1*"
Output: 9 + 9 = 18



Note:

The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
*/

#define MOD 1000000007
​
int numDecodings(char* s) {
    char p, t;
    long long a, b, c;
    
    p = '0';    // previous character
    a = 0;      // previous previous number
    b = 1;      // previous number
    c = 0;      // current number
    
    while (t = *(s ++)) {
        switch (t) {
            case '0':
                if (p == '*') {
                    c = a * 2;
                } else if (p != '1' && p != '2') {
                    return 0;
                } else {
                    c = a;
                }
                break;
            case '*':
                c = b * 9;
                if (p == '1') {
                    c += a * 9;
                } else if (p == '2') {
                    c += a * 6;
                } else if (p == '*') {
                    c += a * 15;
                }
                break;
            default:
                c = b;
                if (p == '*') {
                    if (t <= '6') {
                        c += a * 2;
                    } else {
                        c += a;
                    }
                } else if (p == '1' ||
                    (p == '2' && t >= '0' && t <= '6')) {
                    c += a;
                }
                break;
        }
        a = b % MOD;
        b = c % MOD;
        p = t;
    }
    
    return c % MOD;
}


/*
Difficulty:Hard
Total Accepted:5.3K
Total Submissions:22.3K


Companies Facebook
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Decode Ways
*/
