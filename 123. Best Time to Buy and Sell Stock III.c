/*
123. Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int maxProfit(int* prices, int pricesSize) {
    int buy1, buy2;     // max profit if I buy
    int sell1, sell2;   // max profit if I sell
    int i;
    
    if (pricesSize < 2) return 0;
    
    buy1 = buy2 = 0 - prices[0];
    sell1 = sell2 = 0;
    
    for (i = 1; i < pricesSize; i ++) {
        sell1 = sell1 > buy1  + prices[i] ? sell1 : buy1  + prices[i];
        sell2 = sell2 > buy2  + prices[i] ? sell2 : buy2  + prices[i];
        buy1 = buy1  > 0     - prices[i] ? buy1  : 0     - prices[i];
        buy2 = buy2  > sell1 - prices[i] ? buy2  : sell1 - prices[i];
    }
    
    return sell2;
}


/*
Difficulty:Hard
Total Accepted:88.8K
Total Submissions:303.4K


Related Topics Array Dynamic Programming
Similar Questions Best Time to Buy and Sell Stock Best Time to Buy and Sell Stock II Best Time to Buy and Sell Stock IV

*/
