/*
66. Plus One

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int s = 1;
    int i;
    int *p;
    
    p = malloc((digitsSize + 1) * sizeof(int));
    if (!p) return NULL;
    
    i = digitsSize - 1;
    while (i >= 0) {
        //if (s) {
            p[i] = (digits[i] + s) % 10;
            s = (digits[i] + s) / 10;
        //} else {
        //    p[i] = digits[i];
        //}
        i --;
    }
    if (s) {
        memcpy(&p[1], &p[0], digitsSize * sizeof(int));
        //i = digitsSize - 1;
        //while (i >= 0) {
        //    p[i + 1] = p[i];
        //    i --;
        //}
        p[0] = 1;
        *returnSize = digitsSize + 1;
    } else {
        *returnSize = digitsSize;
    }
    return p;
}


/*
Difficulty:Easy
Total Accepted:181.2K
Total Submissions:469.5K


Companies Google
Related Topics Array Math
Similar Questions 
                
                  
                    Multiply Strings
                  
                    Add Binary
                  
                    Plus One Linked List
*/
