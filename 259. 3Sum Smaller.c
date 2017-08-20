/*
259. 3Sum Smaller

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]


Follow up:
Could you solve it in O(n2) runtime?
*/

int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}
int threeSumSmaller(int* nums, int numsSize, int target) {
    int i, x, y, k;
    int n = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 0; i < numsSize - 2; i ++) {
        x = i + 1;
        y = numsSize - 1;
        while (x < y) {
            if (nums[i] + nums[x] + nums[y] >= target) {
                y --;
            } else {
                n += y - x;
                x ++;
            }
        }
    }
    return n;
}


/*
Difficulty:Medium
Total Accepted:26.6K
Total Submissions:64.5K


Companies Google
Related Topics Array Two Pointers
Similar Questions 
                
                  
                    3Sum
                  
                    3Sum Closest
                  
                    Valid Triangle Number
*/
