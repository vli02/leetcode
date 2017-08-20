/*
490. The Maze

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.


Example 1
Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.





Example 2
Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.




Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

const int offset[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
​
bool dfs(int *v, int **maze, int rowsz, int colsz, int start_x, int start_y, int dest_x, int dest_y) {
    int i, x, y, nx, ny;
    
    if (start_x == dest_x &&
        start_y == dest_y) return true;
    
    for (i = 0; i < 4; i ++) {
        if (!(v[start_x * colsz + start_y] & (1 << i))) {
            v[start_x * colsz + start_y] |= (1 << i);
            nx = start_x; ny = start_y;
            do {
                x = nx; y = ny;
                nx += offset[i][0]; ny += offset[i][1];
            } while (nx >= 0 && nx < rowsz &&
                     ny >= 0 && ny < colsz &&
                     !maze[nx][ny]);
            if ((x != start_x || y != start_y) &&
                dfs(v, maze, rowsz, colsz, x, y, dest_x, dest_y)) return true;
        }
    }
    
    return false;
}
bool hasPath(int** maze, int mazeRowSize, int mazeColSize, int* start, int startSize, int* destination, int destinationSize) {
    int *v, k;
    v = calloc(mazeRowSize * mazeColSize, sizeof(int));
    //assert(v);
    k = dfs(v, maze, mazeRowSize, mazeColSize, start[0], start[1], destination[0], destination[1]);
    free(v);
    return k;
}


/*
Difficulty:Medium
Total Accepted:6.4K
Total Submissions:14.7K


Companies Google
Related Topics Depth-first Search Breadth-first Search
Similar Questions 
                
                  
                    The Maze III
                  
                    The Maze II
*/
