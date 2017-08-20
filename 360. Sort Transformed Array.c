/*
360. Sort Transformed Array

Given a sorted array of integers nums and integer values a, b and c.  Apply a function of the form f(x) = ax2 + bx + c to each element x in the array. 

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]



Credits:Special thanks to @elmirap for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortTransformedArray(int* nums, int numsSize, int a, int b, int c, int* returnSize) {
    int *p;
    int i, j, n;
    int k1, k2;
​
    *returnSize = numsSize;
    
    p  = malloc(numsSize * sizeof(int));
    
    i = 0; j = numsSize - 1;
    if (a > 0) {
        n = numsSize;
        while (i <= j) {
            k1 = (a * nums[i] + b) * nums[i] + c;
            k2 = (a * nums[j] + b) * nums[j] + c;
            if (k1 > k2) {
                p[-- n] = k1; i ++;
            } else {
                p[-- n] = k2; j --;
            }
        }
    } else {
        n = 0;
        while (i <= j) {
            k1 = (a * nums[i] + b) * nums[i] + c;
            k2 = (a * nums[j] + b) * nums[j] + c;
            if (k1 < k2) {
                p[n ++] = k1; i ++;
            } else {
                p[n ++] = k2; j --;
            }
        }
    }
    return p;
}


/*
Difficulty:Medium
Total Accepted:11.9K
Total Submissions:27.1K


Companies Google
Related Topics Math Two Pointers

*/
