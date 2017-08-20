/*
38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221



1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.



Given an integer n, generate the nth term of the count-and-say sequence.



Note: Each term of the sequence of integers will be represented as a string.


Example 1:
Input: 1
Output: "1"



Example 2:
Input: 4
Output: "1211"
*/

char* countAndSay(int n) {
    char *s, *d, *x;
    int i, c;
    
    if (!n) return NULL;
    
#define BUF_SIZE 100 * 1024
    
    s = malloc(BUF_SIZE);
    x = d = malloc(BUF_SIZE);
    s[0] = '1';
    s[1] = 0;
    
    while (n > 1) {
        c = 1;
        for (i = 0; s[i]; i ++) {
            if (s[i] != s[i+1]) {
                sprintf(x, "%d%c", c, s[i]);
                x += strlen(x);
                c = 1;
            } else {
                c ++;
            }
        }
        x = s;
        s = d;
        d = x;
        n --;
    }
    
    free(d);
    return s;
}


/*
Difficulty:Easy
Total Accepted:145.1K
Total Submissions:418.7K


Companies Facebook
Related Topics String
Similar Questions 
                
                  
                    Encode and Decode Strings
*/
