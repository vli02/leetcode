/*
935. Knight Dialer

A chess knight can move as indicated in the chess diagram below:

 .           

 

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

 





Example 1:

Input: 1
Output: 10



Example 2:

Input: 2
Output: 20



Example 3:

Input: 3
Output: 46


 

Note:


	1 <= N <= 5000
*/

#define MOD 1000000007

const int map[][4] = {
    /* 0 */ { 4, 6, -1 },
    /* 1 */ { 6, 8, -1 },
    /* 2 */ { 7, 9, -1 },
    /* 3 */ { 4, 8, -1 },
    /* 4 */ { 3, 9, 0, -1 },
    /* 5 */ { -1 },
    /* 6 */ { 1, 7, 0, -1 },
    /* 7 */ { 2, 6, -1 },
    /* 8 */ { 1, 3, -1 },
    /* 9 */ { 2, 4, -1 }
};

/* simple back tracking, need to add memorization to pass TLE */
#if 0
int helper(int p, int n) {
    int *m, s, steps = 0;
    
    if (n == 0) return 1;
    if (p == 5) return -1;
    
    m = map[p];
    while (*m != -1) {
        s = helper(*m, n - 1);
        if (s > 0) steps += s;
        m ++;
    }
    
    return steps;
}
#endif

int knightDialer(int N) {
    int buff[20] = { 0 };
    int *p, *n, *t, i, k = 0;
    
    p = buff;
    n = &buff[10];
    
    p[0] = p[1] = p[2] = p[3] = p[4] =
    p[5] = p[6] = p[7] = p[8] = p[9] = 1;
    
    if (N > 1) p[5] = 0;
    
    while (N -- > 1) {
        n[0] = (p[4] + p[6]) % MOD;
        n[1] = (p[6] + p[8]) % MOD;
        n[2] = (p[7] + p[9]) % MOD;
        n[3] = (p[4] + p[8]) % MOD;
        n[4] = ((p[3] + p[9]) % MOD + p[0]) % MOD;
        n[6] = ((p[1] + p[7]) % MOD + p[0]) % MOD;
        n[7] = (p[2] + p[6]) % MOD;
        n[8] = (p[1] + p[3]) % MOD;
        n[9] = (p[2] + p[4]) % MOD;
        t = p;
        p = n;
        n = t;
    }
    
    for (i = 0; i < 10; i ++) {
        k = (k + p[i]) % MOD;
    }
    
    return k;
}


/*
Difficulty:Medium


*/
