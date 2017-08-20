/*
101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).


For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3



But the following [1,2,2,null,3,null,3]  is not:
    1
   / \
  2   2
   \   \
   3    3




Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define PUSH(N) do { p[n ++] = N; } while (0)
​
bool isSymmetric(struct TreeNode* root) {
    struct TreeNode **p, **tmp;
    int dep, n, i, j, k;
    
    if (!root) return true;
    
    dep = 0; n = 0;
    p = malloc((1 << dep) * sizeof(struct TreeNode *));
    //assert(p);
    PUSH(root);
    while (n) {
        for (i = 0, j = n - 1; i < j; i ++, j --) {
            if ((!p[i] && p[j]) ||
                (!p[j] && p[i]) ||
                ( p[i] && p[i]->val != p[j]->val)) {
                free(p);
                return false;
            }
        }
        tmp = p; k = n;
        dep ++; n = 0;
        p = malloc((1 << dep) * sizeof(struct TreeNode *));
        //assert(p);
        for (i = 0; i < k; i ++) {
            if (tmp[i]) {
                PUSH(tmp[i]->left);
                PUSH(tmp[i]->right);
            }
        }
        free(tmp);
    }
    free(p);
    return true;
}


/*
Difficulty:Easy
Total Accepted:187.9K
Total Submissions:484.8K


Companies LinkedIn Bloomberg Microsoft
Related Topics Tree Depth-first Search Breadth-first Search

*/
