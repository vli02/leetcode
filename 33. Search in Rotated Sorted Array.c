/*
33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

int search(int* nums, int numsSize, int target) {
    int start, end, mid;
    start = 0; end = numsSize - 1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;
        if (nums[start] <= nums[mid]) { // first half are sorted
            if (target  >  nums[mid] || target < nums[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else { // second half are sorted
            if (target < nums[mid] || target > nums[end]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return -1;
}


/*
Difficulty:Medium
Total Accepted:184.4K
Total Submissions:574K


Companies LinkedIn Bloomberg Uber Facebook Microsoft
Related Topics Binary Search Array
Similar Questions 
                
                  
                    Search in Rotated Sorted Array II
                  
                    Find Minimum in Rotated Sorted Array
*/
