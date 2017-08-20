/*
293. Flip Game

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.



Write a function to compute all possible states of the string after one valid move.



For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]




If there is no valid move, return an empty list [].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generatePossibleNextMoves(char* s, int* returnSize) {
    int sz = 100;
    int n = 0;
    char **pp, *p;
    
    int l = strlen(s) + 1;
    char *str = s;
    
    pp = malloc(sz * sizeof(*pp));
    //assert(pp);
    
    while (*s && *(s + 1)) {
        if (*s == '+' && *(s + 1) == '+') {
            *s = *(s + 1) = '-';
            p = malloc(l);
            //assert(p);
            strcpy(p, str);
            if (n == sz) {
                sz *= 2;
                pp = realloc(pp, sz * sizeof(*pp));
                //assert(pp);
            }
            pp[n ++] = p;
            *s = *(s + 1) = '+';
        }
        s ++;
    }
    *returnSize = n;
    
    return pp;
}


/*
Difficulty:Easy
Total Accepted:25.3K
Total Submissions:45.4K


Companies Google
Related Topics String
Similar Questions 
                
                  
                    Flip Game II
*/
