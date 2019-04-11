/*
114. Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6


The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *preOrderTraversal(struct TreeNode *prev, struct TreeNode *node) {
    struct TreeNode *left, *right;
    
    if (!node) return prev;
    
    left = node->left;
    right = node->right;
    node->left = node->right = NULL;
    
    prev->right = node;
    prev = node;

    prev = preOrderTraversal(prev, left);   // it's import to update prev
    prev = preOrderTraversal(prev, right);
    
    return prev;
}
void flatten(struct TreeNode* root) {
    struct TreeNode head = { 0 };
    preOrderTraversal(&head, root);
}


/*
Difficulty:Medium


*/
