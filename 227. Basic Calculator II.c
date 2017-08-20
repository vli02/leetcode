/*
227. Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5




Note: Do not use the eval built-in library function.


Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

typedef struct {
    int *p;
    int sz;
    int n;
} s_t;
int parse(char **sp, int *k) {
    char *s = *sp;
    
    while (*s == ' ') s ++;
​
    *k = 0;
    
    if (*s == 0) return 0;
    
    if (*s == '+' || *s == '-' || *s == '*' || *s == '/') {
        *k = *s == '+' ? 1 :
             *s == '-' ? 2 :
             *s == '*' ? 3 : 4;
        *sp = ++ s;
        return 1;
    }
    
    while (*s >= '0' && *s <= '9') {
        *k = (*k) * 10 + *s - '0';
        s ++;
    }
    *sp = s;
    return 2;
}
void push(s_t *stack, int k) {
    if (stack->sz == stack->n) {
        stack->sz *= 2;
        stack->p = realloc(stack->p, stack->sz * sizeof(int));
        //assert(stack->p);
    }
    stack->p[stack->n ++] = k;
}
int low_op(s_t *ops, int k) {
    const int priority[] = { 0, 1, 1, 2, 2 }; // null, +, -, *, /
    return (priority[ops->p[ops->n - 1]] >= priority[k]) ? 1 : 0;
}
int calculate(char* s) {
    s_t data = { 0 }, ops = { 0 };
    int x, k, d1, d2, o;
​
    data.n = ops.n = 0;
    data.sz = ops.sz = 10;
    data.p = malloc(data.sz * sizeof(int));
    ops.p = malloc(ops.sz * sizeof(int));
    
    push(&data, 0); // put a zero in case of with a null input
    push(&ops, 0);  // put a null operator on top of operator stack
    
    do {
        x = parse(&s, &k);
        if (x == 2) {   // data, push to stack
            push(&data, k);
        } else {        // operator
            while (low_op(&ops, k)) {
                o = ops.p[-- ops.n];
                if (o == 0) break;      // the end
                d2 = data.p[-- data.n];
                d1 = data.p[-- data.n];
                switch (o) {
                    case 1: // '+'
                        d1 = d1 + d2;
                        break;
                    case 2: // '-'
                        d1 = d1 - d2;
                        break;
                    case 3: // '*'
                        d1 = d1 * d2;
                        break;
                    case 4: // '/'
                        d1 = d1 / d2;
                        break;
                    default:
                        break;
                }
                push(&data, d1);
            }
            if (k) push(&ops, k);
        }
    } while (x);
    
    //assert(ops.n == 0);
    k = data.p[data.n - 1];
    
    free(data.p);
    free(ops.p);
    
    return k;
}


/*
Difficulty:Medium
Total Accepted:49.3K
Total Submissions:168.9K


Companies Airbnb
Related Topics String
Similar Questions 
                
                  
                    Basic Calculator
                  
                    Expression Add Operators
*/
