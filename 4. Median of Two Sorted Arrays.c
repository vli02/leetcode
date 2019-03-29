/*
4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0



Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

int bs(int *n, int sz, int k) {
    int i, j, m;
    i = 0;
    j = sz - 1;
    while (i <= j) {
        m = i + (j - i) / 2;
        if (n[m] > k) {
            j = m - 1;
        } else {
            i = m + 1;
        }
    }
    return j;
}
double bs2(int *n1, int sz1, int *n2, int sz2, int m, int m1) {
    double d;
    int i;
    i = bs(n1, sz1, n2[0]);
    if (i >= m) {
        d = n1[m];
        if (m1) {
            if (i > m) {
                d += n1[m + 1];
            } else {
                d += n2[0];
            }
            d /= 2;
        }
    } else if (i == sz1 - 1) {
        d = n2[m - i - 1];
        if (m1) {
            d += n2[m - i];
            d /= 2;
        }
    } else {
        d = bs2(n2, sz2, &n1[i + 1], sz1 - i - 1, m - i - 1, m1);
    }
    return d;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double d;
#if 0  // sliding & binary search
    int i1_left = 0, i1_right = nums1Size;
    int i1, i2;
    
    if (nums1Size > nums2Size) {  // make nums1 as a short array
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    // O(log(min(m, n)))
    while (i1_left <= i1_right) {
        i1 = i1_left + (i1_right - i1_left) / 2;
        i2 = (nums1Size + nums2Size + 1) / 2 - i1;
        if (i1 > 0 && nums1[i1 - 1] > nums2[i2]) {
            i1_right = i1 - 1;
        } else if (i1 < nums1Size && nums1[i1] < nums2[i2 - 1]) {
            i1_left = i1 + 1;
        } else {
            // found it!
            if (i1 == 0) d = nums2[i2 - 1];
            else if (i2 == 0) d = nums1[i1 - 1];
            else if (nums1[i1 - 1] > nums2[i2 - 1]) d = nums1[i1 - 1];
            else d = nums2[i2 - 1];
            if (((nums1Size + nums2Size) % 2) == 0) {
                if (i2 == nums2Size) {
                    d = (d + nums1[i1]) / 2;
                } else if (i1 == nums1Size) {
                    d = (d + nums2[i2]) / 2;
                } else if (nums1[i1] < nums2[i2]) {
                    d = (d + nums1[i1]) / 2;
                } else {
                    d = (d + nums2[i2]) / 2;
                }
            }
            break;
        }
    }
#else // binary search 40+ms
    int p1, p2;
    
    p1 =  (nums1Size + nums2Size - 1) / 2;
    p2 = ((nums1Size + nums2Size) % 2) ? 0 : 1;
    
    if (nums2Size == 0) {
        d = nums1[p1];
        if (p2) {
            d += nums1[p1 + 1];
            d /= 2;
        }
        return d;
    }
    
    if (nums1Size == 0) {
        d = nums2[p1];
        if (p2) {
            d += nums2[p1 + 1];
            d /= 2;
        }
        return d;
    }

    if (nums2[0] < nums1[0]) return bs2(nums2, nums2Size, nums1, nums1Size, p1, p2);
    return bs2(nums1, nums1Size, nums2, nums2Size, p1, p2);
#endif
    
    return d;
}


/*
Difficulty:Hard
Total Accepted:182.7K
Total Submissions:839.6K


Companies Google Zenefits Microsoft Apple Yahoo Dropbox Adobe
Related Topics Binary Search Array Divide and Conquer

*/
