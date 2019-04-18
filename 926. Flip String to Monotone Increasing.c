/*
926. Flip String to Monotone Increasing

A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.

 


Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.



Example 2:

Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.



Example 3:

Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.


 

Note:


	1 <= S.length <= 20000
	S only consists of '0' and '1' characters.
*/

int minFlipsMonoIncr(char* S) {
    /*
    1   0   0   1   1   1   1   1   1   1   1   0   0   1   1       n = 15
    0   1   1   1   2   3   4   5   6   7   8   9   9   9   10  11  <- num of 1 ahead
4   4   3   2   2   2   2   2   2   2   2   2   1   0   0   0       <- num of 0 after
    4   5   4   3   4   5   ...
    */
    int i, n, ones[20001], zeros[20001];
    int flip2zero, flip2one, flip, min;
    
    n = 0;
    ones[0] = 0;
    while (S[n]) {
        ones[n + 1] = ones[n] + (S[n] == '1' ? 1 : 0);

    }
    
    i = n;
    zeros[i --] = 0;
    while (i >= 0) {
        zeros[i] = zeros[i + 1] + (S[i] == '0' ? 1 : 0);
        i --;
    }
    
    min = n;
    for (i = 0; i <= n; i ++) {
        flip = ones[i] + zeros[i];  // at i, ones ahead need to flip to zero
                                    //  and zeros after need to flip to one 
        if (min > flip) min = flip;
    }
    
    return min;
}


/*
Difficulty:Medium


*/
