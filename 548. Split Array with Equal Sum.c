/*
548. Split Array with Equal Sum

Given an array with n integers, you need to find if there are triplets  (i, j, k) which satisfies following conditions:

 0 < i, i + 1 < j, j + 1 < k < n - 1 
 Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal. 

where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.


Example:
Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1



Note:

 1 <= n <= 2000. 
 Elements in the given array will be in range [-1,000,000, 1,000,000].
*/

bool splitArray(int* nums, int numsSize) {
    int i, j, k, n;
    int s1, s2, s3, s4;
    s1 = 0;
    for (i = 1; i < numsSize - 3; i ++) {
        s1 += nums[i - 1];
        s2 = 0;
        for (j = i + 2; j < numsSize - 2; j ++) {
            s2 += nums[j - 1];
            if (s1 == s2) {
                s3 = 0;
                for (k = j + 2; k < numsSize - 1; k ++) {
                    s3 += nums[k - 1];
                    if (s2 == s3) {
                        s4 = 0;
                        for (n = k + 1; n < numsSize; n ++) {
                            s4 += nums[n];
                        }
                        if (s3 == s4) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


/*
Difficulty:Medium
Total Accepted:2.4K
Total Submissions:6.7K


Companies Alibaba
Related Topics Array

*/
