/*
402. Remove K Digits

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.


Note:

The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.




Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.



Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.



Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

char* removeKdigits(char* num, int k) {
    int i, j, l;
    l = strlen(num);
    while (k > 0 && *num) {
        while (*num == '0') {  // remove leading zeros
            num ++;
            l --;
        }
        i = 0;
        while (i < l - 1 && num[i] <= num[i + 1]) {
            i ++;
        }
        // take out the i-th one
        for (j = i; j < l - 1; j ++) {
            num[j] = num[j + 1];
        }
        num[j] = 0;
        l --;
        k --;
    }
    while (*num == '0') {  // remove leading zeros
        num ++;
    }
    if (!*num) num = "0";
    return num;
}


/*
Difficulty:Medium
Total Accepted:21.4K
Total Submissions:81.8K


Companies Google Snapchat
Related Topics Stack Greedy
Similar Questions 
                
                  
                    Create Maximum Number
*/
