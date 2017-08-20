/*
257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.


For example, given the following binary tree:


   1
 /   \
2     3
 \
  5



All root-to-leaf paths are:
["1->2->5", "1->3"]


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char *b;
    int sz;
    int n;
} buff_t;
void buff_int(buff_t *buff, int k) {
    int l;
    if (buff->n + 10 + 2 + 1 >= buff->sz) {
        buff->sz *= 2;
        buff->sz += 10 + 2 + 1;
        buff->b = realloc(buff->b, buff->sz * sizeof(char));
        //assert(buff->b);
    }
    l = sprintf(&buff->b[buff->n], "%d", k);
    buff->n += l;
}
void buff_str(buff_t *buff, char *s, int len) {
    strcpy(&buff->b[buff->n], s);
    buff->n += len;
}
typedef struct {
    char **p;
    int sz;
    int n;
} res_t;
void add2res(res_t *res, char *s) {
    if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = s;
}
void travesal(struct TreeNode *node, buff_t *buff, int n, res_t *res) {
    if (!node) return;
    
    buff->n = n;
    
    buff_int(buff, node->val);
    
    if (!node->left && !node->right) {
        add2res(res, strdup(buff->b));
        return;
    }
    
    buff_str(buff, "->", 2);
    
    n = buff->n;  // tricky, save it for next recursion, it always starts from here.
    
    travesal(node->left, buff, n, res);
    travesal(node->right, buff, n, res);
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    res_t res;
    buff_t buff;
​
    *returnSize = 0;
    
    res.n = 0;
    res.sz = 100;
    res.p = malloc(res.sz * sizeof(char *));
    //assert(res.p);
    
    buff.n = 0;
    buff.sz = 100;
    buff.b = malloc(buff.sz * sizeof(char));
    //assert(buff.b);
    
    travesal(root, &buff, 0, &res);
    
    free(buff.b);
    
    *returnSize = res.n;
    
    return res.p;
}


/*
Difficulty:Easy
Total Accepted:117.7K
Total Submissions:306.5K


Companies Google Apple Facebook
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    Path Sum II
*/
