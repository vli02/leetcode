/*
260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.


For example:


Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].


Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?



Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int i, k, a, b, *p;
    
    k = 0;
    for (i = 0; i < numsSize; i ++) {
        k ^= nums[i];
    }
    
    k = k & ~(k - 1);
    a = b = 0;
    for (i = 0; i < numsSize; i ++) {
        if (nums[i] & k) {
            a ^= nums[i];
        } else {
            b ^= nums[i];
        }
    }
    
    p = malloc(2 * sizeof(int));
    p[0] = a;
    p[1] = b;
    *returnSize = 2;
    return p;
}


/*
Difficulty:Medium
Total Accepted:69.2K
Total Submissions:134.3K


Related Topics Bit Manipulation
Similar Questions Single Number Single Number II

*/
