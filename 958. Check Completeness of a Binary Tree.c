/*
958. Check Completeness of a Binary Tree

Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:



Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.



Example 2:



Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.


 


Note:


	The tree will have between 1 and 100 nodes.
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
    int d;
    bool shrinked;
} dep_t;
bool verify_depth(dep_t *dep, int d) {
    if (dep->d == -1) {    // first time verifying a depth
        dep->d = d;
        return true;
    }
    
    // assert(d <= dep->d);
    if (d == dep->d - 1 && !dep->shrinked) {
        dep->d --;
        dep->shrinked = true;
    }
    
    if (d == dep->d) {
        return true;
    }
    return false;
}
bool traversal(struct TreeNode *node, dep_t *dep, int d) {
    if (!node) {
        if (!verify_depth(dep, d)) return false;
    } else {
        if (!traversal(node->left, dep, d + 1)) return false;
        if (!traversal(node->right, dep, d + 1)) return false;
    }
    
    return true;
}
bool isCompleteTree(struct TreeNode* root) {
    dep_t dep = { -1, false };
    return traversal(root, &dep, 0);
}


/*
Difficulty:Medium


*/
