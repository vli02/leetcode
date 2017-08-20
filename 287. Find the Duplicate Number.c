/*
287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.



Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.



Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

int findDuplicate(int* nums, int numsSize) {
    int slow, fast;
    
    slow = fast = 0;
    do {
        slow = nums[slow];          // one step
        fast = nums[nums[fast]];    // two steps
    } while (slow != fast);
    
    slow = 0;
    do {
        slow = nums[slow];
        fast = nums[fast];
    } while (slow != fast); // start of the cycle
    
    return slow;
}


/*
Difficulty:Medium
Total Accepted:75.7K
Total Submissions:174.4K


Companies Bloomberg
Related Topics Binary Search Array Two Pointers
Similar Questions 
                
                  
                    First Missing Positive
                  
                    Single Number
                  
                    Linked List Cycle II
                  
                    Missing Number
                  
                    Set Mismatch
*/
