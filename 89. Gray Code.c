/*
89. Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2


Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int i, j;
    int *p, psz, pn;
    
    psz = 1 << n;
    p = malloc(psz * sizeof(int));
    //assert(p);
    
    pn = 0;
    p[pn ++] = 0;
    for (i = 0; i < n; i ++) {
        for (j = pn - 1; j >= 0; j --) {
            p[pn ++] = p[j] | (1 << i);
        }
    }
    
    *returnSize = pn;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:92.4K
Total Submissions:224.8K


Companies Amazon
Related Topics Backtracking

*/
