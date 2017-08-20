/*
88. Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.


Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

void merge(int* nums1, int m, int* nums2, int n) {
    int k = m + n - 1;
    m --;
    n --;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            nums1[k--] = nums1[m--];
        }
        nums1[k--] = nums2[n--];
    }
}


/*
Difficulty:Easy
Total Accepted:175.3K
Total Submissions:547.7K


Companies Microsoft Bloomberg Facebook
Related Topics Array Two Pointers
Similar Questions 
                
                  
                    Merge Two Sorted Lists
*/
