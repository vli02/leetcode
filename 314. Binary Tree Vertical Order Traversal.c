/*
314. Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Examples:


Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7



return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]



Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7



return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]



Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2



return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
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
typedef struct {
    int val;
    int x;
    int y;
} elem_t;
void traversal(elem_t **p, int *sz, int *n, struct TreeNode *node, int x, int y) {
    if (!node) return;
    if (*sz == *n) {
        *sz *= 2;
        *p = realloc(*p, (*sz) * sizeof(elem_t));
        //assert(*p);
    }
    (*p)[*n].val = node->val;
    (*p)[*n].x   = x;
    (*p)[*n].y   = y;
    (*n) ++;
    traversal(p, sz, n, node->left,  x - 1, y + 1);
    traversal(p, sz, n, node->right, x + 1, y + 1);
}
int cmp(const void *a, const void *b) {
    elem_t *ea = a, *eb = b;
    int k = ea->x - eb->x;
    if (k == 0) k = ea->y - eb->y;
    return k;
}
int** verticalOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    elem_t *p;
    int sz, n;
    int **ret, *buff, buff_sz, i, j, k;
    
    if (!root) return NULL;
    
    sz = 100;
    p = malloc(sz * sizeof(elem_t));
    //assert(p);
    n = 0;
    
    // put all nodes into the array
    traversal(&p, &sz, &n, root, 0, 0);
    
    // sort all nodes according to x and y
    qsort(p, n, sizeof(elem_t), cmp);
    
    // make the array for return
    k = p[n - 1].x - p[0].x + 1;
    ret = malloc(k * sizeof(int *));
    (*columnSizes) = calloc(k, sizeof(int));
    //assert(ret && *columnSizes);
    
    *returnSize = k;
    
    j = k = 0;
    for (i = 0; i < n; i ++) {
        //printf("%d, ", p[i].val);
        if (j == 0 || p[i].x != p[i - 1].x) {
            j = 0;
            buff_sz = 10;
            buff = malloc(buff_sz * sizeof(int));
            //assert(buff);
            ret[k ++] = buff;
        }
        if (buff_sz == j) {
            buff_sz *= 2;
            buff = realloc(buff, buff_sz * sizeof(int));
            //assert(buff);
            ret[k - 1] = buff;
        }
        buff[j ++] = p[i].val;
        (*columnSizes)[k - 1] = j;
    }
    
    free(p);
    
    return ret;
}


/*
Difficulty:Medium
Total Accepted:28.7K
Total Submissions:78.5K


Companies Google Snapchat Facebook
Related Topics Hash Table
Similar Questions 
                
                  
                    Binary Tree Level Order Traversal
*/
