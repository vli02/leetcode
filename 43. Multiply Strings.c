/*
43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

char* multiply(char* num1, char* num2) {
    int l1, l2, l3, *n3, i, j, a, b, x, k;
    char *p;
    
    l1 = strlen(num1);
    l2 = strlen(num2);
    l3 = l1 + l2;
    
    n3 = calloc(l3, sizeof(int));
    //assert(n3);
    
    for (i = l1 - 1; i >= 0; i --) {
        a = num1[i] - '0';
        k = 0;  // carry over
        for (j = l2 - 1; j >= 0; j --) {
            b = num2[j] - '0';
            x = n3[i + j + 1] + k + a * b;
            k = x / 10;
            n3[i + j + 1] = x % 10;
        }
        n3[i + j + 1] += k;
    }
    i = 0;
    while (i < l3 && !n3[i]) {
        i ++;
    }
    j = 0;
    if (i == l3) {
        p = malloc(2 * sizeof(char));
        //assert(p);
        p[j ++] = '0';
    } else {
        p = malloc((l3 - i + 1) * sizeof(char));
        //assert(p);
        while (i < l3) {
            p[j ++] = '0' + n3[i ++];
        }
    }
    p[j] = 0;
    
    free(n3);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:107.8K
Total Submissions:398.6K


Companies Facebook Twitter
Related Topics Math String
Similar Questions 
                
                  
                    Add Two Numbers
                  
                    Plus One
                  
                    Add Binary
                  
                    Add Strings
*/
