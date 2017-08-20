/*
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.



According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4



For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int match(struct TreeNode *node, struct TreeNode *n) {
    if (!node) return 0;
    return (node == n || match(node->left, n) || match(node->right, n)) ? 1 : 0;
}
struct TreeNode *traversal(struct TreeNode *node, struct TreeNode *p, struct TreeNode *q) {
    struct TreeNode *lca;
    
    // post order traversal
    if (node->left) {
        lca = traversal(node->left, p, q);
        if (lca) return lca;
    }
    
    if (node->right) {
        lca = traversal(node->right, p, q);
        if (lca) return lca;
    }
    
    if (node == p && (match(node->left, q) || match(node->right, q))) return node;
    
    if (match(node->left, p) && match(node->right, q)) return node;
    
    return NULL;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *node;
    
    node = traversal(root, p, q);
    if (!node) node = traversal(root, q, p);
    
    return node;
}


/*
Difficulty:Medium
Total Accepted:112.6K
Total Submissions:378.7K


Companies Amazon LinkedIn Apple Facebook Microsoft
Related Topics Tree
Similar Questions 
                
                  
                    Lowest Common Ancestor of a Binary Search Tree
*/
