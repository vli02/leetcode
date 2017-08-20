/*
191. Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

int hammingWeight(uint32_t n) {
    int c = 0;
    while (n) {
        c ++;
        n &= (n - 1);
    }
    return c;
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
