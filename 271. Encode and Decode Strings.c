/*
271. Encode and Decode Strings

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.


Machine 1 (sender) has the function:
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}

Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}



So Machine 1 does:
string encoded_string = encode(strs);



and Machine 2 does:
vector<string> strs2 = decode(encoded_string);



strs2 in Machine 2 should be the same as strs in Machine 1.


Implement the encode and decode methods.


Note:

The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

/** Encodes a list of strings to a single string */
char* encode(char** strs, int strsSize) {
    int sz, len;
    char *p, *tmp;
    
    int i, l;
    char *s;
    
    int oldsize;
    
    if (strsSize == 0) return NULL;
    
    sz = 1000;
    p = malloc(sz * sizeof(char));
    //assert(p);
    sprintf(p, "%08X", strsSize);
    len = 8;
    
    for (i = 0; i < strsSize; i ++) {
        s = strs[i];
        l = strlen(s);
        oldsize = sz;
        while (len + 8 + l + 1 >= sz) {
            sz = sz * 2;
        }
        if (oldsize != sz) {
            p = realloc(p, sz * sizeof(char));
            //assert(p);
        }
        tmp = p + len;
        sprintf(tmp, "%08X", l);
        len += 8;
        if (l) {
            tmp = p + len;
            sprintf(tmp, "%s", s);
            len += l;
        }
    }
    p[len] = 0;
    return p;
}

/**
 * Decodes a single string to a list of strings.
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int extract_int(char *s) {
    int n, i, k;
    char c;
    
    n = 0;
    for (i = 0; i < 8; i ++) {
        c = s[i];
        if (c >= '0' && c <= '9') {
            k = c - '0';
        } else {
            k = 10 + c - 'A';
        }
        n = n * 16 + k;
    }
    
    return n;
}
char** decode(char* s, int* returnSize) {
    unsigned char c;
    int n, i, j, l, k;
    char **pp, *p;
    
    *returnSize = 0;
    if (!s) return NULL;
    
    *returnSize = n = extract_int(s);
    s += 8;
    
    pp = malloc(n * sizeof(char *));
    //assert(pp);

    for (j = 0; j < n; j ++) {    
        l = extract_int(s);
        s += 8;
        p = malloc((l + 10) * sizeof(char));
        //assert(p);
        strncpy(p, s, l);
        s += l;
        p[l] = 0;
        pp[j] = p;
    }
    
    return pp;
}

// Your functions will be called as such:
// char* s = encode(strs, strsSize);
// decode(s, &returnSize);

/*
Difficulty:Medium
Total Accepted:21.9K
Total Submissions:83.6K


Companies Google
Related Topics String
Similar Questions 
                
                  
                    Count and Say
                  
                    Serialize and Deserialize Binary Tree
*/
