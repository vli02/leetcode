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
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find_nodes(struct TreeNode *node,
                struct TreeNode **n1,
                struct TreeNode **n2,
                struct TreeNode **n3,
                struct TreeNode **p) {
    if (!node || *n3) return;            // all are found
    
    find_nodes(node->left, n1, n2, n3, p);
    
    if (*p && (*p)->val > node->val) {  // found two nodes in wrong order
        if (!*n1) {
            *n1 = *p;                   // save first node
            *n2 = node;                 // save second node
        } else {
            *n3 = node;                 // save third node
            return;                     // all are found
        }
    }
    *p = node;
    
    find_nodes(node->right, n1, n2, n3, p);
}
void recoverTree(struct TreeNode* root) {
    struct TreeNode *n1, *n2, *n3, *p;
    int k;
    
    n1 = n2 = n3 = p = NULL;
    
    find_nodes(root, &n1, &n2, &n3, &p);
    
    if (n1) {
        if (!n3) n3 = n2;
        k = n1->val;            // swap first and third node
        n1->val = n3->val;
        n3->val = k;
    }
}


/*
Difficulty:Hard
Total Accepted:75.7K
Total Submissions:253.9K


Related Topics Tree Depth-first Search

*/
