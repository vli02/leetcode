/*
560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2



Note:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

typedef struct e_s {
    int s;
    int c;
    struct e_s *next;
} e_t;

#define HF 1021
#define HC(S)   (((S) % HF) + HF)

typedef struct {
    e_t *e[HF * 2];
    e_t buff[20000];
    int n;
} ht_t;

e_t *lookup(ht_t *ht, int s) {
    e_t *e = ht->e[HC(s)];
    while (e && e->s != s) e = e->next;
    return e;
}
void insert(ht_t *ht, int s) {
    e_t *e = lookup(ht, s);
    if (e) e->c ++;
    else {
        e = &ht->buff[ht->n ++];
        e->s = s;
        e->c = 1;
        e->next = ht->e[HC(s)];
        ht->e[HC(s)] = e;
    }
}
int count(ht_t *ht, int s) {
    e_t *e = lookup(ht, s);
    if (e) return e->c;
    return 0;
}
int subarraySum(int* nums, int numsSize, int k){
    int i, s, r, n;
    ht_t ht = { 0 };
    
    n = 0;
    s = 0;
    
    insert(&ht, s);
    
    for (i = 0; i < numsSize; i ++) {
        s += nums[i];
        
        n += count(&ht, s - k);
        
        insert(&ht, s);
    }
    
    return n;
}


/*
Difficulty:Medium


*/
