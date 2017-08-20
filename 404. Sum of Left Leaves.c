/*
404. Sum of Left Leaves

Find the sum of all left leaves in a given binary tree.

Example:
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void sumleft(struct TreeNode *node, int *n, int left) {
    if (!node) return;
    sumleft(node->left, n, 1);
    if (left && !node->left && !node->right) *n += node->val;
    sumleft(node->right, n, 0);
}
int sumOfLeftLeaves(struct TreeNode* root) {
    int n = 0;
    sumleft(root, &n, 0);
    return n;
}


/*
Difficulty:Easy
Total Accepted:58.9K
Total Submissions:125.6K


Companies Facebook
Related Topics Tree

*/
