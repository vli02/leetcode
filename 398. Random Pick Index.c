/*
398. Random Pick Index

Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.



Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.


Example:
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/

typedef struct {
    int *nums;
    int sz;
} Solution;
​
Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = malloc(sizeof(Solution));
    //assert(obj);
    obj->nums = nums;
    obj->sz = numsSize;
    return obj;
}
​
int solutionPick(Solution* obj, int target) {
    int i, r, n, k;
    k = -1;
    n = 1;
    r = random();
    for (i = 0; i < obj->sz; i ++) {
        if (obj->nums[i] == target) {
            if (!(r % n)) {
                k = i;
            }
            n ++;
        }
    }
    return k;
}
​
void solutionFree(Solution* obj) {
    free(obj);
}
​
/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 * solutionFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:22.6K
Total Submissions:53K


Companies Facebook
Related Topics Reservoir Sampling
Similar Questions 
                
                  
                    Linked List Random Node
*/
