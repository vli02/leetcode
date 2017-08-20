/*
65. Valid Number

Validate if a given string is numeric.


Some examples:
"0" => true
"   0.1  " => true
"abc" => false
"1 a" => false
"2e10" => true


Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.



Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

bool isNumber(char* s) {
    int n, m;
    
    // skip leading spaces
    while (*s == ' ') s ++;
    
    n = m = 0;
    
    // skip the sign of the number
    if (*s == '+' || *s == '-') s ++;
    
    while (*s >= '0' && *s <= '9') {
        n ++;
        s ++;
    }
    
    if (*s == '.') {
        s ++;
        while (*s >= '0' && *s <= '9') {
            m ++;
            s ++;
        }
        if (!n && !m) return false;
    } else if (!n) {
        return false;
    }
    
    if (*s == 'e' || *s == 'E') {
        s ++;
        if (*s == '+' || *s == '-') s ++;
        n = 0;
        while (*s >= '0' && *s <= '9') {
            n ++;
            s ++;
        }
        if (!n) return false;
    }
    
    while (*s == ' ') s ++;
    
    return *s == 0 ? true : false;
}


/*
Difficulty:Hard
Total Accepted:70K
Total Submissions:550K


Companies LinkedIn
Related Topics Math String
Similar Questions 
                
                  
                    String to Integer (atoi)
*/
