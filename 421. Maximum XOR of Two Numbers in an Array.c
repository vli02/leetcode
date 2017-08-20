/*
421. Maximum XOR of Two Numbers in an Array

Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:
Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

int qBitPartition(int* a, int l, int r, int bc) {
    if (a == NULL || l > r || bc >= 32 || bc < 0) return -1; 
    int i = l;
    int j = r;
    while (i < j) {
        while (i < j && !(a[i] & (1 << bc))) i ++;
        while (i < j &&  (a[j] & (1 << bc))) j --;
        if (i < j) {
            // swap them
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
            i ++;
            j --;
        }
    }
    // in case all elements fall into the first part
    if (!(a[i] & (1 << bc))) i ++;
​
    return i;  // start of the second partition
}
// one number is selected from l1~r1
// the other numbser is selected from l2~r2
int findPartitionMaxXor(int* a, int l1, int r1, int l2, int r2, int bc) {
    // one of these two partitions has no data, the max must be in the other two partitions
    if (l1 > r1 || l2 > r2) return 0;
    // the only difference is the last bit, pick any number from either parition and xor them
    if (bc < 0) return a[l1] ^ a[l2];
    // converge here!!!
    if (l1 == r1 && l2 == r2) return a[l1] ^ a[l2];
    // find next available partition, jump over all zero bits
    do {
        int p1 = qBitPartition(a, l1, r1, bc);
        int p2 = qBitPartition(a, l2, r2, bc);
        if ((p1-1 >= l1 && r2 >= p2) ||
            (r1 >= p1 && p2-1 >= l2)) {
            // as long as at least a new partition is formed, let's recursive.
            int max1 = findPartitionMaxXor(a, l1, p1-1, p2, r2, bc - 1);
            int max2 = findPartitionMaxXor(a, p1, r1, l2, p2-1, bc - 1);
            return max1 > max2 ? max1 : max2;
        }
        bc --; // no new partition is formed on this bit, let's continue on other bits.
    } while(bc >= 0);
    
    return 0;
}
int findMaximumXOR(int* nums, int numsSize) {
    int bc = 31; 
    int p;
    // we must find a no empty partition first
    while (bc >= 0) {
        p = qBitPartition(nums, 0, numsSize-1, bc);
        if (p > 0 && p < numsSize) {
            return findPartitionMaxXor(nums, 0, p-1, p, numsSize-1, bc - 1);
        }
        bc--;
    }
    return 0;  // all bits are same, a ^ a is 0.
}


/*
Difficulty:Medium
Total Accepted:14.6K
Total Submissions:32K


Companies Google
Related Topics Bit Manipulation Trie

*/
