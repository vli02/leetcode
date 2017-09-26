/*
621. Task Scheduler

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle. 

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.



Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

int cmp(const void *a, const void *b) {
    return *(int *)a < *(int *)b ?  1 :
           *(int *)a > *(int *)b ? -1 : 0;
}
int leastInterval(char* tasks, int tasksSize, int n) {
    int c[26] = { 0 };
    int i, k;
    for (i = 0; i < tasksSize; i ++) {
        c[tasks[i] - 'A'] ++;
    }
    qsort(c, 26, sizeof(int), cmp);
    i = 1;
    while (i < 26 && c[i] == c[0]) {
        i ++;
    }
    k = (c[0] - 1) * (n + 1) + i;
    return tasksSize > k ? tasksSize : k;
}


/*
Difficulty:Medium
Total Accepted:11.8K
Total Submissions:27.8K


Companies Facebook
Related Topics Array Greedy Queue
Similar Questions 
                
                  
                    Rearrange String k Distance Apart
*/
