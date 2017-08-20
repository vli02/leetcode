/*
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.


Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct data_s {
    int val;
    int idx;
} data_t;
int cmp(const void *a, const void *b) {
    return ((data_t *)a)->val - ((data_t *)b)->val;
}
int* twoSum(int* nums, int numsSize, int target) {
    int *indices;
    int i, j, k;
    
#if 0
    for (i = 0; i < numsSize - 1; i ++) {
        for (j = i + 1; j < numsSize; j ++) {
            if (nums[i] + nums[j] == target) {
                indices = malloc(2 * sizeof(int));
                //assert(indices);
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }
#else
    data_t *array;
    array = malloc((numsSize + 1) * sizeof(data_t));
    //assert(array);
    for (i = 0; i < numsSize; i ++) {
        array[i].val = nums[i];
        array[i].idx = i;
    }
    qsort(array, numsSize, sizeof(data_t), cmp);
    i = 0;
    j = numsSize - 1;
    while (i < j) {
        k = array[i].val + array[j].val;
        if (k == target) {
            indices = malloc(2 * sizeof(int));
            //assert(indices);
            indices[0] = array[i].idx;
            indices[1] = array[j].idx;
            free(array);
            return indices;
        } else if (k < target) {
            i ++;
        } else {
            j --;
        }
    }
    free(array);
#endif
    
    return NULL;
}


/*
Difficulty:Easy
Total Accepted:586.7K
Total Submissions:1.7M


Companies LinkedIn Uber Airbnb Facebook Amazon Microsoft Apple Yahoo Dropbox Bloomberg Yelp Adobe
Related Topics Array Hash Table
Similar Questions 
                
                  
                    3Sum
                  
                    4Sum
                  
                    Two Sum II - Input array is sorted
                  
                    Two Sum III - Data structure design
                  
                    Subarray Sum Equals K
                  
                    Two Sum IV - Input is a BST
*/
