/*
636. Exclusive Time of Functions

Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions. 

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts from the very beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0. 

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.

Example 1:
Input:
n = 2
logs = 
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
Explanation:
Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1. 
Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time. 
So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.



Note:

Input logs will be sorted by timestamp, NOT log id.
Your output should be sorted by function id, which means the 0th element of your output corresponds to the exclusive time of function 0.
Two functions won't start or end at the same time.
Functions could be called recursively, and will always end.
1 <= n <= 100
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int *p;
    int sp;
    int sz;
} s_t;

void push(s_t *stack, int tx) {
    if (stack->sz == stack->sp) {
        stack->sz *= 2;
        stack->p = realloc(stack->p, stack->sz * sizeof(int));
        //assert(stack->p);
    }
    stack->p[stack->sp ++] = tx;
}
    
int pop(s_t *stack) {
    return stack->p[-- stack->sp];
}
    
void update(s_t *stack, int tx) {
    int i;
    for (i = 0; i < stack->sp; i ++) {
        stack->p[i] += tx;
    }
}

void parse(char *log, int *fid, int *d, int *t) {
    char c;
    *fid = 0;
    while ((c = *(log ++)) != ':') {
        *fid = (*fid) * 10 + c - '0';
    }
    if (*log == 'e') {  // end
        log += 4;
        *d = 0;
    } else {
        log += 6;
        *d = 1;
    }
    *t = 0;
    while ((c = *(log ++)) != 0) {
        *t = (*t) * 10 + c - '0';
    }
}

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    s_t stack;
    int *res, i, fid, d, t;
    
    stack.sz = 100;
    stack.sp = 0;
    stack.p = malloc(stack.sz * sizeof(int));
    //assert(stack.p);
    
    res = calloc(n, sizeof(int));
    //assert(t);
    
    *returnSize = n;
    
    for (i = 0; i < logsSize; i ++) {
        parse(logs[i], &fid, &d, &t);
        if (d) {
            push(&stack, t);
        } else {
            t = t - pop(&stack) + 1;
            update(&stack, t);
            res[fid] += t;
        }
    }
    
    free(stack.p);
    
    return res;
}

/*
Difficulty:Medium
Total Accepted:5.9K
Total Submissions:13.8K


Companies Facebook
Related Topics Stack

*/
