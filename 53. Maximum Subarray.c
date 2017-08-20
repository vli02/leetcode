/*
53. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.


For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.


click to show more practice.

More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

int maxSubArray(int* nums, int numsSize) {
    int i, j, s, m = 0;
#if 0
    // O(n2)
    for (i = 0; i < numsSize; i ++) {
        s = nums[i]; if (i == 0 || m < s) m = s;
        for (j = i + 1; j < numsSize; j ++) {
            s += nums[j]; if (m < s) m = s;
        }
    }
#else
    m = s = nums[0];
    for (i = 1; i < numsSize; i ++) {
        //printf("s: %d, m: %d\n", s, m);
        if (s > 0) s += nums[i];
        else       s  = nums[i];
        if (m < s) m = s;
    }
    //printf("s: %d, m: %d\n", s, m);
#endif
    return m;
}


/*
Difficulty:Easy
Total Accepted:216.1K
Total Submissions:546K


Companies LinkedIn Bloomberg Microsoft
Related Topics Array Dynamic Programming Divide and Conquer
Similar Questions 
                
                  
                    Best Time to Buy and Sell Stock
                  
                    Maximum Product Subarray
*/
