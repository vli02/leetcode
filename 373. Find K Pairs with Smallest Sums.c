/*
373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k. 


Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.


Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]



Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]



Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]



Credits:Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int** columnSizes, int* returnSize) {
    int n, **p, *buff, x;
    int i, j, l, r, c, *rn_on_col;  // current row number on each column
​
    *returnSize = 0;
    if (k <= 0 || nums1Size == 0 || nums2Size == 0) return NULL;
    
    n = nums1Size * nums2Size;
    if (n > k) n = k;
    p = malloc(n * sizeof(int *));
    rn_on_col = malloc(nums2Size * sizeof(int));
    // assert(p && rn_on_col);
    memset(rn_on_col, -1, nums2Size * sizeof(int));
    
    x = r = c = 0;
    buff = malloc(2 * sizeof(int));
    //assert(buff);
    buff[0] = nums1[r];
    buff[1] = nums2[c];
    p[x ++] = buff;
    rn_on_col[c] = r;
    while (-- n) {
        r = nums1Size - 1;
        c = nums2Size - 1;
        l = 0;
        i = 1;
        for (j = 0; j < nums2Size && i != 0; j ++) {
            i = rn_on_col[j] + 1;
            if (i < nums1Size &&
                i != l &&
                nums1[i] + nums2[j] < nums1[r] + nums2[c]) {
                r = i; c = j;
            }
            l = i;
        }
        buff = malloc(2 * sizeof(int));
        //assert(buff);
        buff[0] = nums1[r];
        buff[1] = nums2[c];
        p[x ++] = buff;
        rn_on_col[c] = r;
    }
    
    *returnSize = x;
    *columnSizes = malloc(x * sizeof(int));
    //assert(*columnSize);
    for (i = 0; i < x; i ++) {
        (*columnSizes)[i] = 2;
    }
    
    free(rn_on_col);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:29.4K
Total Submissions:95.9K


Companies Google Uber
Related Topics Heap
Similar Questions 
                
                  
                    Kth Smallest Element in a Sorted Matrix
*/
