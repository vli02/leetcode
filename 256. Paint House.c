/*
256. Paint House

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.


The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.


Note:
All costs are positive integers.
*/

void dfs(int *m, int cost, int r, int p, int **costs, int rowsz) {
    int k;
    
    if (*m && *m < cost) return;
    
    if (r == rowsz) {
        if (*m == 0 || *m > cost) *m = cost;
    } else {
        for (k = 0; k < 3; k ++) {
            if (k != p) {
                dfs(m, cost + costs[r][k], r + 1, k, costs, rowsz);
            }
        }
    }
}
#define RED(I) costs[I][0]
#define BLUE(I) costs[I][1]
#define GREEN(I) costs[I][2]
int minCost(int** costs, int costsRowSize, int costsColSize) {
    int m = 0;
#if 0
    dfs(&m, 0, 0, -1, costs, costsRowSize);
#else
    int red, blue, green;
    int x, y, r, b, g;
    int i;
    
    red = blue = green = 0;
    
    for (i = 0; i < costsRowSize; i ++) {
        // red
        x = blue + RED(i);
        y = green + RED(i);
        r = x < y ? x : y;
        
        // blue
        x = red + BLUE(i);
        y = green + BLUE(i);
        b = x < y ? x : y;
        
        // green
        x = red + GREEN(i);
        y = blue + GREEN(i);
        g = x < y ? x : y;
        
        red = r;
        blue = b;
        green = g;
    }
    m = red < blue ? red : blue;
    m = m < green ? m : green;
#endif
​
    return m;
}


/*
Difficulty:Easy
Total Accepted:24.4K
Total Submissions:53K


Companies LinkedIn
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    House Robber
                  
                    House Robber II
                  
                    Paint House II
                  
                    Paint Fence
*/
