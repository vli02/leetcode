/*
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.


Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

int findPeakElement(int* nums, int numsSize) {
#if 0
    int i;
    
    for (i = 1; i < numsSize && nums[i] > nums[i - 1]; i ++) {
    }
    
    return i - 1;
#else
    int l, r, m;
    if (numsSize == 1) return 0;
    
    l = 0; r = numsSize - 1;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[m] < nums[m + 1]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    return l;
#endif
}


/*
Difficulty:Medium
Total Accepted:119.1K
Total Submissions:318.1K


Companies Microsoft Google
Related Topics Binary Search Array

*/
