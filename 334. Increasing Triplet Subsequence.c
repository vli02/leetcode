/*
334. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.


Formally the function should:
Return true if there exists i, j, k  
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 
else return false.



Your algorithm should run in O(n) time complexity and O(1) space complexity.


Examples:
Given [1, 2, 3, 4, 5],
return true.


Given [5, 4, 3, 2, 1],
return false.


Credits:Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/

bool increasingTriplet(int* nums, int numsSize) {
    int min1, min2, i, k;
    
    min1 = min2 = 0x7fffffff;
    
    for (i = 0; i < numsSize; i ++) {
        k = nums[i];
        if (k <= min1) {
            min1 = k;
        } else if (k <= min2) {
            min2 = k;
        } else {
            return true;
        }
    }
    
    return false;
}


/*
Difficulty:Medium
Total Accepted:43.3K
Total Submissions:110.5K


Companies Facebook
Similar Questions Longest Increasing Subsequence

*/
