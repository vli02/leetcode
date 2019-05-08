/*
947. Most Stones Removed with Same Row or Column

On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 


Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5



Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3



Example 3:

Input: stones = [[0,0]]
Output: 0


 

Note:


	1 <= stones.length <= 1000
	0 <= stones[i][j] < 10000
*/

// The description of this question is very unclear.
// The best way is to use bfs to visit all connected stones.
void dfs(int **stones, int sz, int p, int *visited, int *n) {
    int r, c, i;
    
    if (visited[p]) return;
    
    visited[p] = 1;

    (*n) ++;
    
    r = stones[p][0];
    c = stones[p][1];
    
    // remove stones on same row
    for (i = 0; i < sz; i ++) {
        if (stones[i][0] == r) dfs(stones, sz, i, visited, n);
    }
    
    // remove stones on same col
    for (i = 0; i < sz; i ++) {
        if (stones[i][1] == c) dfs(stones, sz, i, visited, n);
    }
    
    //visited[p] = 0;
}
​
int removeStones(int** stones, int stonesSize, int* stonesColSize){
    int n, ans = 0;
    int *visited;
    int i;
    
    visited = calloc(stonesSize, sizeof(int));
    //assert(visited);
    
    for (i = 0; i < stonesSize; i ++) {
        n = 0;
        dfs(stones, stonesSize, i, visited, &n);
        if (n) ans += n - 1;
        //printf("%d\n", n);
    }
    
    free(visited);
    
    return ans;
}
​
​
    


/*
Difficulty:Medium


*/
