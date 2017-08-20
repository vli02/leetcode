/*
350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.


Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].


Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.



Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int big, small, i, j, k;
    int *bp, *sp;
    int *result, *flags;
​
    *returnSize = 0;
    
    if (!nums1Size || !nums2Size) {
        return NULL;
    }
    
    if (nums1Size > nums2Size) {
        big = nums1Size;
        bp = nums1;
        small = nums2Size;
        sp = nums2;
    } else {
        big = nums2Size;
        bp = nums2;
        small = nums1Size;
        sp = nums1;
    }
    
    result = malloc(small * sizeof(int));
    flags  = calloc(big, sizeof(int));
    if (!result || !flags) {
        return NULL;
    }
    
    k = 0;
    
    i = 0;
    while (i < small) {
        j = 0;
        while (j < big) {
            if (!flags[j] && sp[i] == bp[j]) {
                result[k++] = sp[i];
                flags[j] = 1;
                break;
            }
            j ++;
        }
        i ++;
    }
    *returnSize = k;
    free(flags);
    return result;
}


/*
Difficulty:Easy
Total Accepted:72K
Total Submissions:161.4K


Related Topics Binary Search Hash Table Two Pointers Sort
Similar Questions Intersection of Two Arrays

*/
