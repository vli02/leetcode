/*
229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int *r;
    int m[2] = { 0 };
    int c[2] = { 0 };
    int f = 1;
    int i, j, x;
    
    *returnSize = 0;
    r = malloc(2 * sizeof(int));
    if (!r) return NULL;
    
    i = 0;
    while (i < numsSize) {
        if (m[0] == nums[i]) {
            c[0] ++;
        } else if (m[1] == nums[i]) {
            c[1] ++;
            f = 2;
        } else if (c[0] == 0) {
            m[0] = nums[i];
            c[0] = 1;
        } else if (c[1] == 0) {
            m[1] = nums[i];
            c[1] = 1;
            f = 2;
        } else {
            c[0] --;
            c[1] --;
        }
        
        i ++;
    }
    
    j = 0;
    while (f > 0) {
        f --;
        x = 0;
        i = 0;
        while (i < numsSize) {
            if (m[f] == nums[i]) {
                x ++;
            }
            i ++;
        }
        if (x > numsSize / 3) {
            *returnSize += 1;
            r[j] = m[f];
            j ++;
        }
    }
    
    return r;
}


/*
Difficulty:Medium
Total Accepted:57.4K
Total Submissions:200.9K


Companies Zenefits
Related Topics Array
Similar Questions 
                
                  
                    Majority Element
*/
