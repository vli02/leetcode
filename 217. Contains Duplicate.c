/*
217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
bool containsDuplicate(int* nums, int numsSize) {
    int i;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (i = 1; i < numsSize; i ++) {
        if (nums[i] == nums[i - 1]) return true;
    }
    
    return false;
}


/*
Difficulty:Easy
Total Accepted:168.7K
Total Submissions:368.9K


Companies Palantir Airbnb Yahoo
Related Topics Array Hash Table
Similar Questions 
                
                  
                    Contains Duplicate II
                  
                    Contains Duplicate III
*/
