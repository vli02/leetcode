/*
241. Different Ways to Add Parentheses

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1". 
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2
Input: "2*3-4*5" 
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10] 

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int *p;
    int sz;
    int n;
} res_t;
int str2int(char *s, int start, int end) {
    int k = 0;
    int i;
    for (i = start; i <= end; i ++) {
        k = k * 10 + s[i] - '0';
    }
    return k;
}
void add2res(res_t *res, int k) {
    if (res->sz == 0) {
        res->sz = 10;
        res->p = malloc(res->sz * sizeof(int));
        //assert(res->p);
    } else if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(int));
        //assert(res->p);
    }
    res->p[res->n ++] = k;
}
res_t split_compute(char *s, int start, int end) {
    res_t op1, op2, res = { 0 };
    char c;
    int i, x, y, a, b;
    
    for (i = start; i <= end; i ++) {
        c = s[i];
        if (c == '+' || c == '-' || c == '*') {
            op1 = split_compute(s, start, i - 1);
            op2 = split_compute(s, i + 1, end);
            for (x = 0; x < op1.n; x ++) {
                a = op1.p[x];
                for (y = 0; y < op2.n; y ++) {
                    b = op2.p[y];
                    add2res(&res, c == '+' ? a + b :
                                  c == '-' ? a - b :
                                             a * b);
                }
            }
            free(op1.p);
            free(op2.p);
        }
    }
    
    if (res.n == 0) {
        add2res(&res, str2int(s, start, end));
    }
    
    return res;
}
int* diffWaysToCompute(char* input, int* returnSize) {
    res_t res;
    res = split_compute(input, 0, strlen(input) - 1);
    *returnSize = res.n;
    return res.p;
}


/*
Difficulty:Medium
Total Accepted:45.6K
Total Submissions:103.7K


Related Topics Divide and Conquer
Similar Questions Unique Binary Search Trees II Basic Calculator Expression Add Operators

*/
