/*
270. Closest Binary Search Tree Value

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void search(struct TreeNode *node, double target, int *last) {
    double d, diff1, diff2;
    
    if (!node) return;
    
    d = node->val;  // current one
    diff1 = target - (*last);
    diff2 = target - d;
    
    if (diff1 < 0) diff1 = 0 - diff1;
    if (diff2 < 0) diff2 = 0 - diff2;
    if (diff1 > diff2) *last = d;       // closest one so far
    
    if (target < d) {
        search(node->left, target, last);
    } else
    if (target > d) {
        search(node->right, target, last);
    }
}
int closestValue(struct TreeNode* root, double target) {
    int last = root->val;
    search(root, target, &last);
    return last;
}


/*
Difficulty:Easy
Total Accepted:36.3K
Total Submissions:92.2K


Companies Microsoft Google Snapchat
Related Topics Tree Binary Search
Similar Questions 
                
                  
                    Count Complete Tree Nodes
                  
                    Closest Binary Search Tree Value II
*/
