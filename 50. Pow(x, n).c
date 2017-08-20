/*
50. Pow(x, n)

Implement pow(x, n).
*/

double powx(double x, int n) {
    double k;
    if (n == 0) return 1;
    k = powx(x * x, n / 2);
    if (n % 2) k = k * x;
    return k;
}
double myPow(double x, int n) {
    if (n < 0) { x = 1 / x; n = 0 - n; }
    return powx(x, n);
}


/*
Difficulty:Medium
Total Accepted:161.2K
Total Submissions:612.2K


Companies LinkedIn Google Bloomberg Facebook
Related Topics Binary Search Math
Similar Questions 
                
                  
                    Sqrt(x)
                  
                    Super Pow
*/
