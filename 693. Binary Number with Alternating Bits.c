/*
693. Binary Number with Alternating Bits

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101



Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.



Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.



Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.
*/

unsigned int first_bit_on(unsigned int k, unsigned int sz) {
    unsigned int m = sz / 2;
    if (k == 1) return 1;
    
    if ((k >> m) == 0) {
        return first_bit_on(k, m);
    }
    
    return m + first_bit_on(k >> m, m);
}

bool hasAlternatingBits(int n){
    unsigned int k = n;
    unsigned int b = first_bit_on(n, 32);
    //printf("%d\n", b);
    return (k ^ (k >> 1)) == ((unsigned int)1 << b) - 1 ? true : false;
}


/*
Difficulty:Easy


*/
