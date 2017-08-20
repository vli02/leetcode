/*
450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.



Note: Time complexity should be O(height of tree).

Example:
root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode *p, **pp;
    struct TreeNode *a, *b;
    pp = &root;
    p = *pp;
    while (p) {
        if (p->val > key) {
            pp = &p->left;
        } else if (p->val < key) {
            pp = &p->right;
        } else {
            break;
        }
        p = *pp;
    }
    if (p) {
        // found it!
        if (!p->right) {
            // free(p);
            *pp = p->left;
        } else if (!p->left) {
            // free(p);
            *pp = p->right;
        } else {
            a = p->left;
            b = p->right;
            // free(p);
            *pp = a;
            p = a;
            a = a->right;
            p->right = b;
            if (a) {
                pp = &b->left;
                p = *pp;
                while (p) {
                    pp = &p->left;
                    p = *pp;
                }
                *pp = a;
            }
        }
    }
    return root;
}


/*
Difficulty:Medium
Total Accepted:19.6K
Total Submissions:53.6K


Companies Uber
Related Topics Tree

*/
