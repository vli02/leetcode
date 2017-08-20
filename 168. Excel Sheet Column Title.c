/*
168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
*/

char* convertToTitle(int n) {
    char *s;
    int sz, l, k;
    int i, j;
    
    sz = 100;
    s = malloc(sz * sizeof(char));
    //assert(s);
    l = 0;
    while (n) {
        if (sz == l) {
            sz *= 2;
            s = realloc(s, sz * sizeof(char));
            //assert(s);
        }
        k = (n - 1) % 26;
        s[l ++] = 'A' + k;
        n = (n - 1) / 26;
    }
    s[l] = 0;
    for (i = 0, j = l - 1; i < j; i ++, j --) {
        k = s[i];
        s[i] = s[j];
        s[j] = k;
    }
    return s;
}


/*
Difficulty:Easy
Total Accepted:107.7K
Total Submissions:414.9K


Companies Microsoft Facebook Zenefits
Related Topics Math
Similar Questions 
                
                  
                    Excel Sheet Column Number
*/
