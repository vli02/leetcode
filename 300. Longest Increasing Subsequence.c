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

int lower_bound(int *p, int start, int end, int k) {
    int mid;
    
    if (start > end) {
        return start;
    }
    
    mid = start + (end - start) / 2;
    
    if (p[mid] == k) return mid;
    
    if (p[mid] > k) return lower_bound(p, start, mid - 1, k);
    
    return lower_bound(p, mid + 1, end, k);
}
int lengthOfLIS(int* nums, int numsSize) {
    int *lens, max, i, j;
    
    if (numsSize == 0) return 0;
    
    lens = malloc(numsSize * sizeof(int));
    //assert(lens);
    
    max = 1;
    
#if 0   // O(n^2)   19ms
    for (i = 0; i < numsSize; i ++) {
        lens[i] = 1;                    // starts from 1
        for (j = 0; j < i; j ++) {
            if (nums[i] > nums[j] &&        // a small number is ahead
                lens[i] < lens[j] + 1) {    //
                lens[i] = lens[j] + 1;      // increase 1
            }
        }
        if (max < lens[i]) max = lens[i];
    }
#else   // O(nlogn) 3ms
    int last = 0;
    int *p = lens;      // p is array of sorted numbers
    
    // initialize p with the first num
    p[0] = nums[0];
    // for the rest of nums
    for (i = 1; i < numsSize; i ++) {
        // find proper location of num in sorted array p
        j = lower_bound(p, 0, last, nums[i]);
        // save it in p
        p[j] = nums[i];
        if (last < j) last = j;
    }
    max = last + 1;  // the length of final p is the answer
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
