/*
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.


For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
int cmp(const void *a, const void *b) {
    return (*(struct Interval *)a).start - (*(struct Interval *)b).start;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    int i, j;
​
    if (intervalsSize <= 0) return NULL;
    
    qsort(intervals, intervalsSize, sizeof(struct Interval), cmp);
    
    i = 0;
    for (j = 1; j < intervalsSize; j ++) {
        if (intervals[j].start > intervals[i].end) {
            // append
            intervals[++ i] = intervals[j];
        } else if (intervals[j].end > intervals[i].end) {
            // merge
            intervals[i].end = intervals[j].end;
        }   // ignore it
    }
    
    *returnSize = i + 1;
    
    return intervals;
}


/*
Difficulty:Medium
Total Accepted:136.7K
Total Submissions:454.4K


Companies LinkedIn Google Facebook Twitter Microsoft Bloomberg Yelp
Related Topics Array Sort
Similar Questions 
                
                  
                    Insert Interval
                  
                    Meeting Rooms
                  
                    Meeting Rooms II
                  
                    Teemo Attacking
                  
                    Add Bold Tag in String
*/
