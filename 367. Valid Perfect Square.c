/*
367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.


Note: Do not use any built-in library function such as sqrt.


Example 1:
Input: 16
Returns: True



Example 2:
Input: 14
Returns: False



Credits:Special thanks to @elmirap for adding this problem and creating all test cases.
*/

bool isPerfectSquare(unsigned int num) {
#define MAX_SQRT 46341
    unsigned int start = 1, end, mid, k;
    end = num < MAX_SQRT ? num : MAX_SQRT;
    while (start <= end) {
        mid = start + (end - start) / 2;
        k = mid * mid;
        //printf("%d:%d\n", mid, k);
        if (k == num) return true;
        else if (k > num) end = mid - 1;
        else start = mid + 1;
    }
    return false;
}


/*
Difficulty:Easy
Total Accepted:49.4K
Total Submissions:129.3K


Companies LinkedIn
Related Topics Binary Search Math
Similar Questions 
                
                  
                    Sqrt(x)
                  
                    Sum of Square Numbers
*/
