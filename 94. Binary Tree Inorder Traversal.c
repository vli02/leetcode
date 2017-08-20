/*
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.


For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3



return [1,3,2].


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
#define add2p(P, SZ, N, V) do { \
    if (SZ = N) { \
        SZ *= 2; \
        P = realloc(P, (SZ) * sizeof(int)); \
        /* assert(P); */ \
    } \
    (P)[(N) ++] = V; \
} while (0)
​
void inorder(int **p, int *sz, int *n, struct TreeNode *node) {
    if (!node) return;
    inorder(p, sz, n, node->left);
    add2p(*p, *sz, *n, node->val);
    inorder(p, sz, n, node->right);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int sz, n, *p;
    struct TreeNode **stack, *node;
    int ssz, sp;
    
    sz = 100;
    p = malloc(sz * sizeof(int));
    //assert(p);
    n = 0;
    
#if 0
    inorder(&p, &sz, &n, root);
#else
    ssz = 100;
    stack = malloc(ssz * sizeof(struct TreeNode *));
    //assert(stack);
    sp = 0;
    
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
    node = root;
    while (node || sp) {
        while (node) {
            PUSH(node);
            node = node->left;
        }
        POP(node);
        add2p(p, sz, n, node->val);
        node = node->right;
    }
    
    free(stack);
#endif
​
    *returnSize = n;
    return p;
}


/*
Difficulty:Medium
Total Accepted:212.1K
Total Submissions:455.3K


Companies Microsoft
Related Topics Tree Hash Table Stack
Similar Questions 
                
                  
                    Validate Binary Search Tree
                  
                    Binary Tree Preorder Traversal
                  
                    Binary Tree Postorder Traversal
                  
                    Binary Search Tree Iterator
                  
                    Kth Smallest Element in a BST
                  
                    Closest Binary Search Tree Value II
                  
                    Inorder Successor in BST
*/
