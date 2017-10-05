/*
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.


For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.


Your algorithm should run in O(n2) complexity.


Follow up: Could you improve it to O(n log n) time complexity? 

Credits:Special thanks to @pbrother for adding this problem and creating all test cases.
*/

int lower_bound(int *lens, int start, int end, int last, int k) {
    int mid;
    
    if (start > end) {
        // locate the first one which is not less than current number
        if (start <= last && lens[start] > lens[last]) {
            start ++;
        }
        return start;
    }
    
    mid = start + (end - start) / 2;
    
    if (lens[mid] == k) return mid;
    
    if (lens[mid] > k) return lower_bound(lens, start, mid - 1, last, k);
    
    return lower_bound(lens, mid + 1, end, last, k);
}
int lengthOfLIS(int* nums, int numsSize) {
    int *lens, max, i, j;
    
    if (numsSize == 0) return 0;
    
    lens = malloc(numsSize * sizeof(int));
    //assert(lens);
    
    max = 1;
    
#if 0   // O(n^2)   19ms
    for (i = 0; i < numsSize; i ++) {
        lens[i] = 1;
        for (j = 0; j < i; j ++) {
            if (nums[j] < nums[i] &&
                lens[i] < lens[j] + 1) {
                lens[i] = lens[j] + 1;
            }
        }
        if (max < lens[i]) max = lens[i];
    }
#else   // O(nlogn) 3ms
    int end = 0;
    
    lens[end] = nums[0];
    
    for (i = 1; i < numsSize; i ++) {
        j = lower_bound(lens, 0, end, end, nums[i]);
        lens[j] = nums[i];
        end = (j > end) ? j : end;
    }
    max = end + 1;
#endif
    
    free(lens);
    
    return max;
}

/*
Difficulty:Medium
Total Accepted:85.2K
Total Submissions:222.2K


Companies Microsoft
Related Topics Dynamic Programming Binary Search
Similar Questions 
                
                  
                    Increasing Triplet Subsequence
                  
                    Russian Doll Envelopes
                  
                    Maximum Length of Pair Chain
*/
