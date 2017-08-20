/*
215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.


Note: 
You may assume k is always valid, 1 ? k ? array's length.

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

int comp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
int msort(int *nums, int left, int right, int m) {
    int i, j, k;
    i = left;
    j = right;
    k = nums[i];
    while (i < j) {
        while (i < j && nums[j] <= k) {
            j --;
        }
        if (i < j) {
            nums[i] = nums[j];
            i ++;
        }
        while (i < j && nums[i] >= k) {
            i ++;
        }
        if (i < j) {
            nums[j] = nums[i];
            j --;
        }
    }
    if (i > left) {
        nums[i] = k;
    }
    if (i == m) return nums[i];
    else if (i < m) return msort(nums, i + 1, right, m);
    else return msort(nums, left, i - 1, m);
}
int findKthLargest(int* nums, int numsSize, int k) {
#if 0  // 6ms
    qsort(nums, numsSize, sizeof(int), comp);
    return nums[k - 1];
#else  // 13ms
    return msort(nums, 0, numsSize - 1, k - 1);
#endif
}


/*
Difficulty:Medium
Total Accepted:143K
Total Submissions:365.2K


Companies Facebook Amazon Microsoft Apple Bloomberg Pocket Gems
Related Topics Heap Divide and Conquer
Similar Questions 
                
                  
                    Wiggle Sort II
                  
                    Top K Frequent Elements
                  
                    Third Maximum Number
*/
