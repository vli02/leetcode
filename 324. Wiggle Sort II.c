/*
324. Wiggle Sort II

Given an unsorted array nums, reorder it such that
    nums[0] < nums[1] > nums[2] < nums[3]....



    Example:
    (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
    (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].



    Note:
    You may assume all input has valid answer.



    Follow Up:
    Can you do it in O(n) time and/or in-place with O(1) extra space?


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

int cmp1(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
void msort(int *nums, int left, int right, int m) {
    int i, j, k;
    
    i = left;
    j = right;
    k = nums[i];
    while (i < j) {
        while (i < j && nums[j] >= k) {
            j --;  // find a number less than key from tail <-
        }
        if (i < j) {
            nums[i] = nums[j];  // put this small number to the left
            i ++;
        }
        while (i < j && nums[i] <= k) {
            i ++;  // find a number greater than key from head ->
        }
        if (i < j) {
            nums[j] = nums[i];  // put this greater number to the right
            j --;
        }
    }
    if (i > left) {
        nums[i] = k;
    }
    
    if (i > m) msort(nums, left, i - 1, m);
    else if (i < m) msort(nums, i + 1, right, m);
}
void wiggleSort(int* nums, int numsSize) {
    int i, m, k;
    
#if 0  // this is 56ms
    int *tmp;

    qsort(nums, numsSize, sizeof(int), cmp1); // no need to sort completely
    
    tmp = malloc(numsSize * sizeof(int));  // O(n) memory
    
    m = (numsSize + 1) / 2 ;
    k = numsSize;
    for (i = 0; i < numsSize; i ++) {
        if (i % 2) tmp[i] = nums[-- k];
        else       tmp[i] = nums[-- m];
    }
    
    memcpy(nums, tmp, numsSize * sizeof(int));
    free(tmp);
#else  // this is 93ms :)
#define IDX(N) ((1 + 2 * (N)) % (numsSize | 1))
    int r, c;
    
    m = (numsSize - 1) / 2;
#if 0
    msort(nums, 0, numsSize - 1, m);
#else
    qsort(nums, numsSize, sizeof(int), cmp1); // no need to sort completely
#endif
    
    k = nums[m];  // median number
    //printf("%d\n", k);
    i = m = 0;         // left, current
    r = numsSize - 1;  // right
    while (m <= r) {
        c = nums[IDX(m)];
        if (c > k) {
            // swap left and current, advance left and current
            nums[IDX(m)] = nums[IDX(i)];
            nums[IDX(i)] = c;
            i ++; m ++;
        } else if (c < k) {
            // swap current and right, reduce right
            nums[IDX(m)] = nums[IDX(r)];
            nums[IDX(r)] = c;
            r --;
        } else {
            // advance current
            m ++;
        }
    }
#endif
}

/*
Difficulty:Medium
Total Accepted:30.3K
Total Submissions:116.5K


Companies Google
Related Topics Sort
Similar Questions 
                
                  
                    Sort Colors
                  
                    Kth Largest Element in an Array
                  
                    Wiggle Sort
*/
