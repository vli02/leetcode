/*
273. Integer to English Words

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.


For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

const char *tms[] = { "Billion", "Million",  "Thousand", "", "Hundred" };
const char *nx[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
const char *n1x[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
const char *n2x[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
​
#define APPEND(STR) do { \
    strcat(p, STR); \
    l = strlen(p); \
    *(p + l) = ' '; \
    p += l + 1; \
    total += l + 1; \
    f = 1; \
} while (0)
​
char* numberToWords(int num) {
    char *buff, *p;
    int sz, l, total;
    int m, k, t, d = 1000000000;
    int f, onex;
    
    sz = 1000;
    buff = calloc(sz, sizeof(char));
    //assert(buff);
    p = buff;
    
    p[0] = 0;
    total = 0;
    
    k = num / d;
    if (k) {
        APPEND(nx[k - 1]);
        APPEND(tms[0]);
    }
    
    num = num % d;
    d = d / 1000;
    
    t = 1;
    while (num) {
        m = num / d;
        num = num % d;
        d = d / 1000;
        
        f = onex = 0;
        
        k = m / 100;
        m = m % 100;
        if (k) {
            APPEND(nx[k - 1]);
            APPEND(tms[4]);
        }
        
        k = m / 10;
        m = m % 10;
        if (k == 1) {
            onex = 1;
        } else if (k) {
            APPEND(n2x[k - 2]);
        }
        
        k = m;
        if (onex) {
            APPEND(n1x[k]);
        } else if (k) {
            APPEND(nx[k - 1]);
        }
        
        if (f && d) {
            APPEND(tms[t]);
        }
        t ++;
    }
    
    if (total == 0) {
        strcpy(buff, "Zero");
    } else {
        buff[total - 1] = 0;
    }
    
    //printf("%s\n", buff);
    
    return buff;
}


/*
Difficulty:Hard
Total Accepted:40K
Total Submissions:181.3K


Companies Microsoft Facebook
Related Topics Math String
Similar Questions 
                
                  
                    Integer to Roman
*/
