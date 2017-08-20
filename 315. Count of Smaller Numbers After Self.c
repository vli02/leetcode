/*
315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is 
the number of smaller elements to the right of nums[i].


Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.



Return the array [2, 1, 1, 0].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node_s {
    int key;
    int lnum;
    int dup;
    struct node_s *left;
    struct node_s *right;
} node_t;
void insert(node_t **nodep, node_t *buff, int key, int *pi, int lnum) {
    node_t *node = *nodep;
    if (!node) {
        *pi = lnum;
        node = buff;
        node->key = key;
        node->dup = 1;
        *nodep = node;
    } else if (node->key == key) {
        node->dup ++;
        *pi = lnum + node->lnum;
    } else if (node->key > key) {
        node->lnum ++;
        insert(&node->left, buff, key, pi, lnum);
    } else {
        insert(&node->right, buff, key, pi, lnum + node->lnum + node->dup);
    }
}
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int *p, i;
    node_t *node, *buff;
​
    p = malloc(numsSize * sizeof(int));
    buff = calloc(numsSize, sizeof(node_t));
    //assert(p && buff);
    
    node = NULL;
    for (i = numsSize - 1; i >= 0; i --) {
        insert(&node, &buff[i], nums[i], &p[i], 0);
    }
    
    free(buff);
    *returnSize = numsSize;
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:34.3K
Total Submissions:99.7K


Companies Google
Related Topics Divide and Conquer Binary Indexed Tree Segment Tree Binary Search Tree
Similar Questions 
                
                  
                    Count of Range Sum
                  
                    Queue Reconstruction by Height
                  
                    Reverse Pairs
*/
