/*
133. Clone Graph

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.




OJ's undirected graph serialization:


Nodes are labeled uniquely.


We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.




As an example, consider the serialized graph {0,1,2#1,2#2,2}.



The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.




Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * #define NEIGHBORS_MAX_SIZE 100
 * struct UndirectedGraphNode {
 *     int label;
 *     struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
 *     int neighborsCount;
 * };
 */
struct UndirectedGraphNode *copy1node(struct UndirectedGraphNode *graph, 
                                      struct UndirectedGraphNode ***srcpool, 
                                      struct UndirectedGraphNode ***dstpool, 
                                      int *sp, int *sz) {
    struct UndirectedGraphNode *node;
    int i = 0;
    
    if (!graph) return NULL;
    
    while (i < *sp && (*srcpool)[i] != graph) {
        i ++;
    }
    if (i == *sp) {
        node = malloc(sizeof(struct UndirectedGraphNode));
        //assert(node);
        node->label = graph->label;
        if (*sp == *sz) {
            *sz = *sz * 2;
            *srcpool = realloc(*srcpool, *sz * sizeof(struct UndirectedGraphNode *));
            *dstpool = realloc(*dstpool, *sz * sizeof(struct UndirectedGraphNode *));
            //assert(*srcpool && *dstpool && *stspool);
        }
        (*srcpool)[*sp] = graph;
        (*dstpool)[*sp] = node;
        (*sp) += 1;
        i = 0;
        while (i < graph->neighborsCount) {
            node->neighbors[i] = copy1node(graph->neighbors[i], srcpool, dstpool, sp, sz);
            i ++;
        }
        node->neighborsCount = graph->neighborsCount;
    } else {
        node = (*dstpool)[i];
    }
    
    return node;
}

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph) {
    struct UndirectedGraphNode **srcpool, **dstpool, *node;
    int sp = 0, sz = 100;
    
    srcpool = malloc(sz * sizeof(struct UndirectedGraphNode *));
    dstpool = malloc(sz * sizeof(struct UndirectedGraphNode *));
    //assert(srcpool && dstpool && stspool);
    
    node = copy1node(graph, &srcpool, &dstpool, &sp, &sz);
    
    free(srcpool); free(dstpool);
    
    return node;
}


/*
Difficulty:Medium
Total Accepted:116.4K
Total Submissions:463.8K


Companies Pocket Gems Google Uber Facebook
Related Topics Depth-first Search Breadth-first Search Graph
Similar Questions 
                
                  
                    Copy List with Random Pointer
*/
