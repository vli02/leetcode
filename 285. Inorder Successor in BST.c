/*
285. Inorder Successor in BST

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.



Note: If the given node has no in-order successor in the tree, return null.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    struct TreeNode *succ = NULL;
    //if (!root) return NULL;
    //if (root->val <= p->val) return inorderSuccessor(root->right, p);
    //succ = inorderSuccessor(root->left, p);
    //return succ ? succ : root;
    while (root) {
        if (root->val <= p->val) { // go to right
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }
    return succ;
}


/*
Difficulty:Medium
Total Accepted:36.4K
Total Submissions:101.1K


Companies Pocket Gems Microsoft Facebook
Related Topics Tree
Similar Questions 
                
                  
                    Binary Tree Inorder Traversal
                  
                    Binary Search Tree Iterator
*/
