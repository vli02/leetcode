/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

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
    int *preorder;
    int pre_idx;
    int pre_sz;
    int *inorder;
} data_t;
​
struct TreeNode *make_tree(data_t *data, int start, int end) {
    struct TreeNode *node;
    int i;

    if (start == end) return NULL;
    
    node = malloc(sizeof(struct TreeNode));
    //assert(node);
    node->val = data->preorder[data->pre_idx ++];
    
    i = start;
    while (i < end && data->inorder[i] != node->val) i ++;
    
    node->left = make_tree(data, start, i);
    node->right = make_tree(data, i + 1, end);
    
    return node;
}
​
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    data_t data;
    
    data.preorder = preorder;
    data.pre_idx = 0;
    data.pre_sz = preorderSize;
    data.inorder = inorder;
    
    return make_tree(&data, 0, inorderSize);
}


/*
Difficulty:Medium


*/
