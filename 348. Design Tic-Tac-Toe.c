/*
348. Design Tic-Tac-Toe

Design a Tic-tac-toe game that is played between two players on a n x n grid.


You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.



Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|



Follow up:
Could you do better than O(n2) per move() operation?
*/

typedef struct {
    int *buff;
    int *rn[2];
    int *cn[2];
    int *grid;
    int n;
} TicTacToe;
​
#define IDX(R, C) ((R) * obj->n + (C))
​
/** Initialize your data structure here. */
TicTacToe* ticTacToeCreate(int n) {
    TicTacToe *obj = calloc(1, sizeof(TicTacToe));
    //assert(obj);
    obj->n = n;
    obj->buff = calloc((4 + n) * n, sizeof(int));
    //assert(buff);
    obj->rn[0] = &obj->buff[0 * n];
    obj->rn[1] = &obj->buff[1 * n];
    obj->cn[0] = &obj->buff[2 * n];
    obj->cn[1] = &obj->buff[3 * n];
    obj->grid  = &obj->buff[4 * n];
    return obj;
}
​
/** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
int ticTacToeMove(TicTacToe* obj, int row, int col, int player) {
    int i;
    
    obj->rn[player - 1][row] ++;
    obj->cn[player - 1][col] ++;
    
    if (obj->rn[player - 1][row] == obj->n ||
        obj->cn[player - 1][col] == obj->n) {
        return player;
    }
    
    obj->grid[IDX(row, col)] = player;
    
    for (i = 0; i < obj->n && obj->grid[IDX(i, i)] == player; i ++) {
    }
    if (i == obj->n) return player;
    
    for (i = 0; i < obj->n && obj->grid[IDX(i, obj->n - 1 - i)] == player; i ++) {
    }
    if (i == obj->n) return player;
​
    return 0;
}
​
void ticTacToeFree(TicTacToe* obj) {
    free(obj->buff);
    free(obj);
}
​
/**
 * Your TicTacToe struct will be instantiated and called as such:
 * struct TicTacToe* obj = ticTacToeCreate(n);
 * int param_1 = ticTacToeMove(obj, row, col, player);
 * ticTacToeFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:14.5K
Total Submissions:31.6K


Companies Microsoft Google
Related Topics Design

*/
