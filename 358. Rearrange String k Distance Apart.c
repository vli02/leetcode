/*
358. Rearrange String k Distance Apart

Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.


All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
s = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.



Example 2:
s = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.



Example 3:
s = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.



Credits:Special thanks to @elmirap for adding this problem and creating all test cases.
*/

typedef struct {
    char c;
    int n;
} e_t;
int ecmp(const void *a, const void *b) {
    return ((e_t *)b)->n - ((e_t *)a)->n;
}
char* rearrangeString(char* str, int k) {
    e_t e[26] = { 0 };
    int len = 0, i, j = 0, n;
    char *s = str, *p;
​
    if (!k) return str;
    
    while (*s) {
        i = *s - 'a';
        e[i].c = *s;
        e[i].n ++;
        len ++;
        s ++;
    }
    p = malloc(len + 1);
    //assert(p);
    p[len] = 0;
​
arrange:    
    qsort(e, 26, sizeof(e_t), ecmp);
    n = 0;
    for (i = 0; i < 26 && e[i].n > 0 && n < k; i ++) {
        p[j ++] = e[i].c;
        e[i].n --;
        len --;
        n ++;
    }
    if (len) {
        if (n < k) {
            p[0] = 0;
        } else {
            goto arrange;
        }
    }
​
    return p;
}


/*
Difficulty:Hard
Total Accepted:10.3K
Total Submissions:32.3K


Companies Google
Related Topics Hash Table Heap Greedy
Similar Questions 
                
                  
                    Task Scheduler
*/
