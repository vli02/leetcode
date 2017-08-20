/*
173. Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator {
    struct TreeNode **stack;
    int sp;
};
​
int depth(struct TreeNode *node) {
    int l, r;
    if (!node) return 0;
    l = depth(node->left) + 1;
    r = depth(node->right) + 1;
    if (l > r) return l;
    return r;
}
void push_left(struct BSTIterator *obj, struct TreeNode *node) {
    do {
        obj->stack[obj->sp ++] = node;
        node = node->left;
    } while (node);
}
struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *obj;
    int d = depth(root);
    
    obj = calloc(1, sizeof(*obj));
    //assert(obj);
    if (d) {
        obj->stack = malloc(d * sizeof(struct TreeNode *));
        //assert(obj->stack);
        push_left(obj, root);
    }
    
    return obj;
}
​
/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    return (iter->sp) ? true : false;
}
​
/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    struct TreeNode *node;
    
    node = iter->stack[-- iter->sp];
    if (node->right) push_left(iter, node->right);
    
    return node->val;
}
​
/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    if (iter->stack) free(iter->stack);
    free(iter);
}
​
/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */


/*
Difficulty:Medium
Total Accepted:95.4K
Total Submissions:231.1K


Companies LinkedIn Google Facebook Microsoft
Related Topics Tree Stack Design
Similar Questions 
                
                  
                    Binary Tree Inorder Traversal
                  
                    Flatten 2D Vector
                  
                    Zigzag Iterator
                  
                    Peeking Iterator
                  
                    Inorder Successor in BST
*/
