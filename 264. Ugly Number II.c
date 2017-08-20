/*
264. Ugly Number II

Write a program to find the n-th ugly number.



Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.



Note that 1 is typically treated as an ugly number, and n does not exceed 1690.


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

int nthUglyNumber(int n) {
    int i, u2, u3, u5, k2, k3, k5, k;
    int *p, sz;
    
    p  = malloc(n * sizeof(int));
    //assert(p);
    
    p[0] = 1;
    u2 = u3 = u5 = 0;
    
    for (i = 1; i < n; i ++) {  // more like dp solution, 3ms
        k2 = p[u2] * 2;
        k3 = p[u3] * 3;
        k5 = p[u5] * 5;
        k = k2 < k3 ? k2 : k3;
        k = k  < k5 ? k  : k5;
        if (k == k2) u2 ++;
        if (k == k3) u3 ++;
        if (k == k5) u5 ++;
        p[i] = k;
    }
    
    k = p[n - 1];
    free(p);
    
    return k;
}


/*
Difficulty:Medium
Total Accepted:61K
Total Submissions:187.2K


Related Topics Dynamic Programming Heap Math
Similar Questions Merge k Sorted Lists Count Primes Ugly Number Perfect Squares Super Ugly Number

*/
