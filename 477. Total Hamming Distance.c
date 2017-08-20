/*
477. Total Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.


Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.



Note:

Elements of the given array are in the range of 0  to 10^9
Length of the array will not exceed 10^4.
*/

int totalHammingDistance(int* nums, int numsSize) {
    int i, j, k, t;
    t = 0;
    for (i = 0; i < 32; i ++) {  // for every bit
        k = 0;
        for (j = 0; j < numsSize; j ++) {
            k += (nums[j] & (1 << i)) ? 1 : 0;  // number of bit 1
        }
        t += k * (numsSize - k);  // distance on this particular bit
    }
    return t;
}


/*
Difficulty:Medium
Total Accepted:18.8K
Total Submissions:40.3K


Companies Facebook
Related Topics Bit Manipulation
Similar Questions 
                
                  
                    Hamming Distance
*/
