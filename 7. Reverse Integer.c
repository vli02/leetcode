/*
7. Reverse Integer

Reverse digits of an integer.


Example1: x =  123, return  321
Example2: x = -123, return -321


click to show spoilers.

Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.





Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

int reverse(int x) {
    int k = 0;
    // 2147483647
    //-2147483648
    while (x) {
        if ((x > 0 && k > (0x7fffffff - (x % 10)) / 10) ||
            (x < 0 && k < ((signed)0x80000000 - (x % 10)) / 10)) {
            return 0;
        }
        k = k * 10 + x % 10;
        x = x / 10;
    }
    return k; //(int)k == k ? (int)k : 0;
}


/*
Difficulty:Easy
Total Accepted:275.6K
Total Submissions:1.1M


Companies Bloomberg Apple
Related Topics Math
Similar Questions 
                
                  
                    String to Integer (atoi)
*/
