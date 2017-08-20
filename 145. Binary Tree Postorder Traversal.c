/*
145. Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.


For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3



return [3,2,1].


Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traversal(int **p, int *psz, int *pn, struct TreeNode *node) {
    if (!node) return;
    traversal(p, psz, pn, node->left);
    traversal(p, psz, pn, node->right);
    if (*psz == *pn) {
        *psz *= 2;
        *p = realloc(*p, (*psz) * sizeof(int));
        //assert(*p);
    }
    (*p)[(*pn) ++] = node->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *p, psz, pn;
    
    psz = 100;
    p = malloc(psz * sizeof(int));
    //assert(p);
    pn = 0;
    
    traversal(&p, &psz, &pn, root);
    
    *returnSize = pn;
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:147.8K
Total Submissions:368K


Related Topics Tree Stack
Similar Questions Binary Tree Inorder Traversal

*/
