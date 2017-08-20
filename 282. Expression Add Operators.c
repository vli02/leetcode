/*
282. Expression Add Operators

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.


Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []


Credits:Special thanks to @davidtan1890 for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **p;
    int sz;
    int n;
} res_t;
int str2int(char *num, int l) {
    int k, i;
    k = 0;
    while (l -- > 0) {
        i = *num - '0';
        if (k > 0xffffffff - i) {
            return -1;
        }
        k = k * 10 + i;
        num ++;
    }
    return k;
}
void add2res(char *buff, res_t *res) {
    if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = strdup(buff);
}
void bt(char *num, int s, int e, int n, int m, int target, char *buff, int d, res_t *res) {
    int l, k;
    
    if (s == e) {  // start == end, done!
        if (n == target) {
            buff[d] = 0;
            add2res(buff, res);
        }
        return;
    }
    
    for (l = 1; l <= e - s && l <= 10; l ++) {
        if (l > 1 && num[s] == '0') break;
        k = str2int(&num[s], l);
        if (k < 0) break;
        if (!d) {
            strncpy(buff, &num[s], l);
            bt(num, s + l, e, k, k, target, buff, l, res);
        } else {
            strncpy(&buff[d + 1], &num[s], l);
            buff[d] = '+';
            bt(num, s + l, e, n + k, k, target, buff, d + 1 + l, res);
            buff[d] = '-';
            bt(num, s + l, e, n - k, -k, target, buff, d + 1 + l, res);
            buff[d] = '*';
            bt(num, s + l, e, n - m + m * k, m * k, target, buff, d + 1 + l, res);
        }
    }
}
char** addOperators(char* num, int target, int* returnSize) {
    res_t res;
    char *buff;
    int l;
    
    res.sz = 10;
    res.p = malloc(res.sz * sizeof(char *));
    //assert(res.p);
    res.n = 0;
    
    l = strlen(num);
    buff = malloc(l * 2 * sizeof(char));
    //assert(buff);
    
    bt(num, 0, l, 0, 0, target, buff, 0, &res);
    
    free(buff);
    
    *returnSize = res.n;
    return res.p;
}


/*
Difficulty:Hard
Total Accepted:33.1K
Total Submissions:111.5K


Companies Google Facebook
Related Topics Divide and Conquer
Similar Questions 
                
                  
                    Evaluate Reverse Polish Notation
                  
                    Basic Calculator
                  
                    Basic Calculator II
                  
                    Different Ways to Add Parentheses
                  
                    Target Sum
*/
