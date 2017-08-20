/*
80. Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?


For example,
Given sorted array nums = [1,1,1,2,2,3],


Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(int* nums, int numsSize) {
    int i, j;
    
    if (numsSize < 3) return numsSize;
    
    for (i = 2, j = 2; j < numsSize; j ++) {
        if (nums[j] != nums[i - 2]) {
            nums[i] = nums[j];
            i ++;
        }
    }
    
    return i;
}


/*
Difficulty:Medium
Total Accepted:122.8K
Total Submissions:341.5K


Companies Facebook
Related Topics Array Two Pointers

*/
