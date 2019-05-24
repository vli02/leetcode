/*
394. Decode String

Given an encoded string, return it's decoded string.


The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.


You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].


Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

struct node {
    char *leading_string;
    int leading_len;
    int repeat;
};

char* decodeString(char* s) {
    struct node stack[100], *p;
    int sp = 0;
    
    int n;
    
    char *buff;
    int sz, len;
    
    char *newbuff = NULL;
    int newsz, newlen;
        
    buff = NULL;
    sz = len = 0;
    n = 0;
    while (*s) {
        if (*s == '[') {
            p = &stack[sp ++];  // push and save
            
            p->leading_string = buff;
            p->leading_len = len;
            buff = NULL;
            sz = len = 0;
            
            p->repeat = n;
            n = 0;            
        } else if (*s == ']') {
            p = &stack[-- sp];  // pop and expand
            
            newlen = p->leading_len + p->repeat * len;
            newsz = newlen + 10;
            newbuff = realloc(p->leading_string, newsz * sizeof(char));
            //assert(newbuff);
            if (!p->leading_string) {
                newbuff[0] = 0;
            }
            while (p->repeat) {
                strcat(newbuff, buff);
                p->repeat --;
            }
            free(buff);
            sz = newsz;
            len = newlen;
            buff = newbuff;
        } else if (*s >= '0' && *s <= '9') {
            n = n * 10 + (*s) - '0';
        } else {
            if (len + 1 >= sz) {
                if (sz == 0) sz = 10;
                else sz *= 2;
                buff = realloc(buff, sz * sizeof(char));
                //assert(buff);
            }
            buff[len ++] = *s;
            buff[len] = 0; // null terminated
        }
        s ++;
    }
    if (!buff) buff = calloc(1, sizeof(char));
    //assert(buff);
    return buff;
}

// a very typical yacc grammar:
/*
decoded_string:
      letters
    | pattern
    | decoded_string letters
    | decoded_string pattern
    ;
pattern:
      number '[' decoded_string ']'
    ;
*/


/*
Difficulty:Medium
Total Accepted:33.6K
Total Submissions:81.5K


Companies Google
Related Topics Depth-first Search Stack
Similar Questions 
                
                  
                    Encode String with Shortest Length
*/
