/*
337. House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.



Determine the maximum amount of money the thief can rob tonight without alerting the police.


Example 1:
     3
    / \
   2   3
    \   \ 
     3   1

Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.


Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1

Maximum amount of money the thief can rob = 4 + 5 = 9.


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rob(struct TreeNode* root) {
    int val, val_next;
    if (!root) return 0;
    val = root->val;
    if (root->left) val += rob(root->left->left) + rob(root->left->right);
    if (root->right) val += rob(root->right->left) + rob(root->right->right);
    val_next = rob(root->left) + rob(root->right);
    
    return val > val_next ? val : val_next;
}


/*
Difficulty:Medium
Total Accepted:46.9K
Total Submissions:108.2K


Companies Uber
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    House Robber
                  
                    House Robber II
*/
