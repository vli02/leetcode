/*
444. Sequence Reconstruction

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:
Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.



Example 2:
Input:
org: [1,2,3], seqs: [[1,2]]

Output:
false

Explanation:
The reconstructed sequence can only be [1,2].



Example 3:
Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:
true

Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].



Example 4:
Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:
true




UPDATE (2017/1/8):
The seqs parameter had been changed to a list of list of strings (instead of a 2d array of strings). Please reload the code definition to get the latest changes.
*/

bool sequenceReconstruction(int* org, int orgSize, int** seqs, int seqsRowSize, int *seqsColSizes) {
    int idx[10001], fixed[10001];
    int m, n, i, j, a, b, *p;
    
    for (i = 0; i < orgSize; i ++) {
        j = org[i] - 1;
        idx[j] = i;
        fixed[j] = 0;
    }
    
    m = 0;
    n = orgSize;
    
    for (i = 0; i < seqsRowSize; i ++) {
        p = seqs[i];
        for (j = 0; j < seqsColSizes[i]; j ++) {
            m ++;
            b = p[j] - 1;
            if (b < 0 || b >= orgSize ||
                (orgSize == 1 && b != org[0] - 1)) {
                return false;
            } else if (j > 0) {
                if (idx[a] >= idx[b]) {
                    return false;
                }
                if (!fixed[a] && idx[a] + 1 == idx[b]) {
                    fixed[a] = 1;
                    n --;
                }
            }
            a = b;
        }
    }
    
    return m >= 1 && n == 1;
}


/*
Difficulty:Medium
Total Accepted:6.5K
Total Submissions:32.5K


Companies Google
Related Topics Graph Topological Sort
Similar Questions 
                
                  
                    Course Schedule II
*/
