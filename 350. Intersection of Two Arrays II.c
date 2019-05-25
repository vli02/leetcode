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
#if 1
typedef struct e_s {
    int val;
    int cnt;
    struct e_s *shadow;
} e_t;
#define HF  1021
e_t *lookup(e_t **ht, int v) {
    int hc = v % HF;
    e_t *e = ht[hc];
    while (e && e->val != v) e = e->shadow;
    return e;
}
void insert(e_t **ht, e_t *e) {
    int hc = e->val % HF;
    e->shadow = ht[hc];
    ht[hc] = e;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    e_t *e, *buff, *ht[HF] = { 0 };
    int i, v;
    int k, *result;
    
    if (nums1Size > nums2Size) {
        return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
    }
    
    *returnSize = 0;
    if (!nums1Size || !nums2Size) {
        return NULL;
    }
    
    buff = malloc(nums2Size * sizeof(e_t));
    //assert(buff);
    for (i = 0; i < nums2Size; i ++) {
        v = nums2[i];
        e = lookup(ht, v);
        if (e) e->cnt ++;
        else {
            e = &buff[i];
            e->val = v;
            e->cnt = 1;
            insert(ht, e);
        }
    }
    
    k = 0;
    result = malloc(nums1Size * sizeof(int));
    //assert(result);
    
    for (i = 0; i < nums1Size; i ++) {
        v = nums1[i];
        e = lookup(ht, v);
        if (e && e->cnt > 0) {
            result[k ++] = v;
            e->cnt --;
        }
    }
    
    free(buff);
    
    *returnSize = k;
    return result;
}
#else
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i, j, k;
    int *result, *flags;
    
    if (nums1Size > nums2Size) {
        return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
    }
    
    *returnSize = 0;
    if (!nums1Size || !nums2Size) {
        return NULL;
    }
    
    result = malloc(nums1Size * sizeof(int));
    flags  = calloc(nums2Size, sizeof(int));
    //assert(result && flags);
    
    k = 0;
    for (i = 0; i < nums1Size; i ++) {
        for (j = 0; j < nums2Size; j ++) {
            if (!flags[j] && nums1[i] == nums2[j]) {
                result[k++] = nums1[i];
                flags[j] = 1;
                break;
            }
        }
    }
    
    *returnSize = k;
    free(flags);
    return result;
}
#endif


/*
Difficulty:Easy
Total Accepted:72K
Total Submissions:161.4K


Related Topics Binary Search Hash Table Two Pointers Sort
Similar Questions Intersection of Two Arrays

*/
