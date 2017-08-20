/*
247. Strobogrammatic Number II

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n. 
For example,
Given n = 2, return ["11","69","88","96"].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//const char strobo[] = { '1', '8', '6', '9' };
​
void dfs(char *tmp, char **buffp, int *sz, int *k, int n, int d) {
    char *buff;
​
    if (d == n) {  // done
        if (*k == *sz) {
            (*sz) *= 2;
            *buffp = realloc(*buffp, (*sz) * (n + 1) * sizeof(char));
            //assert(*buffp);
        }
        buff = (*buffp) + (*k) * (n + 1);
        strcpy(buff, tmp);
        (*k) ++;
        return;
    }
    
    if (n - d >= 2) {  // 2 or more spaces are left
        if (d) {  // not the first digit
            tmp[d/2] = tmp[n - 1 - d/2] = '0';
            dfs(tmp, buffp, sz, k, n, d + 2);
        }
        
        tmp[d/2] = tmp[n - d/2 - 1] = '1';
        dfs(tmp, buffp, sz, k, n, d + 2);
        
        tmp[d/2] = tmp[n - d/2 - 1] = '8';
        dfs(tmp, buffp, sz, k, n, d + 2);
​
        tmp[d/2] = '6';
        tmp[n - d/2 - 1] = '9';
        dfs(tmp, buffp, sz, k, n, d + 2);
​
        tmp[d/2] = '9';
        tmp[n - d/2 - 1] = '6';
        dfs(tmp, buffp, sz, k, n, d + 2);
    } else {  // only 1 space left
        tmp[d/2] = '0';
        dfs(tmp, buffp, sz, k, n, d + 1);
​
        tmp[d/2] = '1';
        dfs(tmp, buffp, sz, k, n, d + 1);
​
        tmp[d/2] = '8';
        dfs(tmp, buffp, sz, k, n, d + 1);
    }
}
char** findStrobogrammatic(int n, int* returnSize) {
    int sz;
    char *tmp, *buff, **p;
    int i, k;
    
    *returnSize = 0;
    if (n <= 0) return NULL;
    
    sz = 100;
    buff = malloc(sz * (n + 1) * sizeof(char));
    tmp  = calloc((n + 1), sizeof(char));
    //assert(buff && tmp);
    
    k = 0;
    dfs(tmp, &buff, &sz, &k, n, 0);
    
    free(tmp);
    
    p = malloc(k * sizeof(char *));
    //assert(p);
    
    for (i = 0; i < k; i ++) {
        p[i] = &buff[i * (n + 1)];
    }
    
    *returnSize = k;
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:22K
Total Submissions:55.2K


Companies Google
Related Topics Math Recursion
Similar Questions 
                
                  
                    Strobogrammatic Number
                  
                    Strobogrammatic Number III
*/
