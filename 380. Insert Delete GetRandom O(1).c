/*
380. Insert Delete GetRandom O(1)

Design a data structure that supports all following operations in average O(1) time.



insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.



Example:
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/

struct item {
    int val;
    struct item *shadow;
};
​
#define HASHSZ 100
#define HASHCODE(V) (((unsigned int)V) % HASHSZ)
​
typedef struct {
    struct item *items[HASHSZ];
    int num;
} RandomizedSet;
​
/** Initialize your data structure here. */
RandomizedSet* randomizedSetCreate() {
    RandomizedSet *obj = calloc(1, sizeof(RandomizedSet));
    return obj;
}
​
/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    struct item *e = obj->items[HASHCODE(val)];
    while (e && e->val != val) {
        e = e->shadow;
    }
    if (e) {
        return false;
    }
    
    e = malloc(sizeof(struct item));
    //assert(e);
    e->val = val;
    e->shadow = obj->items[HASHCODE(val)];
    obj->items[HASHCODE(val)] = e;
    obj->num ++;
​
    return true;
}
​
/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val) {
    struct item **pp = &obj->items[HASHCODE(val)];
    struct item *e = *pp;
    while (e && e->val != val) {
        pp = &e->shadow;
        e = *pp;
    }
    if (!e) {
        return false;
    }
    
    obj->num --;
    *pp = e->shadow;
    free(e);
    
    return true;
}
​
/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    int num = 0;
    int i = 0, j;
    struct item *e = NULL;
    
    if (obj->num == 0) return -1;
    
    j = random() % obj->num;
    while (!e && i < HASHSZ && j >= 0) {
        e = obj->items[i];
        while (e && j > 0) {
            e = e->shadow;
            j --;
        }
        i ++;
    }
    return e->val;
}
​
void randomizedSetFree(RandomizedSet* obj) {
    struct item *e, *n;
    int i;
    for (i = 0; i < HASHSZ; i ++) {
        e = obj->items[i];
        while (e) {
            n = e->shadow;
            free(e);
            e = n;
        }
    }
    free(obj);
}
​
/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * struct RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 * bool param_2 = randomizedSetRemove(obj, val);
 * int param_3 = randomizedSetGetRandom(obj);
 * randomizedSetFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:36.2K
Total Submissions:92.7K


Companies Google Uber Twitter Amazon Yelp Pocket Gems Facebook
Related Topics Array Hash Table Design
Similar Questions 
                
                  
                    Insert Delete GetRandom O(1) - Duplicates allowed
*/
