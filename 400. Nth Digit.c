/*
400. Nth Digit

Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).


Example 1:
Input:
3

Output:
3



Example 2:
Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

int findNthDigit(int n) {
    unsigned int i, j, k;
​
    i = j = 1;
    while (n > 9 * i * j) {
        n -= 9 * i * j;
        j *= 10;
        i ++;
    }
    k = j + (n - 1) / i;
    for (j = (n - 1) % i; j < i - 1; j ++) {
        k = k / 10;
    }
    return k % 10;
}


/*
Difficulty:Easy
Total Accepted:25K
Total Submissions:83.1K


Companies Google
Related Topics Math

*/
