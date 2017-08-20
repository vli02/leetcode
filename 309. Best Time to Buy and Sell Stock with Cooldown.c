/*
309. Best Time to Buy and Sell Stock with Cooldown

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:


    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)


Example:
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

int _max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize) {
    int i;
    int buy_today, sell_today, cool_today;  // max profit of every possible status on a day
    int buy_yesterday, sell_yesterday, cool_yesterday;
    
    buy_today = 0 - prices[0];
    sell_today = cool_today = 0;
    
    for (i = 1; i < pricesSize; i ++) {
        buy_yesterday = buy_today;
        sell_yesterday = sell_today;
        cool_yesterday = cool_today;
        
        buy_today  = _max(buy_yesterday,  cool_yesterday - prices[i]);
        sell_today = _max(sell_yesterday, buy_yesterday + prices[i]);
        cool_today = _max(cool_yesterday, sell_yesterday);
    }
    
    return sell_today;
}


/*
Difficulty:Medium
Total Accepted:43.9K
Total Submissions:107.9K


Companies Google
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Best Time to Buy and Sell Stock
                  
                    Best Time to Buy and Sell Stock II
*/
