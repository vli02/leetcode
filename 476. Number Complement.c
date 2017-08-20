/*
476. Number Complement

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:

The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.



Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.



Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

int findComplement(int num) {
    int i, k = 0;
    if (!num) return 1;
    for (i = 0; num && i < 32; i ++) {
        if (!(num & (1 << i))) {
            k |= (1 << i);
        } else {
            num &= ~(1 << i);
        }
    }
    return k;
}


/*
Difficulty:Easy
Total Accepted:49.4K
Total Submissions:81K


Companies Cloudera
Related Topics Bit Manipulation

*/
