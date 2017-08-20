/*
167. Two Sum II - Input array is sorted

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.


Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *result;
    int i, j, total;
​
    result = malloc(2 * sizeof(int));
    //assert(result);
​
    *returnSize = 0;
​
    i = 0;
    j = numbersSize - 1;
    while (i < j) {
        total = numbers[i] + numbers[j];
        if (total > target) {
            j --;
        } else if (total < target) {
            i ++;
        } else {
            result[0] = i + 1;
            result[1] = j + 1;
            *returnSize = 2;
            break;
        }
    }
​
    return result;
}


/*
Difficulty:Easy
Total Accepted:90.5K
Total Submissions:192.5K


Companies Amazon
Related Topics Array Two Pointers Binary Search
Similar Questions 
                
                  
                    Two Sum
                  
                    Two Sum IV - Input is a BST
*/
