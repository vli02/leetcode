/*
93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.


For example:
Given "25525511135",


return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void gen_ip(const char *s, char *buff, int *seglen) {
    int i, j, k;
    for (i = 0; i < 4; i ++) {
        strncpy(buff, s, seglen[i]);
        s += seglen[i];
        buff += seglen[i];
        *buff = '.';
        buff ++;
    }
    buff --;
    *buff = 0;
}
int validate(const char *s, int len) {
    int k = 0;
    
    if (len > 1 && *s == '0') return 0;
    
    while (len -- > 0) {
        k = k * 10 + *s - '0';
        s ++;
    }
    return k > 255 ? 0 : 1;
}
void bt(const char *s, char ***p, int *psz, int *pn, int total, int usedlen, int *seglen, int d) {
    int i, k;
    char buff[16];
    if (d == 4) {
        if (usedlen != total) return;
        gen_ip(s, buff, seglen);
        if (*psz == *pn) {
            *psz *= 2;
            *p = realloc(*p, *psz * sizeof(char *));
            //assert(*p);
        }
        (*p)[*pn] = malloc((total + 4) * sizeof(char));
        //assert((*p)[*pn]);
        strcpy((*p)[*pn], buff);
        (*pn) ++;
        return;
    }
    for (i = 1; i <= 3; i ++) {
        if (validate(&s[usedlen], i)) {
            seglen[d] = i;
            bt(s, p, psz, pn, total, usedlen + i, seglen, d + 1);
        }
    }
}
char** restoreIpAddresses(char* s, int* returnSize) {
    char **p;
    int psz, pn;
    
    int seglen[4] = { 0 };
    
    pn = 0;
    psz = 10;
    p = malloc(psz * sizeof(char *));
    //assert(p);
    
    bt(s, &p, &psz, &pn, strlen(s), 0, seglen, 0);
    
    *returnSize = pn;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:87.7K
Total Submissions:321.1K


Related Topics Backtracking String

*/
