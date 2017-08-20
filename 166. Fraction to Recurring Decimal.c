/*
166. Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".



Credits:Special thanks to @Shangrila for adding this problem and creating all test cases.
*/

char* fractionToDecimal(int numerator, int denominator) {
    char *p;
    int psz, n, *dec, dsz, x;
    long long num, den, k, f;
    int i, repeat_at;
    int neg = 0;
    
    psz = dsz = 100; n = x = 0;
    p = malloc(psz * sizeof(char));
    //assert(p);
    
    neg = ((numerator > 0 && denominator < 0) ||
           (numerator < 0 && denominator > 0)) ? 1 : 0;
    num = numerator;
    den = denominator;
    num = (num < 0) ? -num : num;
    den = (den < 0) ? -den : den;
    
    k = num / den;
    f = num % den;
    
    if (neg && (k || f)) p[n ++] = '-';
    
    n += sprintf(&p[n], "%lld", k);
    if (!f) {
        p[n] = 0;
        return p;
    }
    
    p[n ++] = '.';
    
    dec = malloc(dsz * sizeof(int));
    //assert(dec);
    
    repeat_at = -1;
    if (f < 0) f = -f;
    while (f) {
        for (i = 0; i < x; i += 2) {
            if (dec[i] == f) {
                repeat_at = i;
                goto done;
            }
        }
        if (x + 1 >= dsz) {
            dsz *= 2;
            dec = realloc(dec, dsz * sizeof(int));
            //assert(dec);
        }
        dec[x ++] = f;
        f *= 10;
        k = f / den;
        dec[x ++] = k;
        f = f % den;
    }
    
done:
    for (i = 0; i < x; i += 2) {
        if (n + 3 > psz) {
            psz *= 2;
            p = realloc(p, psz * sizeof(char));
            //assert(p);
        }
        if (repeat_at == i) {
            p[n ++] = '(';
        }
        p[n ++] = '0' + dec[i + 1];
    }
    if (repeat_at != -1) p[n ++] = ')';
    p[n ++] = 0;
    
    free(dec);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:53.4K
Total Submissions:305.5K


Companies Google
Related Topics Hash Table Math

*/
