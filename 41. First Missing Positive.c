/*
41. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.



For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.



Your algorithm should run in O(n) time and uses constant space.
*/

int firstMissingPositive(int* nums, int numsSize) {
    int i, k, t;
    for (i = 0; i < numsSize; i ++) {
        k = nums[i];
        while (k > 0 && k < numsSize && k != nums[k - 1]) {
            nums[i] = nums[k - 1];
            nums[k - 1] = k;
            k = nums[i];
        }
    }
    for (i = 0; i < numsSize; i ++) {
        if (nums[i] != i + 1) break;
    }
    return i + 1;
}


/*
Difficulty:Hard
Total Accepted:104.4K
Total Submissions:409.1K


Related Topics Array
Similar Questions Missing Number Find the Duplicate Number Find All Numbers Disappeared in an Array

*/
