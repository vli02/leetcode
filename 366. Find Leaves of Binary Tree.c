/*
366. Find Leaves of Binary Tree

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.



Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    



Returns [4, 5, 3], [2], [1].



Explanation:

1. Removing the leaves [4, 5, 3] would result in this tree:
          1
         / 
        2          



2. Now removing the leaf [2] would result in this tree:
          1          



3. Now removing the leaf [1] would result in the empty tree:
          []         




Returns [4, 5, 3], [2], [1].


Credits:Special thanks to @elmirap for adding this problem and creating all test cases.
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
void remove_leaf(struct TreeNode **node, int **buf, int *l, int *c) {
    if (!(*node)->left && !(*node)->right) { // leaf node
        if ((*c) == (*l)) {
            (*l) *= 2;
            (*buf) = realloc(*buf, (*l) * sizeof(int));
            //assert(*buf);
        }
        (*buf)[(*c) ++] = (*node)->val;
        *node = NULL;
    } else {
        if ((*node)->left)  remove_leaf(&(*node)->left,  buf, l, c);
        if ((*node)->right) remove_leaf(&(*node)->right, buf, l, c);
    }
}
int** findLeaves(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **row, *col, n, sz;
    int *buf, l, c;
    
    *returnSize = 0;
    
    if (!root) return NULL;
    
    sz = 100; n = 0;
    row = malloc(sz * sizeof(int *));
    col = malloc(sz * sizeof(int));
    //assert(row && col);
    while (root) {
        c = 0; l = 10;
        buf = malloc(l * sizeof(int));
        //assert(buf);
        remove_leaf(&root, &buf, &l, &c);
        if (n == sz) {
            // enlarge row and col
            sz *= 2;
            row = realloc(row, sz * sizeof(int *));
            col = realloc(col, sz * sizeof(int));
            //assert(row && col);
        }
        row[n   ] = buf;
        col[n ++] = c;
    }
    
    *columnSizes = col;
    *returnSize = n;
    
    return row;
}


/*
Difficulty:Medium
Total Accepted:17.8K
Total Submissions:30K


Companies LinkedIn
Related Topics Tree Depth-first Search

*/
