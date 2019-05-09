/*
920. Number of Music Playlists

Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:


	Every song is played at least once
	A song can only be played again only if K other songs have been played


Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

 




Example 1:

Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].



Example 2:

Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]



Example 3:

Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]




 

Note:


	0 <= K < N <= L <= 100
*/

int numMusicPlaylists(int N, int L, int K){
    long *dp;
    int i, j, x;
    
    // dp[i][j]: number of possible answers on listening to i with j songs
    // then we want to get dp[N][L]
    dp = calloc((L + 1) * (N + 1), sizeof(*dp));
    //assert(dp);
#define IDX(I, J) ((I) * (N + 1) + (J))
    
    dp[IDX(0, 0)] = 1;

    for (i = 1; i <= L; i ++) {
        for (j = 1; j <= N; j ++) {
            x = N - j + 1;      // number of songs not being selected
            dp[IDX(i, j)] += dp[IDX(i - 1, j - 1)] * x; // choose a new song
            
            x = j - K;          // number of played songs can be re-selected
            if (x > 0) {
                dp[IDX(i, j)] += dp[IDX(i - 1, j)] * x; // choose a played songs
            }
            dp[IDX(i, j)] %= 1000000007;
        }
    }
    
    i = dp[IDX(L, N)];
    
    free(dp);
    
    return i;
}
​
​


/*
Difficulty:Hard


*/
