/*
71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"


click to show corner cases.

Corner Cases:



Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

char *dirname(char **path) {
    char *start, *end;
    
    start = *path;
    while (*start && *start == '/') {
        start ++;
    }
    
    if (!*start) return NULL;
    
    end = start + 1;
    while (*end && *end != '/') {
        end ++;
    }
    if (*end) {
        *end = 0;
        end ++;
    }
    *path = end;
    
    return start;
}
char* simplifyPath(char* path) {
    char *buff, *p;
    char **stack;
    int sz, sp, i;
    
    int len = strlen(path);
    
    while (*path && *path != '/') path ++;
    
    sz = 100;
    stack = malloc(sz * sizeof(char *));
    //assert(stack);
    sp = 0;
    
#define PUSH(P) do { stack[sp ++] = P; } while (0)
#define POP()   do { if (sp) stack[-- sp]; } while (0)
    
    buff = calloc((len + 1), sizeof(char));
    //assert(buff);
    if (*path == '/') {
        buff[0] = '/';
    }
    
    p = dirname(&path);
    while (p) {
        printf("%s, ", p);
        if (*p == '.' && *(p + 1) == 0) {
            // skip it
        } else if (*p == '.' && *(p + 1) == '.' && *(p + 2) == 0) {
            POP();
        } else {
            PUSH(p);
        }
        p = dirname(&path);
    }
    
    for (i = 0; i < sp; i ++) {
        if (i) strcat(buff, "/");
        strcat(buff, stack[i]);
    }
    
    free(stack);
    
    return buff;
}


/*
Difficulty:Medium
Total Accepted:90.8K
Total Submissions:359.7K


Companies Microsoft Facebook
Related Topics Stack String

*/
