/*
323. Number of Connected Components in an Undirected Graph

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.



    Example 1:

     0          3
     |          |
     1 --- 2    4


    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.


    Example 2:

     0           4
     |           |
     1 --- 2 --- 3


    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.



Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

void dfs(int *visited, int a, int **edges, int sz) {
    int i, b;
    
    visited[a] = 1;
    
    for (i = 0; i < sz; i ++) {
        b = -1;
        if (edges[i][0] == a) {
            b = edges[i][1];
        } else
        if (edges[i][1] == a) {
            b = edges[i][0];
        }
        if (b >= 0 && !visited[b]) {
            dfs(visited, b, edges, sz);
        }
    }
}
int countComponents(int n, int** edges, int edgesRowSize, int edgesColSize) {
    int *visited;
    int i, k;
    
    visited = calloc(n, sizeof(int));
    //assert(visited);
    
    k = 0;
    for (i = 0; i < n; i ++) {
        if (visited[i] == 0) {
            k ++;
            dfs(visited, i, edges, edgesRowSize);
        }
    }
    
    free(visited);
    
    return k;
}


/*
Difficulty:Medium
Total Accepted:27K
Total Submissions:56.4K


Companies Google Twitter
Related Topics Depth-first Search Breadth-first Search Union Find Graph
Similar Questions 
                
                  
                    Number of Islands
                  
                    Graph Valid Tree
                  
                    Friend Circles
*/
