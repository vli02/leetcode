/*
70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Note: Given n will be a positive integer.
*/

int climbStairs(int n) {
    int p, pp, k, i;
    
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    p = 2;
    pp = 1;
    
    for (i = 3; i <= n; i++) {
        k = p + pp;
        pp = p;
        p  = k;
    }
    
    return p;
}


/*
Difficulty:Easy
Total Accepted:186.3K
Total Submissions:465.8K


Companies Adobe Apple
Related Topics Dynamic Programming

*/
