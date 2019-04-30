/*
863. All Nodes Distance K in Binary Tree

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 





Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.


 

Note:


	The given tree is non-empty.
	Each node in the tree has unique values 0 <= node.val <= 500.
	The target node is a node in the tree.
	0 <= K <= 1000.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int *p;
    int n;
    int sz;
} res_t;

void add2res(res_t *res, struct TreeNode *node) {
    //printf("%d, ", node->val);
    if (res->n == res->sz) {
        if (res->sz == 0) res->sz = 10;
        else res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(int));
        //assert(res->p);
    }
    res->p[res->n ++] = node->val;
}
bool node_match(struct TreeNode *node, struct TreeNode *target, int k, int *d) {
    struct TreeNode *p;
    
    if (!node) return false;
    
    if (d) *d = 0;
    if (k == 0 && node == target) return true;
    
    if (d) *d = -1;
    if (node_match(node->left, target, k - 1, NULL)) return true;
    
    if (d) *d = 1;
    return (node_match(node->right, target, k - 1, NULL));
}

struct TreeNode *travel2target(struct TreeNode *node, struct TreeNode *target, int k, int *d) {
    struct TreeNode *p;
    
    if (!node) return NULL;
    
    if (node_match(node, target, k, d)) return node;
    
    p = travel2target(node->left,  target, k, d);
    if (p) return p;
    
    return travel2target(node->right, target, k, d);
}

void travel2peer(res_t *res, struct TreeNode *node, int k) {
    if (!node) return;
    
    if (k == 0) {
        add2res(res, node);
        return;
    }
    
    travel2peer(res, node->left, k - 1);
    travel2peer(res, node->right, k - 1);
}

int* distanceK(struct TreeNode* root, struct TreeNode* target, int K, int* returnSize) {
    res_t res = { 0 };
    int i, d;
    struct TreeNode *node;
    
    for (i = 0; i <= K; i ++) {
        node = travel2target(root, target, i, &d);
        if (!node) continue;
        //printf("%d:%d:", node->val, d);
        if (i == K) add2res(&res, node);
        if (d >= 0) travel2peer(&res, node->left,  K - i - 1);
        if (d <= 0) travel2peer(&res, node->right, K - i - 1);
    }
    
    *returnSize = res.n;
    return res.p;
}


/*
Difficulty:Medium


*/
