/*
261. Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.



For example:


Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.


Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.



Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

bool validTree(int n, int** edges, int edgesRowSize, int edgesColSize) {
    int *p, i, a, b, root = 0;
    
    p = calloc(n, sizeof(int));
    //assert(p);
    
    for (i = 0; i < edgesRowSize; i ++) {
        a = edges[i][0];
        b = edges[i][1];
        while (p[a]) a = p[a] - 1;  // go all way up to the top parent
        while (p[b]) b = p[b] - 1;
        if (a == b) goto done;  // if they have same parent, this forms a loop
        p[a] = b + 1;  // set the parent
    }
    
    free(p);
    return edgesRowSize == n - 1 ? true : false;  // n nodes require n - 1 edges to form a tree
done:
    free(p);
    return false;
}


/*
Difficulty:Medium
Total Accepted:38.6K
Total Submissions:102.4K


Companies Google Facebook Zenefits
Related Topics Depth-first Search Breadth-first Search Graph Union Find
Similar Questions 
                
                  
                    Course Schedule
                  
                    Number of Connected Components in an Undirected Graph
*/
