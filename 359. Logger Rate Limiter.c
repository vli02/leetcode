/*
359. Logger Rate Limiter

Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:
Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;



Credits:Special thanks to @memoryless for adding this problem and creating all test cases.
*/

typedef struct item_s {
    int ts;
    char *msg;
    struct item_s *shadow;
} item_t;
typedef struct {
    item_t *logs[10];
} Logger;
​
unsigned int hash(const char *msg) {
    int h = 5381;
#if 1
    char c = *msg;
    while (c) {
        h = h << 5 + h + c;
        msg ++;
        c = *msg;
    }
#else
    int i, l = strlen(msg);
    for (i = 0; i < l; i ++) {
        h = h * 1 + msg[i];
    }
#endif
    return h;
}
/** Initialize your data structure here. */
Logger* loggerCreate() {
    Logger *obj = calloc(1, sizeof(Logger));
    //assert(obj);
    return obj;
}
​
/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
bool loggerShouldPrintMessage(Logger* obj, int timestamp, char* message) {
    unsigned int c, k;
    item_t *p, **pp;
    
    c = hash(message);
    p = obj->logs[c % 10];
    while (p && strcmp(p->msg, message)) {
        p = p->shadow;
    }
    if (p) {
        if (timestamp - p->ts < 10) {
            return false;
        }
        p->ts = timestamp;
    } else {
        p = malloc(sizeof(item_t));
        //assert(p);
        p->ts = timestamp;
        p->msg = message;
        p->shadow = obj->logs[c % 10];
        obj->logs[c % 10] = p;
    }
    
    return true;
}
​
void loggerFree(Logger* obj) {
    item_t *p, *s;
    int i;
    for (i = 0; i < 10; i ++) {
        p = obj->logs[i];
        while (p) {
            s = p->shadow;
            free(p);
            p = s;
        }
    }
    free(obj);
}
​
/**
 * Your Logger struct will be instantiated and called as such:
 * struct Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 * loggerFree(obj);
 */


/*
Difficulty:Easy
Total Accepted:18.1K
Total Submissions:30.2K


Companies Google
Related Topics Hash Table Design
Similar Questions 
                
                  
                    Design Hit Counter
*/
