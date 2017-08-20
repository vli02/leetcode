/*
26. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.


Do not allocate extra space for another array, you must do this in place with constant memory.



For example,
Given input array nums = [1,1,2],


Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(int* nums, int numsSize) {
    int i, j;
    
    if (numsSize < 2) return numsSize;
    
    for (i = 0, j = 1; j < numsSize; j ++) {
        if (nums[j] != nums[i]) {
            i ++;
            nums[i] = nums[j];
        }
    }
    
    return i + 1;
}


/*
Difficulty:Easy
Total Accepted:249.5K
Total Submissions:703.3K


Companies Microsoft Bloomberg Facebook
Related Topics Array Two Pointers
Similar Questions 
                
                  
                    Remove Element
*/
