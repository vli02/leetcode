/*
224. Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23




Note: Do not use the eval built-in library function.
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
    
    if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '(' || *s == ')') {
        *k = *s == '+' ? 1 :
             *s == '-' ? 2 :
             *s == '*' ? 3 :
             *s == '/' ? 4 :
             *s == '(' ? 5 : 6;
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
    const int priority[] = { 0, 2, 2, 3, 3, 1, 1 }; // null, +, -, *, /, (, )
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
        } else if (k == 5) {  // left parenthese, always push
            push(&ops, k);
        } else {        // operator
            while (low_op(&ops, k)) {
                o = ops.p[-- ops.n];
                if (o == 0 || o == 5) break; // end of input or left parenthese
                d2 = data.p[-- data.n];
                d1 = data.p[-- data.n];
                switch (o) {
                    case 1:             // '+'
                        d1 = d1 + d2;
                        break;
                    case 2:             // '-'
                        d1 = d1 - d2;
                        break;
                    case 3:             // '*'
                        d1 = d1 * d2;
                        break;
                    case 4:             // '/'
                        d1 = d1 / d2;
                        break;
                    default:
                        break;
                }
                push(&data, d1);
            }
            if (k && k != 6) push(&ops, k);  // ignore end or right parenthese
        }
    } while (x);
    
    //assert(ops.n == 0);
    k = data.p[data.n - 1];
    
    free(data.p);
    free(ops.p);
    
    return k;
}


/*
Difficulty:Hard
Total Accepted:51.6K
Total Submissions:190.7K


Companies Google
Related Topics Stack Math
Similar Questions 
                
                  
                    Evaluate Reverse Polish Notation
                  
                    Basic Calculator II
                  
                    Different Ways to Add Parentheses
                  
                    Expression Add Operators
*/
