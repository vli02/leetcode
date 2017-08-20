/*
415. Add Strings

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

char* addStrings(char* num1, char* num2) {
    int one, k, i;
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int l = l1 > l2 ? l1 : l2;
    char c1, c2;
    char *s, *buff;
    
    buff = malloc((l + 2) * sizeof(char));
    //assert(buff);
    
    i = l + 2;
    buff[-- i] = 0;  // null terminated
    one = 0;
    while (l1 > 0 || l2 > 0) {
        c1 = l1 > 0 ? num1[-- l1] : '0';
        c2 = l2 > 0 ? num2[-- l2] : '0';
        k = c1 - '0' + c2 - '0' + one;
        one = k / 10;
        k = k % 10;
        buff[-- i] = k + '0';
    }
    if (one) {
        buff[-- i] = '1';
        //assert(i == 0);
        s = buff;
    } else {
        s = malloc((l + 2) * sizeof(char));
        //assert(s);
        strcpy(s, &buff[i]);
        free(buff);
    }
    return s;
}


/*
Difficulty:Easy
Total Accepted:38.4K
Total Submissions:93K


Companies Google Airbnb
Related Topics Math
Similar Questions 
                
                  
                    Add Two Numbers
                  
                    Multiply Strings
*/
