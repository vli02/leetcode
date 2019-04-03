/*
9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true


Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.


Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Follow up:

Coud you solve it without converting the integer to a string?
*/

bool isPalindrome(int x) {
    int n, d, k = 0;
    
    if (x < 0) return false;
    
    n = x;
    while (n) {
        d = n % 10;
        if (k > (0x7fffffff - d) / 10) return false;    // overflow
        k = k * 10 + d;
        n = n / 10;

    
    return (k == x);
}


/*
Difficulty:Easy


*/
