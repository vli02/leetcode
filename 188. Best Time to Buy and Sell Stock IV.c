/*
188. Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

int _max(int a, int b) {
    return a > b ? a : b;
}
int all_profits(int* prices, int pricesSize) {
    int i, d, p;
        
    p = 0;
    for (i = 1; i < pricesSize; i ++) {
        d = prices[i] - prices[i - 1];
        p = d > 0 ? p + d : p;  // get it as long as it is a profit!
    }

    return p;
}
int maxProfit(int k, int* prices, int pricesSize) {
    int *b, *s, *buff, i, j, p;
    
    if (pricesSize < 2) return 0;
    
    if (k >= pricesSize / 2) return all_profits(prices, pricesSize);
    
    buff = malloc((2 * k + 1) * sizeof(int));
    //assert(buff);
    b = &buff[0];
    s = &buff[k];
    
    for (i = 0; i < k; i ++) {
        b[i] = 0x80000000;  // min integer
        s[i] = 0;
    }
    s[k] = 0;
    
    for (i = 0; i < pricesSize; i ++) {
        for (j = 0; j < k; j ++) {
            // profit on buy is current buy or last sale minus today's price
            b[j]     = _max(b[j],     s[j] - prices[i]);
            // profit on sale is current sale or last buy plus today's price
            s[j + 1] = _max(s[j + 1], b[j] + prices[i]);
        }
    }
    
    p = s[k];
    
    free(buff);
    
    return p;
}


/*
Difficulty:Hard


*/
