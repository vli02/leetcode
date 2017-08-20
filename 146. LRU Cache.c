/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.



get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.


Follow up:
Could you do both operations in O(1) time complexity?

Example:
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

struct kvlist {
    int key;
    int val;
    struct kvlist *prev;
    struct kvlist *next;
    struct kvlist *shadow;
};
​
typedef struct {
    int kf;
    int sz;
    int idx;
    struct kvlist **kp;
    struct kvlist *buff;
    struct kvlist *head;
    struct kvlist *tail;
} LRUCache;
​
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj;
    int i;
    
    obj = calloc(1, sizeof(LRUCache));
    //assert(obj);
    
    obj->kf = 1024 * 10;
    obj->kp = calloc(obj->kf, sizeof(struct kvlist *));
    obj->sz = capacity;
    obj->buff = calloc(obj->sz, sizeof(struct kvlist));
    obj->idx = 0;
    
    obj->head = &obj->buff[0];
    obj->tail = &obj->buff[obj->sz - 1];
    obj->head->prev = obj->tail;
    obj->tail->next = obj->head;
    if (obj->sz > 1) {
        obj->head->next = &obj->buff[1];
        obj->tail->prev = &obj->buff[obj->sz - 2];
    }
    for (i = 1; i < obj->sz - 1; i ++) {
        obj->buff[i].prev = &obj->buff[i - 1];
        obj->buff[i].next = &obj->buff[i + 1];
    }
    
    return obj;
}
​
struct kvlist *lookup(LRUCache *obj, int key) {
    struct kvlist *l;
​
    l = obj->kp[key % obj->kf];
    while (l && l->key != key) {
        l = l->shadow;
    }
    
    return l;
}
​
void move2tail(LRUCache *obj, struct kvlist *l) {
    if (l == obj->tail) return;
    if (l == obj->head) {
        obj->head = l->next;
        obj->tail = l;
        return;
    }
    // take it out of the loop
    l->prev->next = l->next;
    l->next->prev = l->prev;
    // link to the tail
    l->next = obj->head;
    l->prev = obj->tail;
    obj->head->prev = l;
    obj->tail->next = l;
    
    obj->tail = l;
}
​
int lRUCacheGet(LRUCache* obj, int key) {
    int val;
    struct kvlist *l;
    
    l = lookup(obj, key);
    
    if (!l) return -1;
    
    val = l->val;
    
    move2tail(obj, l);
    
    return val;
}
​
void lRUCachePut(LRUCache* obj, int key, int value) {
    int i;
    struct kvlist *l, **pp;
    
    l = lookup(obj, key);
    if (!l) {
        l = obj->head;
        
        // remove it from hash table
        i = l->key % obj->kf;
        pp = &obj->kp[i];
        while (*pp && *pp != l) {
            pp = &(*pp)->shadow;
        }
        *pp = l->shadow;
        
        // insert it to hash table with new key
        l->key = key;
        i = key % obj->kf;
        l->shadow = obj->kp[i];
        obj->kp[i] = l;
    }
    
    l->val = value;
    
    move2tail(obj, l);
}
​
void lRUCacheFree(LRUCache* obj) {
    free(obj->kp);
    free(obj->buff);
}
​
/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */


/*
Difficulty:Hard
Total Accepted:131.8K
Total Submissions:744.5K


Companies Google Uber Facebook Twitter Zenefits Amazon Microsoft Snapchat Yahoo Bloomberg Palantir
Related Topics Design
Similar Questions 
                
                  
                    LFU Cache
                  
                    Design In-Memory File System
                  
                    Design Compressed String Iterator
*/
