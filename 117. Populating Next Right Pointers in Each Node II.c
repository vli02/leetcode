/*
117. Populating Next Right Pointers in Each Node II

Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?

Note:
You may only use constant extra space.


For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7



After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *v, *h, *prev, *left;
    prev = NULL;
    left = root;
    v = left;
    while (v) {
        h = v;
        do {
            if (h->left) {
                if (prev) {
                    prev->next = h->left;
                } else {
                    left = h->left;
                }
                prev = h->left;
            }
            if (h->right) {
                if (prev) {
                    prev->next = h->right;
                } else {
                    left = h->right;
                }
                prev = h->right;
            }
            h = h->next;
        } while (h);
        v = left;
        prev = left = NULL;
    }
}


/*
Difficulty:Medium
Total Accepted:101.9K
Total Submissions:301.9K


Companies Microsoft Bloomberg Facebook
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    Populating Next Right Pointers in Each Node
*/
