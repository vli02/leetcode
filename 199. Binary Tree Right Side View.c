/*
199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---



You should return [1, 3, 4].


Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.
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
int depth(struct TreeNode *node) {
    int d = 0, dl, dr;
    if (node) {
        dl = depth(node->left);
        dr = depth(node->right);
        d = dl > dr ? dl : dr;
        d += 1;
    }
    return d;
}
​
int* rightSideView(struct TreeNode* root, int* returnSize) {
    struct TreeNode *node;
    struct TreeNode **ns;
    int *ds;
    int sp = 0;
    
    int *v = NULL;
    int d, n = 0, last = 0;
    
    *returnSize = 0;
    if (!root) return NULL;
    
    d = depth(root);
    
    ns = malloc(d * sizeof(struct TreeNode *));
    v  = malloc(d * 2 * sizeof(int));
    if (!ns || !v) return NULL;
    ds = v + d;
​
#define PUSH(N, D) do { ns[sp] = N; ds[sp++] = D; } while (0)
#define POP(N, D)  do { N = ns[--sp]; D = ds[sp]; } while (0)
​
    d = 1;
    PUSH(root, d);
    
    while (sp) {
        POP(node, d);
        if (d > last) {
            v[n ++] = node->val;
            last = d;
        }
        if (node->left)  PUSH(node->left, d + 1);
        if (node->right) PUSH(node->right, d + 1);
    }
    
    *returnSize = n;
    
    free(ns);
    
    return v;
}


/*
Difficulty:Medium
Total Accepted:85.6K
Total Submissions:209.3K


Companies Amazon
Related Topics Tree Depth-first Search Breadth-first Search
Similar Questions 
                
                  
                    Populating Next Right Pointers in Each Node
                  
                    Boundary of Binary Tree
*/
