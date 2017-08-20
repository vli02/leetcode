/*
230. Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count(struct TreeNode *node) {
    if (!node) return 0;
    return count(node->left) + count(node->right) + 1;
}
int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode *node = root;
    int n;
    n = count(node->left);
    if (n == k - 1) {
        return node->val;
    } else 
    if (n >= k) {
        return kthSmallest(node->left, k);
    }
    return kthSmallest(node->right, k - n - 1);
}


/*
Difficulty:Medium
Total Accepted:104.8K
Total Submissions:239.5K


Companies Bloomberg Uber Google
Related Topics Binary Search Tree
Similar Questions 
                
                  
                    Binary Tree Inorder Traversal
*/
