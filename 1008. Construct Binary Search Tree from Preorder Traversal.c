/*
1008. Construct Binary Search Tree from Preorder Traversal

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



 

Note: 


	1 <= preorder.length <= 100
	The values of preorder are distinct.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    struct TreeNode *node;
    int mid;
    
    if (preorderSize == 0) return NULL;
    
    node = malloc(sizeof(struct TreeNode));
    //assert(node);
    node->val = preorder[0];
    
    mid = 1;
    while (mid < preorderSize && preorder[mid] < node->val) {
        mid ++;
    }
    node->left = bstFromPreorder(&preorder[1], mid - 1);
    node->right = bstFromPreorder(&preorder[mid], preorderSize - mid);

    return node;
}


/*
Difficulty:Medium


*/
