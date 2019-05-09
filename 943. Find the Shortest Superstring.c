/*
943. Find the Shortest Superstring

Given an array A of strings, find any smallest string that contains each string in A as a substring.

We may assume that no string in A is substring of another string in A.

 


Example 1:

Input: ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.



Example 2:

Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"

 



Note:


	1 <= A.length <= 12
	1 <= A[i].length <= 20
*/

int tail_length(const char *a, int la, const char *b, int lb) {
    int i = 0;
    int max = la < lb ? la - 1 : lb - 1;    // max overlap characters
    while (max && strncmp(&a[la - max], b, max)) {
        max --;
    }
    return lb - max;
}
char * shortestSuperstring(char ** A, int ASize){
    int *len, *addition, *dp, *prev, *stack;
    int sz, i, j, p, k, l, sp;
    int min = 0, last;
    
    char *s, *t;
    
    len = malloc(ASize * sizeof(int));
    //assert(len);
    
    for (i = 0; i < ASize; i ++) {
        len[i] = strlen(A[i]);
    }
    
    addition = calloc(ASize * ASize, sizeof(int));
    //assert(addition);
#define IDX(I, J) ((I) * ASize + (J))
    
    for (i = 0; i < ASize; i ++) {
        for (j = i + 1; j < ASize; j ++) {
            // additional length of A[i] if combine it with A[j]
            addition[IDX(i, j)] = tail_length(A[i], len[i], A[j], len[j]);
            addition[IDX(j, i)] = tail_length(A[j], len[j], A[i], len[i]);
        }
    }
    
    sz = (1 << ASize);  // each bit of (sz - 1) identifies one string in A
    
    dp = calloc(sz * ASize, sizeof(int));
    prev = calloc(sz * ASize, sizeof(int));
    //assert(dp && path);
#define IDX2(I, J) ((I) * (ASize) + (J))
    
    for (i = 0; i < ASize; i ++) {
        dp[IDX2(1 << i, i)] = len[i];   // when there is no parent, the length is itself.
    }
    
    for (i = 1; i < sz; i ++) {         // current combination of strings being selected
        for (j = 0; j < ASize; j ++) {  // the one in the ends in above combination
            if (!(i & (1 << j))) continue;  // if A[j] is not in the above combination
            p = i & ~(1 << j);          // new combination excluding current string A[j]
            for (k = 0; k < ASize; k ++) {
                if (dp[IDX2(p, k)]) {   // if the length of the new combination with A[k] in the end is known
                    l = dp[IDX2(p, k)] + addition[IDX(k, j)];
                    if (dp[IDX2(i, j)] == 0 ||
                        dp[IDX2(i, j)] > l) {
                        dp[IDX2(i, j)] = l;
                        prev[IDX2(i, j)] = k;   // A[j] is after A[k]
                    }
                }
            }
            if (i == sz - 1 &&              // all strings are selected
                (l = dp[IDX2(i, j)]) &&
                (min == 0 || min > l)) {    // and a minimal length is found
                min = l;
                last = j;                   // record the ending string A[j]
            }
        }
    }
    
    stack = malloc(ASize * sizeof(int));
    //assert(stack);
    sp = 0;
    
    p = sz - 1;             // all are selected
    while (p > 0) {
        stack[sp ++] = last;
        l = p;
        p &= ~(1 << last);
        last = prev[IDX2(l, last)];
    }
    
    s = malloc((min + 1) * sizeof(char));
    //assert(s);
    
    i = stack[ -- sp];
    strcpy(s, A[i]);
    
    while (sp) {
        j = stack[ -- sp];
        t = A[j];
        strcat(s, &t[len[j] - addition[IDX(i, j)]]);
        i = j;
    }
    
    free(len);
    free(addition);
    free(dp);
    free(prev);
    free(stack);
    
    return s;
}


/*
Difficulty:Hard


*/
