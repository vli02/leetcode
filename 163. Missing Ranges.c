/*
163. Missing Ranges

Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.


For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **p;
    int sz;
    int n;
} res_t;
void add2res(res_t *res, int l, int h) {
    char *buff;
    buff = calloc(32, sizeof(char)); // 32 bytes
    // assert(buff);
    if (l == h) {
        sprintf(buff, "%d", l);
    } else {
        sprintf(buff, "%d->%d", l, h);
    }
    if (!res->sz) {
        res->sz = 10;
        res->p = malloc(res->sz * sizeof(char *));
        //assert(res->p);
    } else if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = buff;
}
char** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize) {
    res_t res = { 0 };
    int psz, hi, i;
    
    for (i = 0; i < numsSize; i ++) {
        if (lower < nums[i]) {
            // add (lower ... nums[i] - 1) to the buff;
            hi = nums[i] - 1;
            add2res(&res, lower, hi);
        }
        if (nums[i] >= upper) goto done;
        lower = nums[i] + 1;
    }
    
    if (lower <= upper) {
        // add (lower ... upper) to the buff;
        add2res(&res, lower, upper);
    }
    
done:
    *returnSize = res.n;
    
    return res.p;
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
