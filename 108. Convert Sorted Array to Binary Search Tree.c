/*
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *gen_tree(int *nums, int start, int end) {
    struct TreeNode *node;
    int mid;
    
    if (start > end) return NULL;
    
    node = malloc(sizeof(struct TreeNode));
    //assert(node);
    
    mid = start + (end - start) / 2;
    node->val = nums[mid];
    node->left = gen_tree(nums, start, mid - 1);  // sub tree on left
    node->right = gen_tree(nums, mid + 1, end);  // sub tree on right
    
    return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return gen_tree(nums, 0, numsSize - 1);
}


/*
Difficulty:Easy
Total Accepted:133.7K
Total Submissions:317.4K


Companies Airbnb
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    Convert Sorted List to Binary Search Tree
*/
