/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

bool isValid(char* s) {
    int l;
    char *stack;
    int sp = 0;
    
    if (!s || !*s) return true;
    
    l = strlen(s);
    stack = malloc(l * sizeof(char));
    //assert(stack);
    while (*s) {
        if (*s == '(' || *s == '{' || *s == '[') {
            stack[sp ++] = *s;
        } else if (sp == 0) {
            free(stack);
            return false;
        } if (*s == ')') {
            if (stack[-- sp] != '(') { free(stack); return false; }
        } else if (*s == '}') {
            if (stack[-- sp] != '{') { free(stack); return false; }
        } else if (*s == ']') {
            if (stack[-- sp] != '[') { free(stack); return false; }
        }
        s ++;
    }
    
    free(stack);
    return sp == 0 ? true : false;
}


/*
Difficulty:Easy
Total Accepted:224.5K
Total Submissions:672.8K


Companies Google Airbnb Facebook Twitter Zenefits Amazon Microsoft Bloomberg
Related Topics Stack String
Similar Questions 
                
                  
                    Generate Parentheses
                  
                    Longest Valid Parentheses
                  
                    Remove Invalid Parentheses
*/
