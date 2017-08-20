/*
375. Guess Number Higher or Lower II

We are playing the Guess Game. The game is as follows: 

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower. 

However, when you guess a particular number x,  and you guess wrong, you pay $x. You win the game when you guess the number I picked.


Example:
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.



Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Credits:Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.
*/

#define IDX(START, END, SZ) ((START - 1) * SZ + (END - 1))
​
int dp(int *p, int start, int end, int sz) {
    int i, l, r, k, m;
    
    if (start >= end) return 0;
    
    m = p[IDX(start, end, sz)];
    if (m) return m;
    
    for (i = start; i <= end; i ++) {
        k = i;
        l = dp(p, start, i - 1, sz);
        r = dp(p, i + 1, end, sz);
        k += l > r ? l : r;
        if (m == 0 || m > k) m = k;
    }
    p[IDX(start, end, sz)] = m;
    return m;
}
int getMoneyAmount(int n) {
    int *p = calloc(n * n, sizeof(int));
    int m = dp(p, 1, n, n);
    free(p);
    return m;
}


/*
Difficulty:Medium
Total Accepted:22.7K
Total Submissions:63.4K


Companies Google
Related Topics Dynamic Programming Minimax
Similar Questions 
                
                  
                    Flip Game II
                  
                    Guess Number Higher or Lower
                  
                    Can I Win
                  
                    Find K Closest Elements
*/
