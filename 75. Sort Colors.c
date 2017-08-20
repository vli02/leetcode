/*
75. Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.



Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.



Note:
You are not suppose to use the library's sort function for this problem.


click to show follow up.


Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with an one-pass algorithm using only constant space?
*/

void sortColors(int* nums, int numsSize) {
    int l, m, r, k;
    
    l = m = 0;
    r = numsSize - 1;
    
    while (m <= r) {
        k = nums[m];
        if (k < 1) {  // red - swap left and middle, then advance both pointers
            nums[m] = nums[l];
            nums[l] = k;
            l ++; m ++;
        } else if (k > 1) {  // blue - swap right and middle, then shrink right pointer
            nums[m] = nums[r];
            nums[r] = k;
            r --;
        } else {  // white - advance middle
            m ++;
        } 
    }
}


/*
Difficulty:Medium
Total Accepted:169.6K
Total Submissions:447.1K


Companies Pocket Gems Microsoft Facebook
Related Topics Array Two Pointers Sort
Similar Questions 
                
                  
                    Sort List
                  
                    Wiggle Sort
                  
                    Wiggle Sort II
*/
