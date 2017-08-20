/*
228. Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.


For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void ranges(int *nums, int numsz, int ***pp, int *sz, int *n) {
    int a, b;
    int i, l;
    char buff[64];
    
    if (numsz == 0) return;
    
    if (*n == *sz) {
        (*sz) *= 2;
        (*pp) = realloc(*pp, (*sz) * sizeof(char *));
        //assert(*pp);
    }
    b = a = nums[0];
    i = 1;
    while (i < numsz && (b + 1) == nums[i]) {
        i ++; b ++;
    }
    l = sprintf(buff, "%d", a);
    if (i > 1) {
        l += sprintf(&buff[l], "->%d", b);
    }
    
    (*pp)[*n] = malloc((l + 1) * sizeof(char));
    strcpy((*pp)[*n], buff);
    (*n) ++;
    
    ranges(&nums[i], numsz - i, pp, sz, n);
}
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    int sz, n;
    char **p;
    
    *returnSize = 0;
    if (numsSize == 0) return NULL;
    
    sz = 100;
    p = malloc(sz * sizeof(char *));
    //assert(p);
    
    n = 0;
    ranges(nums, numsSize, &p, &sz, &n);
    
    *returnSize = n;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:81.3K
Total Submissions:273.2K


Companies Google
Related Topics Array
Similar Questions 
                
                  
                    Missing Ranges
                  
                    Data Stream as Disjoint Intervals
*/
