/*
207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]


Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?


For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.



click to show more hints.

Hints:

This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

int has_cycle(int *buff, int n, int sz, int *visited) {
    int i, *node;
    
    if (visited[n] == -1) return 0;
    if (visited[n] == 1) return 1;
    
    visited[n] = 1;
    
    node = &buff[n * sz];
    for (i = 0; i < sz; i ++) {
        if (node[i] != 0 && has_cycle(buff, node[i], sz, visited)) {
            return true;
        }
    }
    
    visited[n] = -1;
    
    return false;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
    int ret = true;
    int *buff, *root, *node;
    int i, a, b;
    int *visited;
    
    buff = calloc((numCourses + 1) * numCourses, sizeof(int)); // each node with all possible neighbors
    visited = calloc((numCourses + 1), sizeof(int));
    //assert(buff && visited);
    
    root = &buff[0];  // root node has neighbors of all
    for (i = 0; i < numCourses; i ++) {
        root[i] = i + 1;
    }
    
    for (i = 0; i < prerequisitesRowSize; i ++) {
        a = prerequisites[i][1] + 1;
        b = prerequisites[i][0];
        node = &buff[a * numCourses];
        node[b] = b + 1;
    }
    
    if (has_cycle(buff, 0, numCourses, visited)) {
        ret = false;
    }
    
    free(buff);
    free(visited);

    return ret;
}


/*
Difficulty:Medium
Total Accepted:88.1K
Total Submissions:274.7K


Companies Apple Yelp Zenefits
Related Topics Depth-first Search Breadth-first Search Graph Topological Sort
Similar Questions 
                
                  
                    Course Schedule II
                  
                    Graph Valid Tree
                  
                    Minimum Height Trees
                  
                    Course Schedule III
*/
