/*
280. Wiggle Sort

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....


For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

int qf(void *a, void *b) {
    return *(int *)a - *(int *)b;
}
void wiggleSort(int* nums, int numsSize) {
    int i, j, k;
#if 0
    qsort(nums, numsSize, sizeof(int), qf);
    for (i = 1; i < numsSize - 1; i += 2) {
        k = nums[numsSize - 1];
        for (j = numsSize - 1; j > i; j --) {
            nums[j] = nums[j - 1];
        }
        nums[i] = k;
    }
#else
    for (i = 1; i < numsSize; i ++) {
        if (!((i % 2) ^ (nums[i - 1] > nums[i]))/* ||
            (!(i % 2) && (nums[i - 1] < nums[i]))*/) {
            k = nums[i - 1];
            nums[i - 1] = nums[i];  // swap
            nums[i] = k;
        }
    }
#endif
}


/*
Difficulty:Medium
Total Accepted:29.9K
Total Submissions:52.5K


Companies Google
Related Topics Array Sort
Similar Questions 
                
                  
                    Sort Colors
                  
                    Wiggle Sort II
*/
