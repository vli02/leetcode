/*
486. Predict the Winner

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins. 

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score. 

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. Hence, player 1 will never be the winner and you need to return False.



Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.



Note:

1 <= length of the array <= 20. 
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
*/

#define MAX_LEN 20
#define IDX(S, E) ((S) * (MAX_LEN) + (E))

typedef struct {
    bool flag;
    int val;
} m_t;

int _max(int a, int b) {
    if (a > b) return a;
    return b;
}

int helper(int *nums, int s, int e, m_t *mem) {
    int a, b, c;
    m_t *m;
    
    if (s == e) {
        c = nums[s];
    } else {
        a = nums[s];    // pick the first one
        m = &mem[IDX(s + 1, e)];    // the rest
        if (m->flag) {
            a -= m->val;
        } else {
            a -= helper(nums, s + 1, e, mem);
        }
        
        b = nums[e];    // pick the last one
        m = &mem[IDX(s, e - 1)];    // the rest
        if (m->flag) {
            b -= m->val;
        } else {
            b -= helper(nums, s, e - 1, mem);
        }
        c = _max(a, b);
    }
    
    // save it
    m = &mem[IDX(s, e)];
    m->flag = 1;
    m->val = c;
    
    return c;
}

bool PredictTheWinner(int* nums, int numsSize){
    m_t mem[MAX_LEN * MAX_LEN] = { 0 };
    if (helper(nums, 0, numsSize - 1, mem) >= 0) return true;
    return false;
}


/*
Difficulty:Medium


*/
