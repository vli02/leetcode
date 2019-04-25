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
    /*
    uint32_t k, i;
    k = 0;
    for (i = 0; i < 32; i ++) {
        k = (k << 1) | (n & 1);
        n = n >> 1;
    }
    return k;
    */
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8)  | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4)  | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2)  | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1)  | ((n & 0x55555555) << 1);
    
    return n;
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
