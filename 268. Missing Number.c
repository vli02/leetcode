/*
268. Missing Number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.


For example,
Given nums = [0, 1, 3] return 2.



Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

int missingNumber(int* nums, int numsSize) {
    int i, k;
#if 0
    k = numsSize;
    for (i = 0; i < numsSize; i ++) {
        k = k ^ i ^ nums[i];
    }
#else
    k = numsSize * (numsSize + 1) / 2;
    for (i = 0; i < numsSize; i ++) {
        k -= nums[i];
    }
#endif
    return k;
}


/*
Difficulty:Easy
Total Accepted:125.4K
Total Submissions:283.6K


Companies Microsoft Bloomberg
Related Topics Array Math Bit Manipulation
Similar Questions 
                
                  
                    First Missing Positive
                  
                    Single Number
                  
                    Find the Duplicate Number
*/
