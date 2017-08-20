/*
102. Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).


For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7



return its level order traversal as:
[
  [3],
  [9,20],
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
    l = depth(node->left)  + 1;
    r = depth(node->right) + 1;
    if (l > r) return l;
    return r;
}
void bfs(int **p, struct TreeNode **queue, int n, int *c, int d) {
    int *buff, buffsz, newqsz, k, i;
    struct TreeNode *node, **newq;
    
    buffsz = 10;
    buff = malloc(buffsz * sizeof(int));
    newqsz = 10;
    newq = malloc(newqsz * sizeof(struct TreeNode *));
    //assert(buff && new_p);
    
    k = 0;
    for (i = 0; i < n; i ++) {
        node = queue[i];
        //printf("%d, ", node->val);
        if (c[d] >= buffsz) {
            buffsz *= 2;
            buff = realloc(buff, buffsz * sizeof(int));
            //assert(buff);
        }
        buff[c[d]] = node->val;
        c[d] ++;
        if (k + 1 >= newqsz) {
            newqsz *= 2;
            newq = realloc(newq, newqsz * sizeof(struct TreeNode *));
            //assert(newq);
        }
        if (node->left)  newq[k ++] = node->left;
        if (node->right) newq[k ++] = node->right;
    }
    //printf("done!\n");
    free(queue);
    p[d] = buff;
    if (k) bfs(p, newq, k, c, d + 1);
    else free(newq);
}
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int d, n;
    int **p, *c;
    struct TreeNode **queue;
    
    *returnSize = 0;
    if (!root) return NULL;
    
    d = depth(root);
    p = malloc(d * sizeof(int *));
    c = calloc(d, sizeof(int));
    queue = malloc(1 * sizeof(struct TreeNode *));
    //assert(p && q);
    n = 0;
    queue[n ++] = root;
    
    bfs(p, queue, n, c, 0);
    
    *returnSize = d;
    *columnSizes = c;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:181.3K
Total Submissions:456.8K


Companies LinkedIn Facebook Amazon Microsoft Apple Bloomberg
Related Topics Tree Breadth-first Search
Similar Questions 
                
                  
                    Binary Tree Zigzag Level Order Traversal
                  
                    Binary Tree Level Order Traversal II
                  
                    Minimum Depth of Binary Tree
                  
                    Binary Tree Vertical Order Traversal
                  
                    Average of Levels in Binary Tree
*/
