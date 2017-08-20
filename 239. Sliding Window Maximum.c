/*
239. Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getmax(int *nums, int k) {
    int i;
    int max = nums[0];
    for (i = 1; i < k; i ++) {
        if (max < nums[i]) max = nums[i];
    }
    return max;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int max = 0, i;
    int *buff;
    
    if (!numsSize) return NULL;
    *returnSize = numsSize - k + 1;
    
    buff = malloc((*returnSize) * sizeof(int));
    //assert(buff);
    buff[0] = getmax(&nums[0], k);
    for (i = 1; i + k <= numsSize; i ++) {
        if (buff[i - 1] < nums[i + k - 1]) {
            buff[i] = nums[i + k - 1];
        } else if (buff[i - 1] == nums[i - 1]) {
            buff[i] = getmax(&nums[i], k);
        } else {
            buff[i] = buff[i - 1];
        }
    }
    return buff;
}


/*
Difficulty:Hard
Total Accepted:65.1K
Total Submissions:197.6K


Companies Amazon Google Zenefits
Related Topics Heap
Similar Questions 
                
                  
                    Minimum Window Substring
                  
                    Min Stack
                  
                    Longest Substring with At Most Two Distinct Characters
                  
                    Paint House II
*/
