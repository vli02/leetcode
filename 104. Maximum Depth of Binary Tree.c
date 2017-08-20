/*
104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int l, r;
    
    if (!root) return 0;
    
    l = maxDepth(root->left) + 1;
    r = maxDepth(root->right) + 1;
    
    return l > r ? l : r;
}


/*
Difficulty:Easy
Total Accepted:256.9K
Total Submissions:488K


Companies LinkedIn Uber Apple Yahoo
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    Balanced Binary Tree
                  
                    Minimum Depth of Binary Tree
*/
