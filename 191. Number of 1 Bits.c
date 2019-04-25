/*
191. Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

int helper(uint32_t n, uint32_t b) {
    uint64_t k;
    
    if (n == 0) return 0;
    
    k = ((uint64_t)1 << b) - 1;
    
    if (n == k) return b;
    
    b >>= 1;
    
    return helper(n >> b, b) +
        helper(n & ((1 << b) - 1), b);
}
int hammingWeight(uint32_t n) {
#if 0
    int c = 0;
    while (n) {
        c ++;
        n &= (n - 1);
    }
    return c;
#else
    return helper(n, 32);
#endif
}


/*
Difficulty:Easy
Total Accepted:158K
Total Submissions:399.2K


Companies Microsoft Apple
Related Topics Bit Manipulation
Similar Questions 
                
                  
                    Reverse Bits
                  
                    Power of Two
                  
                    Counting Bits
                  
                    Binary Watch
                  
                    Hamming Distance
*/
