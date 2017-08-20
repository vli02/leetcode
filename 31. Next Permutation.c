/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.


If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).


The replacement must be in-place, do not allocate extra memory.


Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
void nextPermutation(int* nums, int numsSize) {
    int i, j, k;
    for (i = numsSize - 1; i > 0; i --) {
        if (nums[i - 1] < nums[i]) {
            j = i - 1;  // this is the first small number from tail
            while (i < numsSize - 1 &&
                nums[i + 1] > nums[j]) {  // find the second small number in the tail
                i ++;
            }
            k = nums[i];  // swap it
            nums[i] = nums[j];
            nums[j] = k;
            qsort(&nums[j + 1], numsSize - j - 1, sizeof(int), cmp);
            return;
        }
    }
    qsort(nums, numsSize, sizeof(int), cmp);
}


/*
Difficulty:Medium
Total Accepted:116.6K
Total Submissions:405.2K


Companies Google
Related Topics Array
Similar Questions 
                
                  
                    Permutations
                  
                    Permutations II
                  
                    Permutation Sequence
                  
                    Palindrome Permutation II
*/
