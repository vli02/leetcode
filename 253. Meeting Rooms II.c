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
typedef struct {
    int start;
    int end;
    int rooms;
} slice_t;
​
void split_add(slice_t **pp, int *sz, int *n, int *k, struct Interval *m) {
    int i;
    slice_t *s, *s1, *s2;
    struct Interval a, b;
    
    if (*n + 2 >= *sz) {
        //enlarge buffer
        *sz *= 100;
        *pp = realloc(*pp, (*sz) * sizeof(slice_t));
        //assert(*pp);
    }
    for (i = 0; i < *n; i ++) {
        s = &(*pp)[i];
        if (s->start >= m->end || s->end <= m->start) { // no overlap
            continue;
        }
        if (m->start >= s->start && m->end <= s->end) { // meeting is nested
            if (m->start == s->start && m->end == s->end) { // perfect overlap, no split
                s->rooms ++;
            } else 
            if (m->start == s->start) {
                s1 = &(*pp)[(*n) ++];
                s1->start = m->end;
                s1->end = s->end;
                s1->rooms = s->rooms;
                s->end = m->end;
                s->rooms ++;
            } else
            if (m->end == s->end) {
                s1 = &(*pp)[(*n) ++];
                s1->start = s->start;
                s1->end = m->start;
                s1->rooms = s->rooms;
                s->start = m->start;
                s->rooms ++;
            } else {
                s1 = &(*pp)[(*n) ++];
                s2 = &(*pp)[(*n) ++];
                s1->start = s->start;
                s1->end = m->start;
                s1->rooms = s->rooms;
                s2->start = m->end;
                s2->end = s->end;
                s2->rooms = s->rooms;
                s->start = m->start;
                s->end = m->end;
                s->rooms ++;
            }
        } else
        if (m->start < s->start) {  // meeting starts early
            a.start = m->start;
            a.end = s->start;
            b.start = s->start;
            b.end = m->end;
            split_add(pp, sz, n, k, &a);
            split_add(pp, sz, n, k, &b);
        } else
        if (m->end > s->end) {  // meeting ends late
            a.start = m->start;
            a.end = s->end;
            b.start = s->end;
            b.end = m->end;
            split_add(pp, sz, n, k, &a);
            split_add(pp, sz, n, k, &b);
        }
        if (*k < s->rooms) {
            *k = s->rooms;
        }
        return;
    }
    if (i == *n) {
        s = &(*pp)[(*n) ++];
        s->start = m->start;
        s->end = m->end;
        s->rooms = 1;
        if (*k < s->rooms) {
            *k = s->rooms;
        }
    }
}
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int minMeetingRooms(struct Interval* intervals, int intervalsSize) {
    int m = 0;
#if 0
    int sz = 100;
    slice_t *slices;
    int n = 0;
    int i;
    
    slices = malloc(sz * sizeof(slice_t));
    //assert(slices);
    
    for (i = 0; i < intervalsSize; i ++) {
        split_add(&slices, &sz, &n, &m, &intervals[i]);
    }
    
    free(slices);
#else
    int *buff, *start, *end;
    int s, e;
    
    buff = malloc(intervalsSize * 2 * sizeof(int));
    //assert(buff);
    start = &buff[0];
    end   = &buff[intervalsSize];
    
    for (s = 0; s < intervalsSize; s ++) {
        start[s] = intervals[s].start;
        end[s]   = intervals[s].end;
    }
    
    qsort(start, intervalsSize, sizeof(int), cmp);
    qsort(end,   intervalsSize, sizeof(int), cmp);
    
#if 0
    for (s = 0, e = 0; s < intervalsSize; s ++) {
        printf("%d - %d\n", start[s], end[e]);
        if (start[s] < end[e]) {
            m ++; // start[s] - end[e] is the first period requires most rooms
        } else {
            e ++;
        }
    }
#else
    for (s = intervalsSize - 1, e = intervalsSize - 1; e >= 0; e --) {
        printf("%d - %d\n", start[s], end[e]);
        if (start[s] < end[e]) {
            m ++;  // start[s] - end[e] is the last period requires most rooms
        } else {
            s --;
        }
    }
#endif
    
    free(buff);
#endif
​
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
