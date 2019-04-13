/*
865. Smallest Subtree with all the Deepest Nodes

Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation:



We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.


 

Note:


	The number of nodes in the tree will be between 1 and 500.
	The values of each node are unique.
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
    struct TreeNode *root;
    struct TreeNode *lca;
    int depth;
} set_t;
​
bool match(struct TreeNode *a, struct TreeNode *b) {
    if (!a) return false;
    if (a == b || match(a->left, b) || match(a->right, b)) return true;
    return false;
}
struct TreeNode *find_lca(struct TreeNode *node,
                          struct TreeNode *left,
                          struct TreeNode *right) {
    struct TreeNode *lca;
    
    if (!node) return NULL;
    
    lca = find_lca(node->left, left, right);
    if (lca) return lca;
    lca = find_lca(node->right, left, right);
    if (lca) return lca;

    if ((node == left || match(node->left, left))   // the left node can be previous lca
        && match(node->right, right)) return node;
    
    return NULL;
}
void traversal(struct TreeNode *node, set_t *set, int d) {
    if (!node) return;
    
    traversal(node->left, set, d + 1);
    traversal(node->right, set, d + 1);
    
    if (set->depth < d) {   // the deepest node
        set->depth = d;
        set->lca = node;
    } else if (set->depth == d) {   // more than one node are deepest
        set->lca = find_lca(set->root, set->lca, node);
    }
}
struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    set_t set = { root, NULL, -1 };
    traversal(root, &set, 0);
    return set.lca;
}


/*
Difficulty:Medium


*/
