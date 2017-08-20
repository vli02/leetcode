/*
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.


For "(()", the longest valid parentheses substring is "()", which has length = 2.


Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

int longestValidParentheses(char* s) {
    int i, l, n, *v;
    int max;
    
    if (!s) return 0;
    
    l = strlen(s);
    v = malloc(l * sizeof(int));
    if (!v) return -1;
    
    i = 0; n = 0;
    while (i < l) {
        if (s[i] == '(') {
            v[i] = 1;
            n ++;
        } else /*if (s[i] == ')')*/ {
            if (n > 0) {
                n --;
                v[i] = 1;
            } else {
                v[i] = 0;
            }
        }
        i ++;
    }
    
    i = l; n = 0;
    while (i > 0) {
        i --;
        if (s[i] == ')') {
            if (v[i]) {
                n ++;
            }
        } else /*if (s[i] == '(')*/ {
            if (n > 0) {
                n --;
            } else {
                v[i] = 0;
            }
        }
    }
    
    i = 1; n = 0; max = 0;
    while (i < l) {
        if (v[i]) {
            v[i] = v[i - 1] + 1;
        
            if (max < v[i]) {
                max = v[i];
            }
        }
        i ++;
    }
    
    return max;
}


/*
Difficulty:Hard
Total Accepted:100.6K
Total Submissions:436.1K


Related Topics Dynamic Programming String
Similar Questions Valid Parentheses

*/
