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
    
    i = j = -1;
    start = 0; end = numsSize - 1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            i = j = mid;
            while (i > 0 && nums[i - 1] == target) {
                i --;
            }
            while (j < numsSize - 1 && nums[j + 1] == target) {
                j ++;
            }
            break;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    range[0] = i;
    range[1] = j;
    
    *returnSize = 2;
    
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
