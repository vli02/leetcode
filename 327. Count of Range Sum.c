/*
327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.

    Range sum S(i, j) is defined as the sum of the elements in nums between indices i and 
    j (i ? j), inclusive.



    Note:
    A naive algorithm of O(n2) is trivial. You MUST do better than that.


    Example:
    Given nums = [-2, 5, -1], lower = -2, upper = 2,
    Return 3.
    The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

int count_and_sort(int sort, double *sum, int start, int end, int l, int h, double *tmp) {
    int mid;
    int n, i, j, k, x, stop;
​
    if (end - start <= 1) return 0;
​
    mid = start + (end - start) / 2;
​
    // divide
    n = count_and_sort(1, sum, start, mid, l, h, tmp) +
        count_and_sort(1, sum, mid,   end, l, h, tmp);
​
    // count
    x = 0;
    for (i = start; i < mid; i ++) {
        stop = 0;
        for (j = mid; !stop && j < end; j ++) {
            k = sum[j] - sum[i];
            // because the second part of sum are sorted, the inner loop can stop early.
            if (k > h) stop = 1;
            else if (k >= l) n ++;
        }
    }
​
    // merge sort
    if (sort) {
        i = start;
        j = mid;
        k = 0;
        while (i < mid && j < end) {
            if (sum[i] <= sum[j]) {
                tmp[k] = sum[i];
                i ++;
            } else {
                tmp[k] = sum[j];
                j ++;
            }
            k ++;
        }
        if (i < mid) memcpy(&tmp[k], &sum[i], (mid - i) * sizeof(sum[0]));
        if (j < end) memcpy(&tmp[k], &sum[j], (end - j) * sizeof(sum[0]));
        memcpy(&sum[start], tmp, (end - start) * sizeof(sum[0]));
    }
​
    return n;
}
int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    double *sum, *tmp;
    int i, j, k, n;
    
    sum = malloc((numsSize + 1) * sizeof(double));
    //assert(sum);
    
    sum[0] = 0;
    for (i = 0; i < numsSize; i ++) {
        sum[i + 1] = sum[i] + (double)nums[i];
    }
    
#if 0  // this is O(n^2) 169ms
    n = 0;
    for (i = 0; i < numsSize; i ++) {
        for (j = i + 1; j <= numsSize; j ++) {
            k = sum[j] - sum[i];
            if (k >= lower && k <= upper) n ++;
        }
    }
#else  // this is 285ms :)
    tmp = malloc((numsSize + 1) * sizeof(double));
    //assert(tmp);
    n = count_and_sort(0, sum, 0, numsSize + 1, lower, upper, tmp);
    free(tmp);
#endif
    
    free(sum);
    
    return n;
}


/*
Difficulty:Hard
Total Accepted:19.1K
Total Submissions:64.3K


Companies Google
Related Topics Divide and Conquer Binary Search Tree
Similar Questions 
                
                  
                    Count of Smaller Numbers After Self
                  
                    Reverse Pairs
*/
