/*
736. Parse Lisp Expression

You are given a string expression representing a Lisp-like expression to return the integer value of.

The syntax for these expressions is given as follows.

An expression is either an integer, a let-expression, an add-expression, a mult-expression, or an assigned variable.  Expressions always evaluate to a single integer.

(An integer could be positive or negative.)

A let-expression takes the form (let v1 e1 v2 e2 ... vn en expr), where let is always the string "let", then there are 1 or more pairs of alternating variables and expressions, meaning that the first variable v1 is assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, and so on sequentially; and then the value of this let-expression is the value of the expression expr.

An add-expression takes the form (add e1 e2) where add is always the string "add", there are always two expressions e1, e2, and this expression evaluates to the addition of the evaluation of e1 and the evaluation of e2.

A mult-expression takes the form (mult e1 e2) where mult is always the string "mult", there are always two expressions e1, e2, and this expression evaluates to the multiplication of the evaluation of e1 and the evaluation of e2.

For the purposes of this question, we will use a smaller subset of variable names.  A variable starts with a lowercase letter, then zero or more lowercase letters or digits.  Additionally for your convenience, the names "add", "let", or "mult" are protected and will never be used as variable names.

Finally, there is the concept of scope.  When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially.  It is guaranteed that every expression is legal.  Please see the examples for more details on scope.


Evaluation Examples:
Input: (add 1 2)
Output: 3

Input: (mult 3 (add 2 3))
Output: 15

Input: (let x 2 (mult x 5))
Output: 10

Input: (let x 2 (mult x (let x 3 y 4 (add x y))))
Output: 14
Explanation: In the expression (add x y), when checking for the value of the variable x,
we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
Since x = 3 is found first, the value of x is 3.

Input: (let x 3 x 2 x)
Output: 2
Explanation: Assignment in let statements is processed sequentially.

Input: (let x 1 y 2 x (add x y) (add x y))
Output: 5
Explanation: The first (add x y) evaluates as 3, and is assigned to x.
The second (add x y) evaluates as 3+2 = 5.

Input: (let x 2 (add (let x 3 (let x 4 x)) x))
Output: 6
Explanation: Even though (let x 4 x) has a deeper scope, it is outside the context
of the final x in the add-expression.  That final x will equal 2.

Input: (let a1 3 b2 (add a1 1) b2) 
Output 4
Explanation: Variable names can contain digits after the first character.



Note:
The given string expression is well formatted: There are no leading or trailing spaces, there is only a single space separating different components of the string, and no space between adjacent parentheses.  The expression is guaranteed to be legal and evaluate to an integer.
The length of expression is at most 2000.  (It is also non-empty, as that would not be a legal expression.)
The answer and all intermediate calculations of that answer are guaranteed to fit in a 32-bit integer.
*/

#define TYPE_INT    0
#define TYPE_ID     1

typedef struct {
    char *p;
    int len;
} idn_t;

typedef struct {
    int type;       // 0: identifier, 1: value
    union {
        idn_t id;
        int num;
    } u;
} expr_t;

typedef struct sym_s {
    idn_t id;
    int val;
    int scope;
    struct sym_s *list;
} sym_t;

typedef struct {
    char *input;
    sym_t *sym;
} p_t;

#define IS_LET(E)  ((E)[0] == 'l' && \
                    (E)[1] == 'e' && \
                    (E)[2] == 't' && \
                    (E)[3] == ' ')
#define IS_ADD(E)  ((E)[0] == 'a' && \
                    (E)[1] == 'd' && \
                    (E)[2] == 'd' && \
                    (E)[3] == ' ')
#define IS_MULT(E) ((E)[0] == 'm' && \
                    (E)[1] == 'u' && \
                    (E)[2] == 'l' && \
                    (E)[3] == 't' && \
                    (E)[4] == ' ')
#define IS_NUM(E)  ((E)[0] >= '0' && \
                    (E)[0] <= '9')

char *next_input(char *input) {
    int n = 0;
    char c;
    while (c = *(input ++)) {
        if (c == '(') n ++;
        else if (c == ')') {
            if (n) n --;
            else {
                *(input - 1) = 0;
                break;
            }
        }
    }
    if (*input == ' ') input ++;
    //assert(0);
    return input;
}

idn_t parse_identifier(p_t *p) {
    char c;
    idn_t id;

    id.p = p->input;
    do {
        c = *(++ p->input);
    } while (c != 0 && c != ' ');

    id.len = p->input - id.p;

    if (c == ' ') p->input ++;

    return id;
}

expr_t parse_num(p_t *p) {
    expr_t expr;
    int neg = 0;
    
    if (*p->input == '-') {
        neg = 1;
        p->input ++;
    }
    
    expr.type = TYPE_INT;
    expr.u.num = 0;
    do {
        expr.u.num = expr.u.num * 10 + *p->input - '0';
        p->input ++;
    } while (IS_NUM(p->input));
    
    if (neg) {
        expr.u.num = 0 - expr.u.num;
    }
    
    if (*p->input == ' ') p->input ++;
    
    return expr;
}

expr_t resolve(p_t *p, expr_t a) {
    sym_t *sym;

    if (a.type == TYPE_ID) {
        sym = p->sym;
        while (a.u.id.len != sym->id.len ||
               strncmp(a.u.id.p, sym->id.p, sym->id.len)) sym = sym->list;
        a.type = TYPE_INT;
        a.u.num = sym->val;
    }

    return a;
}

expr_t parse(p_t *, int);

expr_t parse_let(p_t *p, int d) {
    char c;
    sym_t *sym;
    expr_t a, b;
    while (c = *p->input) {
        if (c == ' ') {
            p->input ++;
            continue;
        }
        a = parse(p, d);
        if (a.type == TYPE_INT) break;
        if (*p->input) {
            b = parse(p, d);
            b = resolve(p, b);
            sym = malloc(sizeof(*sym));
            //assert(sym);
            sym->id = a.u.id;
            sym->val = b.u.num;
            sym->scope = d;
            sym->list = p->sym;
            p->sym = sym;
        }
    }
    if (a.type == TYPE_ID) {
        a = resolve(p, a);
    }
    sym = p->sym;
    while (sym && sym->scope == d) {
        p->sym = sym->list;
        free(sym);
        sym = p->sym;
    }
    return a;
}

expr_t parse(p_t *p, int d) {
    char c, *next;
    expr_t a, b, sym, expr;

    if ((c = *p->input) == '(') {
        p->input ++;
        next = next_input(p->input);
        expr = parse(p, d + 1);
        p->input = next;
    } else if (IS_LET(p->input)) {
        p->input += 4;
        expr = parse_let(p, d);
    } else if (IS_ADD(p->input)) {
        p->input += 4;
        a = parse(p, d);
        b = parse(p, d);
        a = resolve(p, a);
        b = resolve(p, b);
        expr.type = TYPE_INT;
        expr.u.num = a.u.num + b.u.num;
    } else if (IS_MULT(p->input)) {
        p->input += 5;
        a = parse(p, d);
        b = parse(p, d);
        a = resolve(p, a);
        b = resolve(p, b);
        expr.type = TYPE_INT;
        expr.u.num = a.u.num * b.u.num;
    } else if (IS_NUM(p->input) ||
               *p->input == '-') {
        expr = parse_num(p);
    } else {
        expr.type = TYPE_ID;
        expr.u.id = parse_identifier(p);
    }

    //assert(*p->input == 0);

    return expr;
}

int evaluate(char * expression) {
    expr_t result;
    p_t p = { 0 };
    p.input = expression;
    result = parse(&p, 0);
    return result.u.num;
}


/*
Difficulty:Hard


*/
