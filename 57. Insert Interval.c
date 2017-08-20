/*
57. Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.


Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].



Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].



This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int lower_bound(struct Interval *p, int i, int j, int k) {
    int end = j, m;
    
    while (i <= j) {
        m = i + (j - i) / 2;
        
        if (k >= p[m].start && k <= p[m].end) return m;
        
        if (k > p[m].end) i = m + 1;
        else              j = m - 1;
    }
    
    return (i > end) ? i : j;
}
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval *p;
    int i, j, k;
    
#define ISZ sizeof(struct Interval)
    
    p = malloc((intervalsSize + 1) * ISZ);
    //assert(p);
    
    i = lower_bound(intervals, 0, intervalsSize - 1, newInterval.start);
    // append to tail
    if (i == intervalsSize) {
        memcpy(&p[0], intervals, intervalsSize * ISZ);
        p[intervalsSize] = newInterval;
        *returnSize = intervalsSize + 1;
        return p;
    }
    
    j = lower_bound(intervals, 0, intervalsSize - 1, newInterval.end);
    // add to head
    if (j == -1) {
        p[0] = newInterval;
        memcpy(&p[1], intervals, intervalsSize * ISZ);
        *returnSize = intervalsSize + 1;
        return p;
    }
    
    //printf("%d, %d\n", i, j);
    
    // insert and merge
    if (i == -1) {
        intervals[0].start = newInterval.start;
        i = 0;
    }
    if (j == intervalsSize) {
        intervals[intervalsSize - 1].end = newInterval.end;
        j = intervalsSize - 1;
    }
    k = 0;
    memcpy(&p[k], intervals, (i + 1) * ISZ);
    k += i;
    
    if (newInterval.start > p[i].end) {
        p[++ k].start = newInterval.start;
    }
    if (newInterval.end > intervals[j].end) {
        p[k].end = newInterval.end;
    } else {
        p[k].end = intervals[j].end;
    }
    k ++;
    
    memcpy(&p[k], &intervals[j + 1], (intervalsSize - j - 1) * ISZ);
    k += intervalsSize - j - 1;
    
    *returnSize = k;
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:98.9K
Total Submissions:358.3K


Companies LinkedIn Google Facebook
Related Topics Array Sort
Similar Questions 
                
                  
                    Merge Intervals
*/
