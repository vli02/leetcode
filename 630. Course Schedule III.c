/*
630. Course Schedule III

There are n different online courses numbered from 1 to n. Each course has some duration(course length)  t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.



Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.



Example:
Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation: 
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.




Note:

The integer 1 <= d, t, n <= 10,000. 
You can't take two courses simultaneously.
*/

typedef struct {
    int *p;
    int n;
} heap_t;
int cmp(const void *a, const void *b) {
    int x = *(int *)a, y = *(int *)b;
    return x < y ? -1 :
           x > y ?  1 : 0;
}
int cmp2(const void *a, const void *b) {
    int x = (*(int **)a)[1], *y = (*(int **)b)[1];
    return x < y ? -1 :
           x > y ?  1 : 0;
}
void heap_push(heap_t *heap, int k) {
    heap->p[heap->n ++] = k;
    qsort(heap->p, heap->n, sizeof(int), cmp);  // optimize here to avoid TLE!!!
}
int heap_pop(heap_t *heap) {
    int k = heap->p[-- heap->n];
    return k;
}
int scheduleCourse(int** courses, int coursesRowSize, int coursesColSize) {
    heap_t heap = { 0 };
    int i, days, end, t;
    
    qsort(courses, coursesRowSize, sizeof(int *), cmp2);
    
    heap.p = malloc(coursesRowSize * sizeof(int));
    //assert(heap.p);
    
    t = 0;
    for (i = 0; i < coursesRowSize; i ++) {
        days = courses[i][0];
        end  = courses[i][1];
        heap_push(&heap, days);
        t += days;
        if (t > end) {
            t -= heap_pop(&heap);
        }
    }
    
    free(heap.p);
    
    return heap.n;
}


/*
Difficulty:Hard
Total Accepted:3.5K
Total Submissions:12.7K


Companies WAP
Related Topics Greedy
Similar Questions 
                
                  
                    Course Schedule
                  
                    Course Schedule II
*/
