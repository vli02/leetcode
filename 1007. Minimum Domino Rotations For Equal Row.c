/*
1007. Minimum Domino Rotations For Equal Row

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the i-th domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:



Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.


Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.


 

Note:


	1 <= A[i], B[i] <= 6
	2 <= A.length == B.length <= 20000
*/


int minDominoRotations(int* A, int ASize, int* B, int BSize){
    bool a_ok, b_ok;
    int i, a_up, a_down, b_down, b_up;
    
    a_ok = b_ok = true;
    a_up = a_down = b_down = b_up = 0;
    
    for (i = 0; i < ASize; i ++) {
        if (a_ok && A[i] != A[0] && B[i] != A[0]) a_ok = false;
        if (b_ok && B[i] != B[0] && A[i] != B[0]) b_ok = false;
        
        if (!a_ok && !b_ok) return -1;
        
        if (a_ok) {
            if (A[i] != A[0]) a_up ++;          // flip up to make all are A[0] on top
            else if (B[i] != A[0]) a_down ++;   // flip down to make all are A[0] in bottom
        }
        if (b_ok) {
            if (B[i] != B[0]) b_down ++;
            else if (A[i] != B[0]) b_up ++;
        }
    }
    
    if (a_ok) return a_up < a_down ? a_up : a_down;
    
    if (b_ok) return b_up < b_down ? b_up : b_down;
    
    return -1;
}


/*
Difficulty:Medium


*/
