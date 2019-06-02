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
    int dep;
    bool flag;
} set_t;
bool verify_and_set(set_t *set, int d) {
    if (set->dep == -1) {    // first time verifying a depth
        set->dep = d;
        return true;
    }
    
    // assert(d <= set->dep);
    if (d == set->dep - 1 && !set->flag) {
        set->flag = true;
        set->dep --;
    }
    
    if (d == set->dep) {
        return true;
    }
    return false;
}
bool traversal(struct TreeNode *node, set_t *set, int d) {
    if (set->dep != -1 && d > set->dep) return false;
    
    if (!node->left) {
        if (node->right) return false;
        // this is a left node
        if (verify_and_set(set, d) == false) return false;
    } else if (!traversal(node->left, set, d + 1)) return false;
    else if (!node->right) {
        if (verify_and_set(set, d) == false) return false;
    } else if (!traversal(node->right, set, d + 1)) return false;
    
    return true;
}
bool isCompleteTree(struct TreeNode* root) {
    set_t set = { -1, false };
    if (!root) return true;
    return traversal(root, &set, 0);
}


/*
Difficulty:Medium


*/
