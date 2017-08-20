/*
163. Missing Ranges

Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.


For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize) {
    char **p, *buff;
    int psz, hi, i;
    
    psz = 10;
    p = malloc(psz * sizeof(char *));
    //assert(p);
​
    *returnSize = 0;
    
    i = 0;
    while (i < numsSize) {
        if (lower < nums[i]) {
            // add lower ... min(nums[i] - 1, upper) to the buff;
            buff = calloc(32, sizeof(char)); // 32 bytes
            // assert(buff);
            hi = (nums[i] - 1) < upper ? (nums[i] - 1) : upper;
            if (lower == hi) {
                sprintf(buff, "%d", lower);
            } else {
                sprintf(buff, "%d->%d", lower, hi);
            }
            if (*returnSize == psz) {
                psz = psz * 2;
                p = realloc(p, psz * sizeof(char *));
                //assert(p);
            }
            p[*returnSize] = buff;
            (*returnSize) ++;
        }
        if (nums[i] >= upper) goto done;
        lower = nums[i] + 1;
        i ++;
    }
    if (lower <= upper) {
        // add lower ... min(nums[i] - 1, upper) to the buff;
        buff = calloc(32, sizeof(char)); // 32 bytes
        // assert(buff);
        if (lower == upper) {
            sprintf(buff, "%d", lower);
        } else {
            sprintf(buff, "%d->%d", lower, upper);
        }
        if (*returnSize == psz) {
            psz ++;
            p = realloc(p, psz * sizeof(char *));
            //assert(p);
        }
        p[*returnSize] = buff;
        (*returnSize) ++;
    }
done:
    if (*returnSize == 0) {
        free(p);
        p = NULL;
    }
    return p;
}


/*
Difficulty:Medium
Total Accepted:29.4K
Total Submissions:120K


Companies Google
Related Topics Array
Similar Questions 
                
                  
                    Summary Ranges
*/
