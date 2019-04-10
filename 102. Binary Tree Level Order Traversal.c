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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    struct TreeNode **q;
    int n;
    int sz;
} q_t;

void add2q(q_t *q, struct TreeNode *node) {
    if (q->n == q->sz) {
        q->sz *= 2;
        q->q = realloc(q->q, q->sz * sizeof(struct TreeNode *));
        //assert(q->q);
    }
    q->q[q->n ++] = node;
}

int depth(struct TreeNode *node) {
    int l, r;
    if (!node) return 0;
    l = depth(node->left)  + 1;
    r = depth(node->right) + 1;
    if (l > r) return l;
    return r;
}
void bfs(int **p, q_t *q1, q_t *q2, int *c, int d) {
    int *buff, buffsz, i;
    struct TreeNode *node;
    
    if (!q1->n) return;
    
    buffsz = 10;
    buff = malloc(buffsz * sizeof(int));
    
    for (i = 0; i < q1->n; i ++) {
        node = q1->q[i];
        //printf("%d, ", node->val);
        if (c[d] >= buffsz) {
            buffsz *= 2;
            buff = realloc(buff, buffsz * sizeof(int));
            //assert(buff);
        }
        buff[c[d]] = node->val;
        c[d] ++;
        
        if (node->left)  add2q(q2, node->left);
        if (node->right) add2q(q2, node->right);
    }
    //printf("done!\n");
    
    p[d] = buff;
    
    q1->n = 0;
    bfs(p, q2, q1, c, d + 1);
}
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int d;
    int **p, *c;
    q_t q1 = { 0 }, q2 = { 0 };
    
    *returnSize = 0;
    if (!root) return NULL;
    
    d = depth(root);
    p = malloc(d * sizeof(int *));
    c = calloc(d, sizeof(int));
    //assert(p && c);
    
    q1.sz = q2.sz = 10;
    q1.q = malloc(q1.sz * sizeof(struct TreeNode *));
    q2.q = malloc(q2.sz * sizeof(struct TreeNode *));
    //assert(q1.q && q2.q);
    
    add2q(&q1, root);
    
    bfs(p, &q1, &q2, c, 0);
    
    *returnSize = d;
    *columnSizes = c;
    
    free(q1.q);
    free(q2.q);
    
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
