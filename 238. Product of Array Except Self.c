/*
238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *x = malloc(numsSize * sizeof(int));
    //assert(x);
    int i, j, k;
    
    x[0] = 1;
    for (i = 1; i < numsSize; i ++) {
        x[i] = x[i - 1] * nums[i - 1];
    }
    k = nums[numsSize - 1];
    for (i = numsSize - 2; i >= 0; i --) {
        x[i] = x[i] * k;
        k *= nums[i];
    }
    
    *returnSize = numsSize;
    return x;
}


/*
Difficulty:Medium
Total Accepted:106.1K
Total Submissions:216.4K


Companies Amazon LinkedIn Apple Facebook Microsoft
Related Topics Array
Similar Questions 
                
                  
                    Trapping Rain Water
                  
                    Maximum Product Subarray
                  
                    Paint House II
*/
