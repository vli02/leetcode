/*
464. Can I Win

In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins. 

What if we change the game so that players cannot re-use integers? 

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally. 

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.


Example
Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/

int addwin(int v, int *dp, int k, int m, int total) {
    int i, hewins;
    
    for (i = m - 1; i >= 0; i --) {
        if (!(v & (1 << i))) {
            if (k + i + 1 >= total) return 1;  // very tricky, cannot be outside the for loop.
            v |= (1 << i);
            hewins = dp[v - 1];
            if (hewins == -1) {
                hewins = addwin(v, dp, k + i + 1, m, total);
                dp[v - 1] = hewins;
            }
            v &= ~(1 << i);
            if (!hewins) return 1;
        }
    }
    return 0;
}
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int w, v, *dp;
    
    // none can win
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
    
    v = 0;
    dp = calloc((1 << maxChoosableInteger), sizeof(int));
    //assert(dp);
    memset(dp, -1, (1 << maxChoosableInteger) * sizeof(int));
    
    w = addwin(v, dp, 0, maxChoosableInteger, desiredTotal);
    
    free(dp);
    
    return w;
}


/*
Difficulty:Medium
Total Accepted:12.4K
Total Submissions:49.9K


Companies LinkedIn
Related Topics Dynamic Programming Minimax
Similar Questions 
                
                  
                    Flip Game II
                  
                    Guess Number Higher or Lower II
                  
                    Predict the Winner
*/
