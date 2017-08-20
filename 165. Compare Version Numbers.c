/*
165. Compare Version Numbers

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37

Credits:Special thanks to @ts for adding this problem and creating all test cases.
*/

int compareVersion(char* version1, char* version2) {
    int a, b;
    char *v1, *v2;
    while (version1 || version2) {
        if (version1) {
            v1 = version1;
            version1 = strchr(version1, '.');
            if (version1) {
                *version1 = 0;
                version1 ++;
            }
            a = atoi(v1);
        } else {
            a = 0;
        }
        if (version2) {
            v2 = version2;
            version2 = strchr(version2, '.');
            if (version2) {
                *version2 = 0;
                version2 ++;
            }
            b = atoi(v2);
        } else {
            b = 0;
        }
        if (a > b) return 1;
        if (a < b) return -1;
    }
    
    return 0;
}


/*
Difficulty:Medium
Total Accepted:86.5K
Total Submissions:431.1K


Companies Microsoft Apple
Related Topics String

*/
