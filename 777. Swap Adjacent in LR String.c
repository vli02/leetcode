/*
777. Swap Adjacent in LR String

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX


Note:


	1 <= len(start) = len(end) <= 10000.
	Both start and end will only consist of characters in {'L', 'R', 'X'}.
*/

// L can move ahead of X, R can move after X.
// skip X from start and end:
// if both are L, and this L in start does not appear earlier than the L in end, this is ok since L can move ahead;
// if both are R, and this R in start does not appear later than the R in end, this is ok since R can move afterwards.
bool canTransform(char * start, char * end){
    int i, j;
    
    i = j = 0;
    while (start[i] && end[i]) {
        while (start[i] == 'X') i ++;
        while (end[j] == 'X') j ++;
        
        if (start[i] == 0 && end[j] == 0) return true;
        if (start[i] == 0 || end[j] == 0) return false;
        
        if (start[i] != end[j] ||
           (start[i] == 'L' && i < j) ||
           (start[i] == 'R' && i > j)) return false;

        i ++; j ++;
    }
    
    return true;
}
​
​


/*
Difficulty:Medium


*/
