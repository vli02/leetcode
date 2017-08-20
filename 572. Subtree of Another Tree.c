/*
572. Subtree of Another Tree

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.


Example 1:

Given tree s:
     3
    / \
   4   5
  / \
 1   2

Given tree t:
   4 
  / \
 1   2

Return true, because t has the same structure and node values with a subtree of s.


Example 2:

Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0

Given tree t:
   4
  / \
 1   2

Return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool equal(struct TreeNode *node, struct TreeNode *t) {
    if (!node && !t) return true;
    if (!node || !t || node->val != t->val) return false;
    return equal(node->left, t->left) && equal(node->right, t->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (equal(s, t) ||
       (s && isSubtree(s->left, t)) ||
       (s && isSubtree(s->right, t))) return true;
    return false;
}


/*
Difficulty:Easy
Total Accepted:17.6K
Total Submissions:43.3K


Companies Facebook eBay
Related Topics Tree
Similar Questions 
                
                  
                    Count Univalue Subtrees
                  
                    Most Frequent Subtree Sum
*/
