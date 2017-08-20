/*
448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *p;
    int i, j, x;
    
    p = malloc(numsSize * sizeof(int));
    //assert(p);
    for (i = 0; i < numsSize; i ++) {
        x = nums[i];
        x = (x > 0) ? x - 1 : 0 - x - 1;
        if (nums[x] > 0) nums[x] = 0 - nums[x];
    }
    j = 0;
    for (i = 1; i <= numsSize; i ++) {
        if (nums[i - 1] > 0) {
            p[j ++] = i;
        }
    }
    *returnSize = j;
    return p;
}


/*
Difficulty:Easy
Total Accepted:54.4K
Total Submissions:106K


Companies Google
Related Topics Array
Similar Questions 
                
                  
                    First Missing Positive
                  
                    Find All Duplicates in an Array
*/
