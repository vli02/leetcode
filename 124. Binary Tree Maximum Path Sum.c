/*
124. Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.


For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.


For example:
Given the below binary tree,
       1
      / \
     2   3



Return 6.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxsum(struct TreeNode *node, int *max) {
    int l, r, k, s;
    
    if (!node) return 0;
    
    l = maxsum(node->left, max);
    r = maxsum(node->right, max);
    
    l = l > 0 ? l : 0;                  // ignore negative
    r = r > 0 ? r : 0;
    
    s = node->val + l + r;              // current node + both sides
    if (*max < s) *max = s;
    
    k = node->val + (l > r ? l : r);    // current node + one side only
    return k;
}
int maxPathSum(struct TreeNode* root) {
    int max;
    if (root) {
        max = root->val;
        maxsum(root, &max);
    } else {
        max = 0;
    }
    return max;
}


/*
Difficulty:Hard
Total Accepted:101.3K
Total Submissions:388.5K


Companies Microsoft Baidu
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    Path Sum
                  
                    Sum Root to Leaf Numbers
*/
