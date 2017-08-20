/*
437. Path Sum III

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumFrom(struct TreeNode *node, int sum) {
    int n = 0;
    
    if (node) {
        sum -= node->val;
        n += (!sum) ? 1 : 0;
        n += sumFrom(node->left, sum);
        n += sumFrom(node->right, sum);
    }
    
    return n;
}
int pathSum(struct TreeNode* root, int sum) {
    if (!root) return 0;
    return sumFrom(root, sum) +
           pathSum(root->left, sum) +
           pathSum(root->right, sum);
}


/*
Difficulty:Easy
Total Accepted:33.6K
Total Submissions:84.2K


Related Topics Tree
Similar Questions Path Sum Path Sum II

*/
