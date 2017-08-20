/*
401. Binary Watch

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:
Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]


Note:

The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_HOUR 12  // this should be 13 so it includes 12:xx pm.
#define MAX_MIN  60
​
char** readBinaryWatch(int num, int* returnSize) {
    char **pp, *p;
    int sz = MAX_HOUR * MAX_MIN;
​
    int hh[13]; // number of digits in hours
    int mm[60]; // number of digits in minutes
    int i, j, k, x;
    
    i = 0;
    while (i < MAX_HOUR) {
        hh[i] = 0;
        k = i;
        while (k != 0) {
            while (!(k & 0x1)) k = k >> 1;
            k = k >> 1;
            hh[i] ++;
        }
        i ++;
    }
    i = 0;
    while (i < MAX_MIN) {
        mm[i] = 0;
        k = i;
        while (k != 0) {
            while (!(k & 0x1)) k = k >> 1;
            k = k >> 1;
            mm[i] ++;
        }
        i ++;
    }
    
    *returnSize = 0;
    
    pp = malloc(sz * sizeof(char *));
    p = malloc(sz * 6 * sizeof(char));
    if (!pp || !p) return NULL;
    
    k = 0;
    i = 0;
    while (i < MAX_HOUR) {
        j = 0;
        while (j < MAX_MIN) {
            if (hh[i] + mm[j] == num) {
                pp[k ++] = p;
                sprintf(p, "%d:%02d", i, j);
                p += 6;
            }
            j ++;
        }
        i ++;
    }
    *returnSize = k;
    
    return pp;
}


/*
Difficulty:Easy
Total Accepted:34K
Total Submissions:75.9K


Companies Google
Related Topics Backtracking Bit Manipulation
Similar Questions 
                
                  
                    Letter Combinations of a Phone Number
                  
                    Number of 1 Bits
*/
