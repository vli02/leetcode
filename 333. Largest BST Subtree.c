/*
333. Largest BST Subtree

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:

Input: [10,5,15,1,8,null,7]

   10 
   / \ 
  5  15 
 / \   \ 
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.


Follow up:
Can you figure out ways to solve it with O(n) time complexity?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct {
    int n;
    int min;
    int max;
    int flag;
} val_t;

val_t post_order(struct TreeNode *node, int *max) {
    val_t lval, rval, cval = { 0 };
    
    if (!node) return cval;
    
    lval = post_order(node->left, max);
    rval = post_order(node->right, max);
    
    if (lval.n == -1 || rval.n == -1 ||         // left or right is not a BST
       (lval.flag && node->val <= lval.max) ||  // current does not qualify a BST
       (rval.flag && node->val >= rval.min)) {
        cval.n = -1;
    } else {
        cval.n = lval.n + rval.n + 1;           // current qualifies a BST
        
        if (*max < cval.n) *max = cval.n;
        
        cval.min = lval.flag == 0 ? node->val : lval.min;
        cval.max = rval.flag == 0 ? node->val : rval.max;
        cval.flag = 1;
    }
    
    //printf("%d: %d,%d,%d\n", node->val, cval.min, cval.max, cval.n);
    
    return cval;
}

int largestBSTSubtree(struct TreeNode* root){
    int max = 0;
    
    post_order(root, &max);
    
    return max;
}


/*
Difficulty:Medium


*/
