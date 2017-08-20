/*
484. Find Permutation

By now, you are given a secret signature consisting of character 'D' and 'I'. 'D' represents a decreasing relationship between two numbers, 'I' represents an increasing relationship between two numbers. And our secret signature was constructed by a special integer array, which contains uniquely all the different number from 1 to n (n is the length of the secret signature plus 1). For example, the secret signature "DI" can be constructed by array [2,1,3] or [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that can't represent the "DI" secret signature.



On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n] could refer to the given secret signature in the input.


Example 1:
Input: "I"
Output: [1,2]
Explanation: [1,2] is the only legal initial spectial string can construct secret signature "I", where the number 1 and 2 construct an increasing relationship.



Example 2:
Input: "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI", but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]



Note:
The input string will only contain the character 'D' and 'I'.
The length of input string is a positive integer and will not exceed 10,000
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void find_i_and_expand(int *p, char *s, int k) {
    char *t = s, *b, *f;
​
    while (*t && *t != 'I') t ++;  // find first I
    
    if (!*t) {
        while (t >= s) {
            p[t - s] = k;
            k ++;
            t --;
        }
    } else {
        b = t;
        while (b >= s) { // expand backward
            p[b - s] = k;
            k ++;
            b --;
        }
        t ++;
        while (*t && *t == 'I') { // expand forward
            p[t - s] = k;
            k ++;
            t ++;
        }
        return find_i_and_expand(&p[t - s], t, k);
    }
}
int* findPermutation(char* s, int* returnSize) {
    int len, *p, i, k;
​
    *returnSize = 0;
    if (!s || !*s) return NULL;
    
    len = strlen(s);
    *returnSize = len + 1;
    p = calloc((len + 1), sizeof(int));
    
    find_i_and_expand(p, s, 1);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:5K
Total Submissions:9.2K


Companies Google
Related Topics Greedy

*/
