/*
689. Maximum Sum of 3 Non-Overlapping Subarrays

In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.


Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.


Return the result as a list of indices representing the starting position of each interval (0-indexed).  If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.



Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    /* create summary array and scan from left to right */
    /*
    1   2   1   2   6   7   5   1
        3   3   3   8   13  12  6   <- sum
        0   0   0   3   4   4   4   <- largest sum from left
        4   4   4   4   4   5   6   <- largest sum from right
        
    i = left[0], j = 2, k = right[4]
    i = left[1], j = 3, k = right[5]
    i = left[2], j = 4, k = right[6]
    */
    
    int sum[20000], left[20000], right[20000];
    int i, j, n, m, x, y, z, s;
    int *result;
    
    n = s = 0;
    
    // create summary array
    for (i = 0; i < k && i < numsSize; i ++) {
        s += nums[i];
    }
    sum[n ++] = s;
    
    for (; i < numsSize; i ++) {
        s -= nums[i - k];
        s += nums[i];
        sum[n ++] = s;
    }
    
    // the index of largest summary from left
    left[0] = j = 0;
    for (i = 1; i < n; i ++) {
        if (sum[i] > sum[j]) j = i;
        left[i] = j;
    }
    
    // the index of largest summary from right
    right[n - 1] = j = n - 1;
    for (i = n - 2; i >= 0; i --) {
        if (sum[i] >= sum[j]) j = i;
        right[i] = j;
    }
    
    // initial value
    x = left[0];
    y = k;
    z = right[2 * k];
    
    // scan from left to right
    for (m = k + 1; m < n - k; m ++) {
        i = left[m - k];
        j = right[m + k];
        if (sum[i] + sum[m] + sum[j] > sum[x] + sum[y] + sum[z]) {
            // the index found so far
            x = i; y = m; z = j;
        }
    }
    
    result = malloc(3 * sizeof(int));
    //assert(result);
    result[0] = x; result[1] = y; result[2] = z;
    
    *returnSize = 3;
    
    return result;
}


/*
Difficulty:Hard


*/
