/*
447. Number of Boomerangs

Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

#define DUMP(P, I, J, K) do { } while (0)
​
int dis(int **p, int a, int b) {
    int x = abs(p[a][0] - p[b][0]);
    int y = abs(p[a][1] - p[b][1]);
    int z = x * x + y * y;
    return z;
}
int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
    int n = 0;
    int i, j, k;
    double d1, d2;
    for (i = 0; i < pointsRowSize; i ++) {
        for (j = 0; j < pointsRowSize; j ++) {
            if (j == i) continue;
            d1 = dis(points, i, j);
            for (k = j + 1; k < pointsRowSize; k ++) {
                d2 = dis(points, i, k);
                if (d1 == d2) {
                    DUMP(points, i, j, k);
                    n ++;
                }
            }
        }
    }
    return n * 2;
}


/*
Difficulty:Easy
Total Accepted:25K
Total Submissions:55.6K


Companies Google
Related Topics Hash Table
Similar Questions 
                
                  
                    Line Reflection
*/
