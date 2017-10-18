/*
687. Longest Univalue Path

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.


Example 1:




Input:
              5
             / \
            4   5
           / \   \
          1   1   5




Output:
2




Example 2:




Input:
              1
             / \
            4   5
           / \   \
          4   4   5




Output:
2



Note:
The given binary tree has not more than 10000 nodes.  The height of the tree is not more than 1000.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode *node, int *max) {
    int l, r, k;
    if (!node) return 0;
    l = helper(node->left, max);
    r = helper(node->right, max);
    k = 1;
    if (l && node->val == node->left->val) {
        k += l;
        l ++;
    } else {
        l = 1;
    }
    if (node->right && node->val == node->right->val) {
        k += r;
        r ++;
    } else {
        r = 1;
    }
    if (*max < k) *max = k;
    
    return l > r ? l : r;
}
int longestUnivaluePath(struct TreeNode* root) {
    int max = 1;
    helper(root, &max);
    return max - 1;
}


/*
Difficulty:Easy
Total Accepted:5K
Total Submissions:15.5K


Companies Google
Related Topics Tree Recursion
Similar Questions 
                
                  
                    Binary Tree Maximum Path Sum
                  
                    Count Univalue Subtrees
                  
                    Path Sum III
*/
