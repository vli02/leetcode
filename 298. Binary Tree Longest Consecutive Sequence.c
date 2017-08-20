/*
298. Binary Tree Longest Consecutive Sequence

Given a binary tree, find the length of the longest consecutive sequence path.


The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).



For example,
   1
    \
     3
    / \
   2   4
        \
         5

Longest consecutive sequence path is 3-4-5, so return 3. 
   2
    \
     3
    / 
   2    
  / 
 1

Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int recursive(struct TreeNode *root, int *max) {
    int l, r, n;
    
    if (!root) return 0;
    
    l = recursive(root->left, max);
    if (l && root->val + 1 == root->left->val) {
        l += 1;
    } else {
        l = 1;
    }
    r = recursive(root->right, max);
    if (r && root->val + 1 == root->right->val) {
        r += 1;
    } else {
        r = 1;
    }
    
    n = l > r ? l : r;
    if (*max < n) *max = n;
    
    return n;
}
​
int longestConsecutive(struct TreeNode* root) {
    int max = 0;
    
    recursive(root, &max);
    
    return max;
}
​


/*
Difficulty:Medium
Total Accepted:31.5K
Total Submissions:76.9K


Companies Google
Related Topics Tree
Similar Questions 
                
                  
                    Longest Consecutive Sequence
                  
                    Binary Tree Longest Consecutive Sequence II
*/
