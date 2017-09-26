/*
253. Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.


For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int minMeetingRooms(struct Interval* intervals, int intervalsSize) {
    int m = 0;
    int *buff, *start, *end;
    int s, e;
    
    buff = malloc(intervalsSize * 2 * sizeof(int));
    //assert(buff);
    start = &buff[0];
    end   = &buff[intervalsSize];
    
    for (s = 0; s < intervalsSize; s ++) {
        start[s] = intervals[s].start;
        end[s]   = intervals[s].end;
    }
    
    qsort(start, intervalsSize, sizeof(int), cmp);
    qsort(end,   intervalsSize, sizeof(int), cmp);
    
#if 0
    for (s = 0, e = 0; s < intervalsSize; s ++) {
        //printf("%d - %d\n", start[s], end[e]);
        if (start[s] < end[e]) {
            m ++; // start[s] - end[e] is the first period requires most rooms
        } else {
            e ++;
        }
    }
#else
    for (s = intervalsSize - 1, e = intervalsSize - 1; e >= 0; e --) {
        //printf("%d - %d\n", start[s], end[e]);
        if (start[s] < end[e]) {
            m ++;  // start[s] - end[e] is the last period requires most rooms
        } else {
            s --;
        }
    }
#endif
    
    free(buff);

    return m;
}

/*
Difficulty:Medium
Total Accepted:42.3K
Total Submissions:108.9K


Companies Google Snapchat Facebook
Related Topics Heap Greedy Sort
Similar Questions 
                
                  
                    Merge Intervals
                  
                    Meeting Rooms
                  
                    Minimum Number of Arrows to Burst Balloons
*/
