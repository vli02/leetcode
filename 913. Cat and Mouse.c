/*
913. Cat and Mouse

A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in 3 ways:


	If ever the Cat occupies the same node as the Mouse, the Cat wins.
	If ever the Mouse reaches the Hole, the Mouse wins.
	If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.


Given a graph, and assuming both players play optimally, return 1 if the game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a draw.

 





Example 1:

Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
Explanation:
4---3---1
|   |
2---5
 \ /
  0


 

Note:


	3 <= graph.length <= 50
	It is guaranteed that graph[1] is non-empty.
	It is guaranteed that graph[2] contains a non-zero element.
*/

typedef struct {
    int m;      // mouse position
    int c;      // cat position
    int t;      // who is going to move in next turn
    int s;      // current win-lose state
} node_t;
#define MOUSE_POSITION(NODE)    ((NODE)->m)
#define CAT_POSITION(NODE)      ((NODE)->c)

#define MOUSE_MOVE  1
#define CAT_MOVE    2

#define IS_MOUSE_MOVE(NODE) ((NODE)->t == MOUSE_MOVE)
#define IS_CAT_MOVE(NODE)   ((NODE)->t == CAT_MOVE)

#define UNKNOWN_    0
#define MOUSE_WIN   1
#define CAT_WIN     2

#define SET_MOUSE_WIN(NODE) ((NODE)->s = MOUSE_WIN)
#define SET_CAT_WIN(NODE)   ((NODE)->s = CAT_WIN)

#define IS_MOUSE_WIN(NODE)  ((NODE)->s == MOUSE_WIN)
#define IS_CAT_WIN(NODE)    ((NODE)->s == CAT_WIN)

#define MSZ     50
#define CSZ     50
#define TSZ     3
#define SIZE    (MSZ * CSZ *TSZ)

#define IDX(M, C, T)    ((M) * (CSZ) * (TSZ) + (C) * (TSZ) + T)

node_t *get_node(node_t *nodes, int m, int c, int t) {
    node_t *node = &nodes[IDX(m, c, t)];
    
    node->m = m;
    node->c = c;
    node->t = t;
    
    return node;
}
bool mouse_win_on_all_children(node_t *node, node_t *nodes, int **graph, int *colsz) {
    int i, j, k;
    node_t *child;
    
    i = CAT_POSITION(node);
    for (j = 0; j < colsz[i]; j ++) {
        k = graph[i][j];
        if (k == 0) continue;   // cat cannot go to position 0
        child = get_node(nodes, MOUSE_POSITION(node), k, MOUSE_MOVE);
        if (!IS_MOUSE_WIN(child)) return false;  // not determined or cat wins
    }
    return true;    // mouse wins on all children
}
bool cat_win_on_all_children(node_t *node, node_t *nodes, int **graph, int *colsz) {
    int i, j, k;
    node_t *child;
    
    i = MOUSE_POSITION(node);
    for (j = 0; j < colsz[i]; j ++) {
        k = graph[i][j];
        child = get_node(nodes, k, CAT_POSITION(node), CAT_MOVE);
        if (!IS_CAT_WIN(child)) return false;
    }
    return true;
}
int catMouseGame(int** graph, int graphSize, int* graphColSize){
    int i, j, k;
    node_t nodes[SIZE] = { 0 }; // total number of nodes per (mouse position * cat position * who is going to move)
    node_t *buff1[SIZE], *buff2[SIZE];     // queue of knowns states
    node_t **q1 = buff1, **q2 = buff2, **q3;
    int q1len = 0, q2len = 0;
    
    node_t *node, *parent;
    
    // initial known states
    for (i = 1; i < graphSize; i ++) {
        // mouse is at 0, regardless where cat is and who is going to move, mouse wins
        node = get_node(nodes, 0, i, MOUSE_MOVE);
        SET_MOUSE_WIN(node);
        q1[q1len ++] = node;        // enqeue this node
        
        node = get_node(nodes, 0, i, CAT_MOVE);
        SET_MOUSE_WIN(node);
        q1[q1len ++] = node;
        
        // mouse and cat have met, regardless who is going to move, cat wins
        node = get_node(nodes, i, i, MOUSE_MOVE);
        SET_CAT_WIN(node);
        q1[q1len ++] = node;
        
        node = get_node(nodes, i, i, CAT_MOVE);
        SET_CAT_WIN(node);
        q1[q1len ++] = node;
    }
    
    while (q1len) {
        for (i = 0; i < q1len; i ++) {
            node = q1[i];
            // for each parent node which can move to current node
            if (IS_MOUSE_MOVE(node)) {      // current node is mouse going to move
                j = CAT_POSITION(node);     // parent must be cat was moving
                for (k = 0; k < graphColSize[j]; k ++) {
                    if (graph[j][k] == 0) continue; // cat cannot be at position 0
                    parent = get_node(nodes, MOUSE_POSITION(node), graph[j][k], CAT_MOVE);
                    if (IS_MOUSE_WIN(parent) || IS_CAT_WIN(parent)) continue;    // already determined
                    if (IS_CAT_WIN(node)) {     // if cat wins at present, parent must win because:
                        SET_CAT_WIN(parent);    // parent is cat to move so the cat can just move to here
                    } else if (mouse_win_on_all_children(parent, nodes, graph, graphColSize)) {
                        SET_MOUSE_WIN(parent);
                    } else {
                        parent = NULL;      // unable to determine it, forget about it at this moment.
                    }
                    if (parent) q2[q2len ++] = parent;  // enqueue it for next round expansion
                }
            } else {                        // current node is cat going to move
                j = MOUSE_POSITION(node);   // parent must be mouse was moving
                for (k = 0; k < graphColSize[j]; k ++) {
                    parent = get_node(nodes, graph[j][k], CAT_POSITION(node), MOUSE_MOVE);
                    if (IS_MOUSE_WIN(parent) || IS_CAT_WIN(parent)) continue;    // already determined
                    if (IS_MOUSE_WIN(node)) {
                        SET_MOUSE_WIN(parent);
                    } else if (cat_win_on_all_children(parent, nodes, graph, graphColSize)) {
                        SET_CAT_WIN(parent);
                    } else {
                        parent = NULL;
                    }
                    if (parent) q2[q2len ++] = parent;  // enqueue it for next round expansion
                }
            }
        }
        // switch q1 and q2
        q3 = q1;
        q1 = q2;
        q1len = q2len;
        q2 = q3;
        q2len = 0;
    }
    
    node = &nodes[IDX(1, 2, MOUSE_MOVE)];
    return node->s;
}


/*
Difficulty:Hard


*/
