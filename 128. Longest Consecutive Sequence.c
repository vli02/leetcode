/*
128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.


For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.


Your algorithm should run in O(n) complexity.
*/

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int longestConsecutive(int* nums, int numsSize) {
    int i, l, len = 1;
    
    if (!numsSize) return 0;
    
#if 1 // O(nlogn)
    qsort(nums, numsSize, sizeof(int), cmp);
    
    l = 1;
    for (i = 1; i < numsSize; i ++) {
        if (nums[i] == nums[i - 1]) {
        } else if (nums[i] == nums[i - 1] + 1) {
            l ++;
        } else {
            l = 1;
        }
        if (len < l) len = l;
    }
#else
    // make a hash table to store the length of consecutive of current number
    // and update the length of consecutive of left and right boundary
#endif
​
    return len;
}


/*
Difficulty:Hard
Total Accepted:109K
Total Submissions:296.1K


Companies Google Facebook
Related Topics Array Union Find
Similar Questions 
                
                  
                    Binary Tree Longest Consecutive Sequence
*/
