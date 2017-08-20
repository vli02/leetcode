/*
209. Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.


For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.


click to show more practice.

More practice:

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).


Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*/

int minSubArrayLen(int s, int* nums, int numsSize) {
    int i, j, k, d = 0;
    
    k = 0;
    for (i = 0, j = 0; i < numsSize; i ++) {
        k += nums[i];
        while (k >= s) {
            // found it
            if (d == 0 || d > i - j + 1) {
                d = i - j + 1;
            }
            // try to shrink the window from left pointer
            k -= nums[j ++];
        }
    }
    
    return d;
}


/*
Difficulty:Medium
Total Accepted:88.2K
Total Submissions:288.4K


Companies Facebook
Related Topics Array Two Pointers Binary Search
Similar Questions 
                
                  
                    Minimum Window Substring
                  
                    Maximum Size Subarray Sum Equals k
*/
