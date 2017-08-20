/*
222. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode *node, int i, int n, int *x) {
    int k = 0;
    if (i == n) {
        if (node->left) {
            k++;
        }
        if (node->right) {
            k++;
        }
        *x = (*x) + k;
​
        return k == 2 ? 0 : 1;
    }
    
    k = dfs(node->left, i + 1, n, x);
    if (k) return k;
​
    k = dfs(node->right, i + 1, n, x);
    if (k) return k;
    
    return 0;
}
int countNodes(struct TreeNode* root) {
    struct TreeNode *n = root;
    int i = 0;
    int x = 0;
    
    if (!n) return 0;
    
    do {
        i ++;
        n = n->right;
    } while (n);
​
    dfs(root, 1, i, &x);
    
    return (1 << i) - 1 + x;
}


/*
Difficulty:Medium
Total Accepted:64.8K
Total Submissions:235.8K


Related Topics Tree Binary Search
Similar Questions Closest Binary Search Tree Value

*/
