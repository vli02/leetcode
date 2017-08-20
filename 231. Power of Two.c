/*
231. Power of Two

Given an integer, write a function to determine if it is a power of two.


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

bool isPowerOfTwo(int n) {
    if (!n || (n & 0x80000000)) return false; // this is important!
#if 0
    while (!(n & 1)) n >>= 1;
    return n == 1 ? true : false;
#else
    //printf("%x, %x\n", n, n - 1);
    return (n & (n - 1)) == 0 ? true : false;
#endif
}


/*
Difficulty:Easy
Total Accepted:141.5K
Total Submissions:352.5K


Companies Google
Related Topics Math Bit Manipulation
Similar Questions 
                
                  
                    Number of 1 Bits
                  
                    Power of Three
                  
                    Power of Four
*/
