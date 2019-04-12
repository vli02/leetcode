/*
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. 

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.


For example, you may serialize the following tree
    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


Credits:Special thanks to @Louis1992 for adding this problem and creating all test cases.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int depth(struct TreeNode *n) {
    int l, r;
    if (!n) return 0;
    l = depth(n->left);
    r = depth(n->right);
    return l > r ? l + 1 : r + 1;
}

#define PUSH(P, N) do { P[sp++] = N; } while (0)
#define POP(P, N)  do { N = P[--sp]; } while (0)

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    char *str, *head;
    int sz = 1024 * 10;
    int d, n = 0, l = 0;
    struct TreeNode **stack;
    int sp = 0;
    struct TreeNode *node;
    char c;
    
#define HEAD_SZ 32

    if (!root) return NULL;
    
    d = depth(root);

    head = malloc(sz * (sizeof(int) + 2) + HEAD_SZ + 1);
    stack = malloc((d + 1) * sizeof(struct TreeNode *));
    //assert(head && stack);
    
    str = head + HEAD_SZ;

    PUSH(stack, root);
    while (sp) {
        if (l + 32 + 8 > sz) {
            sz = sz * 2;
            head = realloc(head, sz * (sizeof(int) + 2) + HEAD_SZ + 1);
            //assert(head);
            str = head + l + HEAD_SZ;
        }
        POP(stack, node);
        if (node) {
            n ++;
            sprintf(str, "%08x", node->val);
            str += 8; l += 8;
            PUSH(stack, node->right);
            PUSH(stack, node->left);
        } else {
            *str = ','; str += 1; l += 1;
        }
    }
    *str = 0;
    
    // put checksum in the first 8 bytes
    c = head[HEAD_SZ];
    sprintf(head, "%08x%08x%08x%08x", 0, d, n, l);
    head[HEAD_SZ] = c; //sprintf has put a 0 terminator in the end.
    
    free(stack);
    
    return head;
}

int str2num(char *p) {
    char buff[9] = { 0 };
    strncpy(buff, p, 8);
    return strtol(buff, NULL, 16);
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    int n, d, l;
    struct TreeNode *buff;
    int idx = 0;
    struct TreeNode ***stackp;
    int sp = 0;
    struct TreeNode **pp;
    int val;
    struct TreeNode *root = NULL, *node;

    if (!data) return NULL; // verify checksum
    
    data += 8;
    
    d = str2num(data);
    
    data += 8;
    
    n = str2num(data);
        
    data += 8;
    
    l = str2num(data);
        
    data += 8;
    
    buff = malloc(n * sizeof(struct TreeNode));
    stackp = malloc((d + 1) * sizeof(struct TreeNode **));
    //assert(buff && stackp);
    
    PUSH(stackp, &root);
    
    while (l > 0) {
        POP(stackp, pp);
        if (*data == ',') {
            *pp = NULL;
            data += 1;
            l -= 1;
        } else {
            val = str2num(data);
            data += 8;
            l -= 8;
            node = &buff[idx ++];
            node->val = val;
            *pp = node;
            PUSH(stackp, &node->right);
            PUSH(stackp, &node->left);
        }
    }
    
    free(stackp);
    
    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);


/*
Difficulty:Hard
Total Accepted:68.5K
Total Submissions:206K


Companies LinkedIn Google Uber Facebook Amazon Microsoft Yahoo Bloomberg
Related Topics Tree Design
Similar Questions 
                
                  
                    Encode and Decode Strings
                  
                    Serialize and Deserialize BST
                  
                    Find Duplicate Subtrees
*/
