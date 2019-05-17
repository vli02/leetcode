/*
222. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *node, int i, int n, int *x) {
    if (i == n) {
        if (node->left) (*x) ++;
        if (node->right) (*x) ++;
        return;
    }
    
    if ((*x) % 2) return;
    dfs(node->left, i + 1, n, x);
    
    if ((*x) % 2) return;
    dfs(node->right, i + 1, n, x);    
}
int countNodes(struct TreeNode* root) {
    struct TreeNode *node = root;
    int i = 0;
    int x = 0;
    
    if (!node) return 0;
    
    while (node) {
        i ++;
        node = node->right;
    }

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
