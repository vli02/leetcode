/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).



Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.



Example 1:
    2
   / \
  1   3

Binary tree [2,1,3], return true.


Example 2:
    1
   / \
  2   3

Binary tree [1,2,3], return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValid(struct TreeNode* p, struct TreeNode** prev) {
    if (!p) return true;
    if (!isValid(p->left, prev)) return false;
    if (*prev && p->val <= (*prev)->val) return false;
    *prev = p;
    return (isValid(p->right, prev));
}
bool isValidBST(struct TreeNode* root) {
    struct TreeNode *prev = NULL;
    return isValid(root, &prev);
}


/*
Difficulty:Medium
Total Accepted:174.5K
Total Submissions:749K


Companies Amazon Microsoft Bloomberg Facebook
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    Binary Tree Inorder Traversal
                  
                    Find Mode in Binary Search Tree
*/
