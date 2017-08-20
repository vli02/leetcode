/*
198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/

int robx(int *nums, int numsSize, int *t) {
    int k1 = 0, k2 = 0;
    
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    
    if (t[2] == -1) {
        t[2] = robx(&nums[2], numsSize - 2, &t[2]);
    }
    k1 = nums[0] + t[2];
    if (t[1] == -1) {
        t[1] = robx(&nums[1], numsSize - 1, &t[1]);
    }
    k2 = t[1];
    
    return k1 > k2 ? k1 : k2;
}
​
int rob(int* nums, int numsSize) {
#if 0
    int k = 0;
    int *t;
    
    if (numsSize == 0) return 0;
    
    t = malloc(numsSize * sizeof(int));
    if (!t) return 0;
    memset(t, -1, numsSize * sizeof(int));
​
    k = robx(nums, numsSize, t);
    
    free(t);
    
    return k;
#else
    int i;
    int rob_p_p, rob_p, dont_rob_p;
    int rob_this, dont_rob_this;
    
    rob_p_p = rob_p = dont_rob_p = 0;
    rob_this = dont_rob_this = 0;
    
    for (i = 0; i < numsSize; i ++) {
        rob_this = nums[i] + ((rob_p_p > dont_rob_p) ? rob_p_p : dont_rob_p);
        dont_rob_this = (rob_p > dont_rob_p) ? rob_p : dont_rob_p;
        rob_p_p = rob_p;
        rob_p = rob_this;
        dont_rob_p = dont_rob_this;
    }
    
    return rob_this > dont_rob_this ? rob_this : dont_rob_this;
#endif
}


/*
Difficulty:Easy
Total Accepted:145.8K
Total Submissions:375.1K


Companies LinkedIn Airbnb
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Maximum Product Subarray
                  
                    House Robber II
                  
                    Paint House
                  
                    Paint Fence
                  
                    House Robber III
                  
                    Non-negative Integers without Consecutive Ones
                  
                    Coin Path
*/
