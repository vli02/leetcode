/*
72. Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)



You have the following 3 operations permitted on a word:



a) Insert a character
b) Delete a character
c) Replace a character
*/

int minDistance(char* word1, char* word2) {
    int rowsz, colsz, row, col, *dp, k;
    
    rowsz = strlen(word1);
    colsz = strlen(word2);
    
    dp = malloc((rowsz + 1) * (colsz + 1) * sizeof(int));
    //assert(dp);
#define IDX(ROW, COL) ((ROW + 1) * (colsz + 1) + (COL + 1))
    
    dp[0] = 0;
    for (row = 0; row < rowsz; row ++) {
        dp[IDX(row, -1)] = row + 1;
    }
    for (col = 0; col < colsz; col ++) {
        dp[IDX(-1, col)] = col + 1;
    }
    
    for (row = 0; row < rowsz; row ++) {
        for (col = 0; col < colsz; col ++) {
            k = dp[IDX(row - 1, col - 1)];
            if (word1[row] != word2[col]) {
                k = k < dp[IDX(row - 1, col)] ? k : dp[IDX(row - 1, col)];
                k = k < dp[IDX(row, col - 1)] ? k : dp[IDX(row, col - 1)];
                k += 1;
            }
            dp[IDX(row, col)] = k;
        }
    }
    
    k = dp[IDX(rowsz - 1, colsz - 1)];
    free(dp);
    
    return k;
}


/*
Difficulty:Hard
Total Accepted:92.4K
Total Submissions:291.9K


Related Topics Dynamic Programming String
Similar Questions One Edit Distance Delete Operation for Two Strings

*/
