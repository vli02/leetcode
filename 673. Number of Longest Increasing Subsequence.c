/*
673. Number of Longest Increasing Subsequence

Given an unsorted array of integers, find the number of longest increasing subsequence.


Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].



Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.



Note:
Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/

int findNumberOfLIS(int* nums, int numsSize) {
    int i, j, k, res = 0, max_len = 0;
    int *tmp, *len, *cnt;
    
    if (numsSize == 0) return 0;
    
    tmp = calloc(numsSize * 2, sizeof(int));
    //assert(tmp);
    len = &tmp[0];
    cnt = &tmp[numsSize];
    
    for (i = 0; i < numsSize; i ++) {
        len[i] = cnt[i] = 1;
        for (j = 0; j < i; j ++) {
            if (nums[i] > nums[j]) {
                if (len[i] < len[j] + 1) {
                    // reset the length and count
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[i] == len[j] + 1) {
                    // current summary
                    cnt[i] += cnt[j];
                }
            }
        }
        
        if (max_len < len[i]) {
            max_len = len[i];   // reset
            res = cnt[i];
        } else if (max_len == len[i]) {
            res += cnt[i];      // total
        }
    }
    
    free(tmp);
    
    return res;
}


/*
Difficulty:Medium
Total Accepted:5.4K
Total Submissions:17.4K


Companies Facebook
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Longest Increasing Subsequence
                  
                    Longest Continuous Increasing Subsequence
*/
