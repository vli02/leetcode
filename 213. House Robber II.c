/*
213. House Robber II

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street. 

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*/

int robx(int *m, int *nums, int numsSize) {
    int k1 = 0, k2 = 0;
    
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    
    if (m[2] == -1) {
        m[2] = robx(&m[2], &nums[2], numsSize - 2);
    }
    k2 = nums[0] + m[2];
    if (m[1] == -1) {
        m[1] = robx(&m[1], &nums[1], numsSize - 1);
    }
    k1 = m[1];
    
    return k1 > k2 ? k1 : k2;
}
​
int rob(int* nums, int numsSize) {
    int *m, k1, k2;
    
    if (numsSize == 0) return 0;
    
    m = malloc(numsSize * sizeof(int));
    //assert(m);
​
    memset(m, -1, numsSize * sizeof(int));
    k1 = robx(m, &nums[0], numsSize - 1);  // exclude the last house
    memset(m, -1, numsSize * sizeof(int));
    k2 = robx(m, &nums[1], numsSize - 1);  // exclude the first house
    
    free(m);
    
    return k1 > k2 ? k1 : k2;
}


/*
Difficulty:Medium
Total Accepted:59K
Total Submissions:173.9K


Companies Microsoft
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    House Robber
                  
                    Paint House
                  
                    Paint Fence
                  
                    House Robber III
                  
                    Non-negative Integers without Consecutive Ones
                  
                    Coin Path
*/
