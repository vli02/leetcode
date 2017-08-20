/*
295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
Examples: 
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5 


Design a data structure that supports the following two operations:


void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.



For example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2


Credits:Special thanks to @Louis1992 for adding this problem and creating all test cases.
*/

#define PRINT(MF, D) do { } while (0)
#define DUMP(MF) do { } while (0)
​
typedef struct {
    int *p;
    int sz;
    int n;
} MedianFinder;
​
/** initialize your data structure here. */
MedianFinder* medianFinderCreate() {
    MedianFinder *mf;
    int *buff;
    int sz;
    
    sz = 100;
    buff = malloc(sz * sizeof(int));
    mf = calloc(1, sizeof(*mf));
    //assert(buff && mf);
    mf->p = buff;
    mf->sz = sz;
​
    return mf;
}
​
int find_x(int *p, int start, int end, int num) {
    int x = 0;
    while (start <= end) {
        x = (end + start) / 2;
        if (p[x] > num) {
            end = x - 1;
        } else if (p[x] < num) {
            start = x + 1;
        } else {
            break;
        }
    }
    return x;
}
void medianFinderAddNum(MedianFinder* mf, int num) {
    int i, x;
    
    if (!mf) return;
    
    if (mf->n == mf->sz) {
        // enlarge the buffer
        mf->sz *= 2;
        mf->p = realloc(mf->p, mf->sz * sizeof(int));
        //assert(mf->p);
    }
    if (mf->n == 0) {
        mf->p[mf->n ++] = num;
DUMP(mf);
        return;
    }
    
    x = find_x(mf->p, 0, mf->n - 1, num);
    if (mf->p[x] <= num) x ++;
    for (i = mf->n - 1; i >= x; i --) {
        mf->p[i + 1] = mf->p[i];
    }
    mf->p[x] = num;
    mf->n ++;
DUMP(mf);
}
​
double medianFinderFindMedian(MedianFinder* mf) {
    double d;
    
    if (mf->n % 2) {
        d = mf->p[mf->n / 2];
    } else {
        d  = mf->p[mf->n / 2];
        d += mf->p[mf->n / 2 - 1];
        d /= 2;
    }
PRINT(mf, d);
    return d;
}
​
void medianFinderFree(MedianFinder* mf) {
    free(mf->p);
    free(mf);
}


/*
Difficulty:Hard
Total Accepted:44.3K
Total Submissions:166.6K


Companies Google
Related Topics Heap Design
Similar Questions 
                
                  
                    Sliding Window Median
*/
