/*
202. Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number


12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


Credits:Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
*/

bool has_cycle(int *set, int x, int k) {
    int i;
    for (i = 0; i < x; i ++) {
        if (set[i] == k) return true;
    }
    return false;
}
bool isHappy(int n) {
    int i, k;
    int *set, sz, x;
    
    //assert(n > 0);
    sz  = 100;
    x   = 0;
    set = malloc(sz * sizeof(int));
    //assert(set);
    
    do {
        if (x == sz) {
            sz *= 2;
            set = realloc(set, sz * sizeof(int));
            //assert(set);
        }
        set[x ++] = n;
        k = 0;
        while (n) {
            i = n % 10;
            n = n / 10;
            k += i * i;
        }
        n = k;
    } while (k != 1 && !has_cycle(set, x, k));
    
    free(set);
    
    return k == 1 ? true : false;
}


/*
Difficulty:Easy
Total Accepted:129.1K
Total Submissions:317.8K


Companies Uber Airbnb Twitter
Related Topics Hash Table Math
Similar Questions 
                
                  
                    Add Digits
                  
                    Ugly Number
*/
