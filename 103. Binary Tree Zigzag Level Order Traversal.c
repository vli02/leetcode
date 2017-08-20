/*
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).


For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7



return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int depth(struct TreeNode *node) {
    int l, r;
    if (!node) return 0;
    l = depth(node->left) + 1;
    r = depth(node->right) + 1;
    if (l > r) return l;
    return r;
}
#define PUSH(Q, L, N) do { Q[L ++] = N; } while (0)
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int d, **p, *buff, *c, k;
    struct TreeNode **queue, **tmp;
    int qlen, tsz, tlen;
    struct TreeNode *node;
    
    *returnSize = 0;
    if (!root) return NULL;
    
    d = depth(root);
    
    p = malloc(d * sizeof(int *));
    c = malloc(d * sizeof(int));
    //assert(p && c);
    *returnSize = d;
    
    d = 1;
    queue = malloc(1 * sizeof(struct TreeNode *));
    //assert(queue);
    qlen = 0;
    PUSH(queue, qlen, root);
    
    tmp = NULL;
    while (qlen) {
        if (!tmp) {
            tlen = 0;
            tsz = 10;
            tmp = malloc(tsz * sizeof(struct TreeNode *));
            //assert(tmp);
            k = 0;
            buff = malloc(qlen * sizeof(int));
            //assert(buff);
        } else if (tsz <= tlen + 1) {
            tsz *= 2;
            tmp = realloc(tmp, tsz * sizeof(struct TreeNode *));
            //assert(tmp);
        }
        node = queue[-- qlen];
        buff[k ++] = node->val;
        
        if ( (d % 2) && node->left)  PUSH(tmp, tlen, node->left);
        if (            node->right) PUSH(tmp, tlen, node->right);
        if (!(d % 2) && node->left)  PUSH(tmp, tlen, node->left);
        
        if (qlen == 0) {
            p[d - 1] = buff;
            c[d - 1] = k;
            d ++;
            free(queue);
            queue = tmp;
            qlen = tlen;
            tmp = NULL;
        }
    }
    free(queue);
    *columnSizes = c;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:106.1K
Total Submissions:306.7K


Companies LinkedIn Bloomberg Microsoft
Related Topics Tree Breadth-first Search Stack
Similar Questions 
                
                  
                    Binary Tree Level Order Traversal
*/
