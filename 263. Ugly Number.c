/*
263. Ugly Number

Write a program to check whether a given number is an ugly number.



Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.



Note that 1 is typically treated as an ugly number.


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

bool isUgly(int num) {
    int pf[] = { 2, 3, 5 };
    int i = sizeof(pf) / sizeof(pf[0]);
    while (num && -- i >= 0) {
        while (!(num % pf[i])) {
            num = num / pf[i];
            //printf("%d, ", num);
        }
    }
    return num == 1 ? true : false;
}


/*
Difficulty:Easy
Total Accepted:104.7K
Total Submissions:267K


Related Topics Math
Similar Questions Happy Number Count Primes Ugly Number II

*/
