/*
106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct {
    int *postorder;
    int post_idx;
    int *inorder;
} data_t;

struct TreeNode *make_tree(data_t *data, int start, int end) {
    struct TreeNode *node;
    int i;
    
    if (start == end) return NULL;
    
    node = malloc(sizeof(struct TreeNode));
    //assert(node);
    node->val = data->postorder[-- data->post_idx];
    
    i = start;
    while (i < end && data->inorder[i] != node->val) i ++;
    
    node->right = make_tree(data, i + 1, end);
    node->left = make_tree(data, start, i);
    
    return node;
}
​
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    data_t data;
    data.postorder = postorder;
    data.post_idx = postorderSize;
    data.inorder = inorder;
    return make_tree(&data, 0, inorderSize);
}


/*
Difficulty:Medium


*/
