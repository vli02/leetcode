/*
461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.


Example:
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ?   ?

The above arrows point to positions where the corresponding bits are different.
*/

int hammingDistance(int x, int y) {
    int k = x ^ y;
    int n = 0;
    while (k) {
        n ++;
        k = k & (k - 1);  // reduce one bit
    }
    return n;
}


/*
Difficulty:Easy
Total Accepted:85.8K
Total Submissions:122.5K


Companies Facebook
Related Topics Bit Manipulation
Similar Questions 
                
                  
                    Number of 1 Bits
                  
                    Total Hamming Distance
*/
