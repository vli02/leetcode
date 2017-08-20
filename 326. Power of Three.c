/*
326. Power of Three

Given an integer, write a function to determine if it is a power of three.


    Follow up:
    Could you do it without using any loop / recursion?


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

bool isPowerOfThree(int n) {
#if 0
    if (n == 1) return true;
    if (n == 0 || n % 3) return false;
    return isPowerOfThree(n / 3);
#else
    return (n > 0 && (1162261467 % n) == 0);
#endif
}


/*
Difficulty:Easy
Total Accepted:99.4K
Total Submissions:247.2K


Companies Google
Related Topics Math
Similar Questions 
                
                  
                    Power of Two
                  
                    Power of Four
*/
