/*
136. Single Number

Given an array of integers, every element appears twice except for one. Find that single one.


Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

int singleNumber(int* nums, int numsSize) {
    int i, k = 0;
    for (i = 0; i < numsSize; i ++) {
        k = k ^ nums[i];  // a ^ a equals to 0; 0 ^ a equals to a
    }
    return k;
}


/*
Difficulty:Easy
Total Accepted:231K
Total Submissions:424.5K


Companies Palantir Airbnb
Related Topics Hash Table Bit Manipulation
Similar Questions 
                
                  
                    Single Number II
                  
                    Single Number III
                  
                    Missing Number
                  
                    Find the Duplicate Number
                  
                    Find the Difference
*/
