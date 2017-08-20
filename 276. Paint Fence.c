/*
276. Paint Fence

There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color. 
Return the total number of ways you can paint the fence. 

Note:
n and k are non-negative integers.
*/

int numWays(int n, int k) {
    int total;
    int i;
​
    int same = 0;
    int diff = k;
    if (!n) return 0;
    for (i = 1; i < n; i ++) {
        total = same + diff;
        same = diff;
        diff = total * (k - 1);
    }
    total = same + diff;
​
    return total;
}
​
// no more than three adjacent posts having the same color
// most straightforward approach is dfs, this is dp solution
​
/*
if (!n) return 0;
if (n == 1) return k;
s3 = 0; // all three the same
s2 = k; // the last two the same
diff = k * (k - 1);
for (i = 2; i < n; i ++) {
    total = s2 + s3 + diff;
    s3 = s2
    s2 = diff
    diff = total * (k - 1);
}
*/


/*
Difficulty:Easy
Total Accepted:24.2K
Total Submissions:70.6K


Companies Google
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    House Robber
                  
                    House Robber II
                  
                    Paint House
                  
                    Paint House II
*/
