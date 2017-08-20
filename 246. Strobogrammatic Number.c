/*
246. Strobogrammatic Number

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

bool isStrobogrammatic(char* num) {
    int m[10] = { 0, 1, -1, -1, -1, -1, 9, -1, 8, 6 };
    int i, j, a, b;
    int l = strlen(num);
​
    for (i = 0, j = l - 1; i <= j; i ++, j --) {
        a = num[i] - '0';
        b = num[j] - '0';
        //printf("%d ... %d\n", a, b);
        if (m[a] != b) {
            return false;
        }
    }
​
    return true;
}


/*
Difficulty:Easy
Total Accepted:27.3K
Total Submissions:68.6K


Companies Google
Related Topics Hash Table Math
Similar Questions 
                
                  
                    Strobogrammatic Number II
                  
                    Strobogrammatic Number III
*/
