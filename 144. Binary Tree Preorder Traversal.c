/*
144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.


For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3



return [1,2,3].


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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode **stack, *node;
    int ssz, sp;
    int *p, psz, n;
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    ssz = 100;
    stack = malloc(ssz * sizeof(struct TreeNode *));
    //assert(stack);
    sp = 0;
    
    psz = 100;
    p = malloc(psz * sizeof(int));
    //assert(p);
    n = 0;
    
#define PUSH(N) do { \
    if (ssz == sp) { \
        ssz *= 2; \
        stack = realloc(stack, ssz * sizeof(struct TreeNode *)); \
        /* assert(stack); */ \
    } \
    stack[sp ++] = N; \
} while (0)
​
#define POP(N) do { N = stack[-- sp]; } while (0)
​
#define add2p(V) do { \
    if (psz == n) { \
        psz *= 2; \
        p = realloc(p, psz * sizeof(int)); \
    } \
    p[n ++] = V; \
} while (0)
    
    PUSH(root);
    while (sp) {
        POP(node);
        add2p(node->val);
        if (node->right) PUSH(node->right);
        if (node->left) PUSH(node->left);
    }
    
    *returnSize = n;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:187.6K
Total Submissions:416.8K


Related Topics Tree Stack
Similar Questions Binary Tree Inorder Traversal Verify Preorder Sequence in Binary Search Tree

*/
