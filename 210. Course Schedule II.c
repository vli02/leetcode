/*
210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]


Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.


For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.



click to show more hints.

Hints:

This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
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
void dfs(int *buff, int n, int sz, int *indegree, int *visited, int *courses, int *k) {
    int i, *node;
    
    visited[n] = 3;
    
    courses[(*k) ++] = n - 1;
    
    node = &buff[n * sz];
    for (i = 0; i < sz; i ++) {
        n = node[i];
        if (n && visited[n] != 3) {
            indegree[n] --;
            if (indegree[n] == 0) {
                dfs(buff, n, sz, indegree, visited, courses, k);
            }
        }
    }
}
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
    int *buff, *root, *node_a;
    int i, n, k, a, b;
    int *visited;
    int *indegree;
    int *courses;
    
    buff = calloc((numCourses + 1) * numCourses, sizeof(int)); // each node with all possible neighbors
    visited = calloc((numCourses + 1), sizeof(int));
    indegree = calloc((numCourses + 1), sizeof(int));
    courses  = calloc(numCourses, sizeof(int));
    //assert(buff && visited && indegree && courses);
    
    root = &buff[0];  // root node has neighbors of all
    for (i = 0; i < numCourses; i ++) {
        root[i] = i + 1;
    }
    
    for (i = 0; i < prerequisitesRowSize; i ++) {
        a = prerequisites[i][1];
        b = prerequisites[i][0];
        node_a = &buff[(a + 1) * numCourses];
        node_a[b] = (b + 1);    // node a has neighbor b which has id b + 1
        indegree[(b + 1)] ++;
    }
    
    k = 0;
    
    //if (has_cycle(buff, 0, numCourses, visited)) {
    //    goto done;
    //}
    
    // topological sort using dfs
    for (i = 0; i < numCourses; i ++) {
        n = root[i];
        if (indegree[n] == 0 && visited[n] != 3) {
            dfs(buff, n, numCourses, indegree, visited, courses, &k);
        }
    }
    
    if (k != numCourses) k = 0;
    
done:
    free(buff);
    free(visited);
    free(indegree);
​
    *returnSize = k;
    
    return courses;
}


/*
Difficulty:Medium
Total Accepted:65.8K
Total Submissions:235.5K


Companies Facebook Zenefits
Related Topics Depth-first Search Breadth-first Search Graph Topological Sort
Similar Questions 
                
                  
                    Course Schedule
                  
                    Alien Dictionary
                  
                    Minimum Height Trees
                  
                    Sequence Reconstruction
                  
                    Course Schedule III
*/
