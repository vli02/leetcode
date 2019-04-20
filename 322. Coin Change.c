/*
322. Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1


Note:
You may assume that you have an infinite number of each kind of coin.
*/

int coinChange(int* coins, int coinsSize, int amount) {
    int *dp, i, j, d, n;
    
    // can sort the coins first
    // amount = amount % the biggest coin
    
    dp = malloc((amount + 1) * sizeof(int));
    //assert(dp);
    dp[0] = 0;
    
    for (i = 1; i <= amount; i ++) {
        n = -1;
        for (j = 0; j < coinsSize; j ++) {
            if (i >= coins[j]) {
                d = i - coins[j];
                if (dp[d] != -1 && (n == -1 || n > dp[d] + 1)) {
                    n = dp[d] + 1;  // plus one of this coin
                }
            }
        }
        dp[i] = n;
    }

    n = dp[amount];
    
    free(dp);
    
    return n;
}


/*
Difficulty:Medium


*/
