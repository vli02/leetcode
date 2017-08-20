/*
69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.
*/

int mySqrt(int x) {
#if 1
    int left, right, mid, k;
    if (!x) return 0;
    left = 1;
    right = (x < 46340 * 2) ? (x + 1) / 2 : 46340;
    while (left <= right) {
        mid = left + (right - left) / 2;
        //printf("mid: %d\n", mid);
        k = mid * mid;
        if (k == x) return mid;
        if (k < x) left = mid + 1;
        else       right = mid - 1;
    }
    return right;
#else
    unsigned long long r = (x + 1) / 2;
    if (r > 46340) r = 46340;
    while (r * r > x) {
        //printf("r: %lld\n", r);
        r = (r + x / r) / 2;
    }
​
    return r;
#endif
}


/*
Difficulty:Easy
Total Accepted:166.8K
Total Submissions:599.6K


Companies Bloomberg Apple Facebook
Related Topics Binary Search Math
Similar Questions 
                
                  
                    Pow(x, n)
                  
                    Valid Perfect Square
*/
