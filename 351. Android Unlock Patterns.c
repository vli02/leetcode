/*
351. Android Unlock Patterns

Given an Android 3x3 key lock screen and two integers m and n, where  1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:

Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.





Explanation:

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |



Invalid move: 4 - 1 - 3 - 6 

Line  1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2

Line  1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6

Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2

Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.


Credits:Special thanks to @elmirap for adding this problem and creating all test cases.
*/

#define PRINT_START() do { } while (0)
#define PRINT_SEQ() do { } while (0)
#define PRINT_NL() do { } while (0)
​
int map[10][10][2] = {
/*       0        1        2        3        4        5        6        7        8        9    */
/*0*/{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 }},
/*1*/{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 2 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 4 },{ 0, 0 },{ 0, 5 }},
/*2*/{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 5 },{ 0, 0 }},
/*3*/{ { 0, 0 },{ 0, 2 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 5 },{ 0, 0 },{ 0, 6 }},
/*4*/{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 5 },{ 0, 0 },{ 0, 0 },{ 0, 0 }},
/*5*/{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 }},
/*6*/{ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 5 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 }},
/*7*/{ { 0, 0 },{ 0, 4 },{ 0, 0 },{ 0, 5 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 8 }},
/*8*/{ { 0, 0 },{ 0, 0 },{ 0, 5 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 }},
/*9*/{ { 0, 0 },{ 0, 5 },{ 0, 0 },{ 0, 6 },{ 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 8 },{ 0, 0 },{ 0, 0 }}
};
void pattern(int x, int d, int *k, int *visited) {
    int i;
    if (d == 0) {
        PRINT_NL();
        (*k) ++;
        return;
    }
    visited[x] = 1;
    for (i = 1; i < 10; i ++) {
        if (!visited[i] && visited[map[x][i][0]] && visited[map[x][i][1]]) {
            PRINT_SEQ();
            pattern(i, d - 1, k, visited);
        }
    }
    visited[x] = 0;
}
int numberOfPatterns(int m, int n) {
    int visited[10] = { 0 };
    int d, x, t, k;
    visited[0] = 1;
    t = 0;
    for (d = m; d <= n; d ++) {
        for (x = 1; x < 10; x ++) {
            PRINT_START();
            k = 0;
            pattern(x, d - 1, &k, visited);
            t += k;
        }
    }
    return t;
}


/*
Difficulty:Medium
Total Accepted:14.3K
Total Submissions:32.7K


Companies Google
Related Topics Dynamic Programming Backtracking

*/
