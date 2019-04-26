/*
362. Design Hit Counter

Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 



Follow up:
What if the number of hits per second could be very large? Does your design scale?


Credits:Special thanks to @elmirap for adding this problem and creating all test cases.
*/

typedef struct {
    int ts[300];
    int hit[300];
    int first;
    int last;
    int counters;
} HitCounter;

/** Initialize your data structure here. */
HitCounter* hitCounterCreate() {
    HitCounter *obj;
    obj = calloc(1, sizeof(HitCounter));
    //assert(obj);
    //obj->first = -1;
    return obj;
}

void update(HitCounter *obj, int timestamp, int cnt) {
    int i;
    /*if (obj->first == -1) {
        if (cnt == 0) return;
        obj->first = obj->last = 0;
        obj->ts[obj->first] = timestamp;
        obj->hit[obj->first] = cnt;
        obj->counters += cnt;
    } else*/ if (obj->ts[obj->last] == timestamp) {
        obj->hit[obj->last] += cnt;
        obj->counters += cnt;
    } else {
        // number of buckets we kept so far
        i = (obj->last - obj->first + 1 + 300) % 300;
        // clean those buckets which are elder than 5 minutes
        while (timestamp - obj->ts[obj->first] >= 300 && i > 0) {
            obj->counters -= obj->hit[obj->first];
            obj->first = (obj->first + 1) % 300;
            i --;
        }
        // save the hit to the bucket in the tail
        obj->last = (obj->last + 1) % 300;
        obj->ts[obj->last] = timestamp;
        obj->hit[obj->last] = cnt;
        obj->counters += cnt;
    }
}
/** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
void hitCounterHit(HitCounter* obj, int timestamp) {
    update(obj, timestamp, 1);
}

/** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
int hitCounterGetHits(HitCounter* obj, int timestamp) {
    update(obj, timestamp, 0);
    return obj->counters;
}

void hitCounterFree(HitCounter* obj) {
    free(obj);
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * struct HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 * int param_2 = hitCounterGetHits(obj, timestamp);
 * hitCounterFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:16.5K
Total Submissions:30.6K


Companies Dropbox Google
Related Topics Design
Similar Questions 
                
                  
                    Logger Rate Limiter
*/
