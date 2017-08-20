/*
34. Search for a Range

Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].


For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, *range;
    int start, end, mid;
    
    range = malloc(2 * sizeof(int));
    //assert(range);
    
    *returnSize = 2;
    range[0] = range[1] = -1;
    
#if 0
    // O(n2)
    for (i = 0; i < numsSize; i ++) {
        if (range[0] == -1) {
            if (nums[i] == target) {
                range[0] = range[1] = i;
            } else if (nums[i] > target) {
                break;
            }
        } else if (nums[i] == target) {
            range[1] = i;
        } else {
            break;
        }
    }
#else
    i = -1;
    start = 0; end = numsSize - 1;
    while (i == -1 && start <= end) {
        mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            i = j = mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    while (i >= 0 && nums[i] == target) {
        range[0] = i;
        i --;
    }
    while (j >= 0 && j < numsSize && nums[j] == target) {
        range[1] = j;
        j ++;
    }
#endif
    return range;
}


/*
Difficulty:Medium
Total Accepted:145.4K
Total Submissions:463.3K


Companies LinkedIn
Related Topics Binary Search Array
Similar Questions 
                
                  
                    First Bad Version
*/
