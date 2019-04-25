/*
751. IP to CIDR

Given a start IP address ip and a number of ips we need to cover n, return a representation of the range as a list (of smallest possible length) of CIDR blocks.

A CIDR block is a string consisting of an IP, followed by a slash, and then the prefix length.  For example: "123.45.67.89/20".  That prefix length "20" represents the number of common prefix bits in the specified range.


Example 1:
Input: ip = "255.0.0.7", n = 10
Output: ["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
Explanation:
The initial ip address, when converted to binary, looks like this (spaces added for clarity):
255.0.0.7 -> 11111111 00000000 00000000 00000111
The address "255.0.0.7/32" specifies all addresses with a common prefix of 32 bits to the given address,
ie. just this one address.

The address "255.0.0.8/29" specifies all addresses with a common prefix of 29 bits to the given address:
255.0.0.8 -> 11111111 00000000 00000000 00001000
Addresses with common prefix of 29 bits are:
11111111 00000000 00000000 00001000
11111111 00000000 00000000 00001001
11111111 00000000 00000000 00001010
11111111 00000000 00000000 00001011
11111111 00000000 00000000 00001100
11111111 00000000 00000000 00001101
11111111 00000000 00000000 00001110
11111111 00000000 00000000 00001111

The address "255.0.0.16/32" specifies all addresses with a common prefix of 32 bits to the given address,
ie. just 11111111 00000000 00000000 00010000.

In total, the answer specifies the range of 10 ips starting with the address 255.0.0.7 .

There were other representations, such as:
["255.0.0.7/32","255.0.0.8/30", "255.0.0.12/30", "255.0.0.16/32"],
but our answer was the shortest possible.

Also note that a representation beginning with say, "255.0.0.7/30" would be incorrect,
because it includes addresses like 255.0.0.4 = 11111111 00000000 00000000 00000100 
that are outside the specified range.



Note:

ip will be a valid IPv4 address.
Every implied address ip + x (for x < n) will be a valid IPv4 address.
n will be an integer in the range [1, 1000].
*/


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **p;
    int n;
    int sz;
} res_t;
void add2res(res_t *res, char *ip, int mask) {
    int n;
    char tmp[5];
    
    n = sprintf(tmp, "/%d", mask);
    tmp[n] = 0;
    
    strcat(ip, tmp);
    
    if (res->n == res->sz) {
        if (res->sz == 0) res->sz = 10;
        else res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = ip;
}
int _max(int a, int b) {
    if (a > b) return a;
    return b;
}
int bit_length(uint32_t u) {
    int l = 0;
    while (u > 0) {
        l ++;
        u >>= 1;
    }
    return l;
}
uint32_t ip2uint(char *ip) {
    uint32_t u = 0;
    char *p = ip;
    int i;

    for (i = 0; i < 4; i ++) {
        u = (u << 8) + strtol(p, &p, 10);
        p ++;
    }
    
    return u;
}
char *uint2ip(uint32_t u) {
    int n;
    char *ip = malloc(22);
    //assert(ip);
    
    n = 0;
    n += sprintf(&ip[n], "%d.", u >> 24);
    n += sprintf(&ip[n], "%d.", (u << 8) >> 24);
    n += sprintf(&ip[n], "%d.", (u << 16) >> 24);
    n += sprintf(&ip[n], "%d.", (u << 24) >> 24);
    ip[n - 1] = 0;
    
    return ip;
}
char** ipToCIDR(char* ip, int n, int* returnSize) {
    res_t res = { 0 };
    uint32_t start, mask;
    
    start = ip2uint(ip);
    
    while (n > 0) {
        mask = _max(33 - bit_length(start & -start),    // this might be more than we want
                    33 - bit_length(n));
        add2res(&res, uint2ip(start), mask);
        start += 1 << (32 - mask);
        n -= 1 << (32 - mask);
    }
    
    *returnSize = res.n;
    
    return res.p;
}


/*
Difficulty:Easy


*/
