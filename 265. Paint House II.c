/*
265. Paint House II

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.


The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.


Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

void dfs(int *m, int cost, int r, int p, int **costs, int rowsz, int colsz) {
    int k;
    
    if (*m && *m < cost) return;
    
    if (r == rowsz) {
        if (*m == 0 || *m > cost) *m = cost;
    } else {
        for (k = 0; k < colsz; k ++) {
            if (k != p) {
                dfs(m, cost + costs[r][k], r + 1, k, costs, rowsz, colsz);
            }
        }
    }
}
int minCostII(int** costs, int costsRowSize, int costsColSize) {
    int m = 0;
    
    dfs(&m, 0, 0, -1, costs, costsRowSize, costsColSize);
    
    return m;
}
​
// use dp solution, refer to Paint House I


/*
Difficulty:Hard
Total Accepted:22.3K
Total Submissions:58.6K


Companies Facebook
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Product of Array Except Self
                  
                    Sliding Window Maximum
                  
                    Paint House
                  
                    Paint Fence
*/
