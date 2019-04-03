/*
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R


And then read line by line: "PAHNAPLSIIGYIR"


Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

char* convert(char* s, int numRows) {
    int len;
    int i, j, k = 0;
    char *p;
    int step, up;
    
    if (!s || !*s || numRows == 1) return s;
    
    len = strlen(s);
    p = malloc((len + 1) * sizeof(char));
    //assert(p);
    
    step = (numRows - 1) * 2;       // max span
    
    for (i = 0; i < numRows; i ++) {
        j = i;                      // first letter of each row
        up = 1;
        while (j < len) {
            p[k ++] = s[j];
            if (i == 0 || i == numRows - 1) {
                j += step;          // full span
            } else if (up) {
                j += step - i * 2;  // full span - offset
                up = 0;
            } else {
                j += i * 2;         // offset
                up = 1;
            }
        }
    }
    p[k] = 0;
    return p;
}


/*
Difficulty:Medium
Total Accepted:163.3K
Total Submissions:610.5K


Related Topics String

*/
