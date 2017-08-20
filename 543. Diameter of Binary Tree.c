/*
543. Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.



Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    



Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].


Note:
The length of path between two nodes is represented by the number of edges between them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode *node, int *m) {
    int l, r;
    if (!node) return 0;
    l = depth(node->left,  m);
    r = depth(node->right, m);
    if (*m < l + r) *m = l + r;
    if (r < l) r = l;
    return r + 1;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int m = 0;
    depth(root,  &m);
    return m;
}


/*
Difficulty:Easy
Total Accepted:23.7K
Total Submissions:54.4K


Companies Google Facebook
Related Topics Tree

*/
