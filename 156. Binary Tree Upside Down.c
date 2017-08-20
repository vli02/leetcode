/*
156. Binary Tree Upside Down

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.


For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5



return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  



confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.


Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* upsideDownBinaryTree(struct TreeNode* root) {
    struct TreeNode **stack;
    int sz = 100, sp = 0;
    struct TreeNode *node, **pp;
    
    stack = malloc(sz * sizeof(struct TreeNode *));
    //assert(stack);
    
    // push all nodes to stack
    node = root;
    while (node) {
        // enlarge stack
        if (sp + 1 >= sz) {
            sz *= 2;
            stack = realloc(stack, sz * sizeof(struct TreeNode *));
            //assert(stack);
        }
        stack[sp ++] = node;
        stack[sp ++] = node->right;
        node = node->left;
    }
    
    // pop from stack
    if (sp && !stack[sp - 1]) -- sp;
    pp = &root;
    while (sp) {
        *pp = stack[-- sp];
        if (sp) {
            (*pp)->left = stack[-- sp];
        } else {
            (*pp)->left = NULL;
        }
        (*pp)->right = NULL;
        pp = &(*pp)->right;
    }
    
    free(stack);
    
    return root;
}


/*
Difficulty:Medium
Total Accepted:26.5K
Total Submissions:59.8K


Companies LinkedIn
Related Topics Tree
Similar Questions 
                
                  
                    Reverse Linked List
*/
