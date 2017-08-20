/*
99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.


Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find_nodes(struct TreeNode *node,
                struct TreeNode **first,
                struct TreeNode **middle,
                struct TreeNode **last,
                struct TreeNode **prev) {
    if (!node || *last) return;
    
    find_nodes(node->left, first, middle, last, prev);
    
    if (*prev && (*prev)->val > node->val) {
        if (!*first) {
            *first = *prev;
            *middle = node;
        } else {
            *last = node;
            return;
        }
    }
    *prev = node;
    
    find_nodes(node->right, first, middle, last, prev);
}
void recoverTree(struct TreeNode* root) {
    struct TreeNode *first, *middle, *last, *prev;
    int k;
    
    first = middle = last = prev = NULL;
    
    find_nodes(root, &first, &middle, &last, &prev);
    
    if (first) {
        last = last ? last : middle;
        k = first->val;
        first->val = last->val;
        last->val = k;
    }
}


/*
Difficulty:Hard
Total Accepted:75.7K
Total Submissions:253.9K


Related Topics Tree Depth-first Search

*/
