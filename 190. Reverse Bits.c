/*
190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).


Follow up:
If this function is called many times, how would you optimize it?


Related problem: Reverse Integer

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

uint32_t reverseBits(uint32_t n) {
    int k, i;
    k = 0;
    for (i = 0; i < 32; i ++) {
        k = (k << 1) | (n & 1);
        n = n >> 1;
    }
    return k;
}


/*
Difficulty:Easy
Total Accepted:109.3K
Total Submissions:370.1K


Companies Apple Airbnb
Related Topics Bit Manipulation
Similar Questions 
                
                  
                    Number of 1 Bits
*/
