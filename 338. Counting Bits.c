/*
338. Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.


Example:
For num = 5 you should return [0,1,1,2,1,2].


Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount  in c++ or in any other language.



Credits:Special thanks to @ syedee  for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *p, i;
    
    p = malloc((num + 1) * sizeof(int));
    //assert(p);
    *returnSize = num + 1;
    
    p[0] = 0;
    for (i = 1; i <= num; i ++) {
        p[i] = p[i & (i - 1)] + 1;
    }
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:84.7K
Total Submissions:138.2K


Related Topics Dynamic Programming Bit Manipulation
Similar Questions Number of 1 Bits

*/
