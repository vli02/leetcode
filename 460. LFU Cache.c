/*
460. LFU Cache

Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.



get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.


Follow up:
Could you do both operations in O(1) time complexity?

Example:
LFUCache cache = new LFUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

typedef struct item_s {
    int key;
    int val;
    int ref;
    // add mutex if it is used in multithreaded program
    struct item_s *shadow;
    struct item_s *prev;
    struct item_s *next;
} item_t;
​
typedef struct {
    int sz;
    item_t **data;
    item_t *head;
    item_t *buff;
} LFUCache;
​
LFUCache* lFUCacheCreate(int capacity) {
    LFUCache *p;
    item_t *buff;
    int i;
    
    if (capacity <= 0) return NULL;
    
    p = malloc(sizeof(item_t));
    //assert(p);
    p->data = calloc(capacity, sizeof(item_t *));
    //assert(p->data);
    buff = calloc(capacity, sizeof(item_t));
    //assert(buff);
    p->head = p->buff = &buff[0];
    
    if (capacity > 1) {
        buff[0].next = &buff[1];
        for (i = 1; i < capacity - 1; i ++) {
            buff[i].prev = &buff[i - 1];
            buff[i].next = &buff[i + 1];
        }
        buff[capacity - 1].prev = &buff[capacity - 2];
    }
​
    p->sz = capacity;
    
    return p;
}
​
void move2next(item_t *t, LFUCache *obj) {
    item_t *a, *b;
    
    a = t;
    b = t->next;
    while (b && b->ref <= t->ref) {
        a = b;
        b = b->next;
    }
    if (a != t) {
        t->next->prev = t->prev;
        if (t->prev) t->prev->next = t->next;
        else obj->head = t->next;
        a->next = t;
        t->prev = a;
        t->next = b;
        if (b) b->prev = t;
    }
}
item_t *lookup(LFUCache* obj, int key) {
    item_t *t;
    
    t = obj->data[key % obj->sz];
    while (t && t->key != key) {
        t = t->shadow;
    }
    
    return t;
}
int lFUCacheGet(LFUCache* obj, int key) {
    item_t *t, *n, *np;
    
    t = obj ? lookup(obj, key) : NULL;
    if (!t) {
        return -1;
    }
    
    t->ref ++;
    
    move2next(t, obj);
    
    return t->val;
}
void lFUCachePut(LFUCache* obj, int key, int value) {
    item_t *t, **pp;
    
    if (!obj) return;
    
    t = lookup(obj, key);
    
    if (!t) {
        t = obj->head; // least frequently used
        
        // take it out of the cache
        pp = &obj->data[t->key % obj->sz];
        while (*pp && *pp != t) {
            pp = &(*pp)->shadow;
        }
        if (*pp) {
            *pp = (*pp)->shadow;
        }
        
        // put it back with new key
        t->key = key;
        t->ref = 1;
        t->shadow = obj->data[key % obj->sz];
        obj->data[key % obj->sz] = t;
    } else {
        t->ref ++;
    }
    
    t->val = value;
    
    move2next(t, obj);
}
​
void lFUCacheFree(LFUCache* obj) {
    if (!obj) return;
    free(obj->buff);
    free(obj->data);
    free(obj);
}
​
/**
 * Your LFUCache struct will be instantiated and called as such:
 * struct LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 * lFUCachePut(obj, key, value);
 * lFUCacheFree(obj);
 */


/*
Difficulty:Hard
Total Accepted:12.7K
Total Submissions:53.6K


Companies Amazon Google
Related Topics Design
Similar Questions 
                
                  
                    LRU Cache
                  
                    Design In-Memory File System
*/
