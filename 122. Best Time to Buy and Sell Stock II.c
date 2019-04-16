/*
122. Best Time to Buy and Sell Stock II

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int maxProfit(int* prices, int pricesSize) {
    int i, d, p;
    
    if (pricesSize < 2) return 0;
    
    p = 0;
    for (i = 1; i < pricesSize; i ++) {
        d = prices[i] - prices[i - 1];
        p = d > 0 ? p + d : p;  // get it as long as it is a profit!
    }

    return p;
}


/*
Difficulty:Easy
Total Accepted:152.2K
Total Submissions:323.9K


Companies Bloomberg
Related Topics Array Greedy
Similar Questions 
                
                  
                    Best Time to Buy and Sell Stock
                  
                    Best Time to Buy and Sell Stock III
                  
                    Best Time to Buy and Sell Stock IV
                  
                    Best Time to Buy and Sell Stock with Cooldown
*/
