/*
272. Closest Binary Search Tree Value II

Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
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
void serialize(int **p, int *sz, int *n, int *x, struct TreeNode *node, int target) {
    if (!node) return;
    serialize(p, sz, n, x, node->left, target);
    if (*x == -1 || node->val <= target) {
        *x = *n;
    }
    if (*sz == *n) {
        *sz *= 2;
        *p = realloc(*p, (*sz) * sizeof(int));
        //assert(*p);
    }
    (*p)[(*n) ++] = node->val;
    serialize(p, sz, n, x, node->right, target);
}
int* closestKValues(struct TreeNode* root, double target, int k, int* returnSize) {
    int sz, n, *p;
    int m, i, j;
    int *result, x;
​
    sz = 100;
    p = malloc(sz * sizeof(int));
    //assert(p);
    
    n = 0; m = -1;
    serialize(&p, &sz, &n, &m, root, target);
    if (p[m] < target && m < n - 1 && target - p[m] > p[m + 1] - target) {
        m += 1;
    }
    
    result = malloc(k * sizeof(int));
    //assert(result);
    
    x = 0;
    result[x ++] = p[m];
    i = m - 1; j = m + 1;
    while (-- k) {
        if (i < 0) result[x ++] = p[j ++];
        else if (j >= n) result[x ++] = p[i --];
        else if (target - p[i] < p[j] - target) result[x ++] = p[i --];
        else result[x ++] = p[j ++];
    }
    
    free(p);
    
    *returnSize = x;
    
    return result;
}


/*
Difficulty:Hard
Total Accepted:17.5K
Total Submissions:45K


Companies Google
Related Topics Tree Stack
Similar Questions 
                
                  
                    Binary Tree Inorder Traversal
                  
                    Closest Binary Search Tree Value
*/
