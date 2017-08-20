/*
152. Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.



For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

int maxProduct(int* nums, int numsSize) {
    int i, j, k, m;
#if 0
    // O(n2)
    for (i = 0; i < numsSize; i ++) {
        k = nums[i]; if (i == 0 || m < k) m = k;
        for (j = i + 1; j < numsSize; j ++) {
            k = k * nums[j]; if (m < k) m = k;
        }
    }
#else
    int min, max;
    m = min = max = nums[0];
    for (i = 1; i < numsSize; i ++) {
        if (nums[i] >= 0) {
            k = max * nums[i];
            max = k > nums[i] ? k : nums[i];
            k = min * nums[i];
            min = k < nums[i] ? k : nums[i];
        } else {
            j = max;
            k = min * nums[i];
            max = k > nums[i] ? k : nums[i];
            k =   j * nums[i];
            min = k < nums[i] ? k : nums[i];
        }
        m = m > max ? m : max;
    }
#endif
    return m;
}


/*
Difficulty:Medium
Total Accepted:106.6K
Total Submissions:415.3K


Companies LinkedIn
Related Topics Array Dynamic Programming
Similar Questions 
                
                  
                    Maximum Subarray
                  
                    House Robber
                  
                    Product of Array Except Self
                  
                    Maximum Product of Three Numbers
*/
