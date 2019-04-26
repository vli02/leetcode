/*
762. Prime Number of Set Bits in Binary Representation

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary.  For example, 21 written in binary is 10101 which has 3 set bits.  Also, 1 is not a prime.)


Example 1:Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)


Example 2:Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)


Note:
L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/

int numOfBits(n) {
    int k = 0;
    while (n) {
        k ++;
        n = n & (n - 1);
    }
    return k;
}
​
int countPrimeSetBits(int L, int R){
    int k = (1 << 2) |
            (1 << 3) |
            (1 << 5) |
            (1 << 7) |
            (1 << 11) |
            (1 << 13) |
            (1 << 17) |
            (1 << 19);
    int ans = 0;
    while (L <= R) {
        if ((k >> numOfBits(L)) & 1) ans ++;
        /* equals to:
        if (numOfBits(L) is 2 or 3 or 5 or 7 ...
        */

    }
    return ans;
}


/*
Difficulty:Easy


*/
