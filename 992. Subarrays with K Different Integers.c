/*
992. Subarrays with K Different Integers

Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].


Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


 

Note:


	1 <= A.length <= 20000
	1 <= A[i] <= A.length
	1 <= K <= A.length
*/

int subarraysWithKDistinct(int* A, int ASize, int K) {
    int cnt[20001] = { 0 };
    int a, l = 0, r = 0, n = 1, t = 0;

    while (r < ASize) {
        a = A[r ++];
        if (cnt[a] == 0) {  // reduce K when a new number is pushed in from right
            K --;
        }
        cnt[a] ++;
        
        if (K < 0) {        // number on far left is uniq, pop it out and reset all
            a = A[l ++];
            cnt[a] = 0;
            K = 0;
            n = 1;
        }
        
        if (K == 0) {               // a valid result is found
            while (cnt[A[l]] > 1) { // pop out all dup numbers from far left
                a = A[l ++];
                cnt[a] --;
                n ++;               // all possible combinations after one pop
            }
            t += n;                 // all possible combinations so far
        }
    }
    
    return t;
}


/*
Difficulty:Hard


*/
