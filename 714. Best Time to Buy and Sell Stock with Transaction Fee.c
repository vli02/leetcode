/*
714. Best Time to Buy and Sell Stock with Transaction Fee

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.
You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.  You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] = 4Selling at prices[5] = 9The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.



Note:
0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/

int _max(a, b) {
    if (a > b) return a;
    return b;
}
int maxProfit(int* prices, int pricesSize, int fee) {

    int i, p;
    
    /* both of following solutions work, the difference is:
       if loop starts from day 0, buy has to be compute before sale;
       if loop starts from day 1, sell has to be compute before buy;
       it is because starting from day 0, buy has to happen before buy;
       starting from day 1 means a buy happened already, so sell first.
    */
#if 1
    buy  = 0x80000000;
    sell = 0;
    
    for (i = 0; i < pricesSize; i ++) {
        p = prices[i];
        buy  = _max(buy,  sell - p);
        sell = _max(sell, buy  + p - fee);
    }
#else
    buy  = - prices[0];
    sell = 0;
    
    for (i = 1; i < pricesSize; i ++) {
        p = prices[i];
        sell = _max(sell, buy  + p - fee);
        buy  = _max(buy,  sell - p);
    }
#endif
    
    return sell;
}


/*
Difficulty:Medium


*/
