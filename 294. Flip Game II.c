/*
294. Flip Game II

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.



Write a function to determine if the starting player can guarantee a win.



For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".


Follow up:
Derive your algorithm's runtime complexity.
*/

bool canWin(char* s) {
    bool hewins;
    char *p = s;
    while (*p && *(p + 1)) {
        if (*p == '+' && *(p + 1) == '+') {
            *p = *(p + 1) = '-';
            hewins = canWin(s);
            *p = *(p + 1) = '+';
            if (!hewins) return true;
        }
        p ++;
    }
    return false;
}


/*
Difficulty:Medium
Total Accepted:26.1K
Total Submissions:56.5K


Companies Google
Related Topics Backtracking
Similar Questions 
                
                  
                    Nim Game
                  
                    Flip Game
                  
                    Guess Number Higher or Lower II
                  
                    Can I Win
*/
