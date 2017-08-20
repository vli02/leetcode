/*
342. Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true.
Given num = 5, return false.


Follow up: Could you solve it without loops/recursion?

Credits:Special thanks to @yukuairoy  for adding this problem and creating all test cases.
*/

bool isPowerOfFour(int num) {
    // one bit only and has to be on 0101 0101 0101 0101
    return num > 0 && (num&(num-1)) == 0 && (num & 0x55555555) != 0;
}


/*
Difficulty:Easy
Total Accepted:67.8K
Total Submissions:176.4K


Companies Two Sigma
Related Topics Bit Manipulation
Similar Questions 
                
                  
                    Power of Two
                  
                    Power of Three
*/
