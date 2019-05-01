/*
438. Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".



Example 2:
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

typedef struct {
    int *p;
    int n;
    int sz;
} res_t;
void add2res(res_t *res, int i) {
    if (res->n == res->sz) {
        if (res->sz == 0) res->sz = 10;
        else res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(int));
        //assert(res->p);
    }
    res->p[res->n ++] = i;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    res_t res = { 0 };
    int cnt[26] = { 0 }, n = 0;
    int head, tail, i, j;
    char c;
    
    while (c = *(p ++)) {
        cnt[c - 'a'] ++;
        n ++;           // total number
    }
    
    head = tail = 0;
    
    while (c = s[tail ++]) {
        i = c - 'a';
        cnt[i] --;
        if (cnt[i] >= 0) {
            n --;
            if (n == 0) {   // found one
                add2res(&res, head);
                c = s[head ++]; // push one out from head
                j = c - 'a';
                cnt[j] ++;
                n ++;
            }
        } else {
            while (cnt[i] < 0) {
                c = s[head ++];
                j = c - 'a';
                cnt[j] ++;
                if (cnt[j] > 0) n ++;
            }
        }
    }
    *returnSize = res.n;
    return res.p;
}


/*
Difficulty:Easy


*/
