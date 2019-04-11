/*
391. Perfect Rectangle

Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.



Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).



Example 1:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.






Example 2:
rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.






Example 3:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.






Example 4:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
*/

typedef struct dot_s {
    int x;
    int y;
    struct dot_s *shadow;
} dot_t;
#define HSZ 1000
typedef struct set_s {
    dot_t **d;
    int n;
} set_t;
int lookup_remove(set_t *set, int x, int y) {
    dot_t **p, *d;
    
    p = &set->d[x % HSZ];
    while ((*p) && ((*p)->x != x || (*p)->y != y)) {
        p = &((*p)->shadow);
    }
    
    if (*p) {
        d = *p;
        *p = d->shadow;
        free(d);
        set->n --;
        return 1;
    }
    
    return 0;
}
void add2set(set_t *set, int x, int y) {
    dot_t *d = malloc(sizeof(dot_t));
    //assert(d);
    d->x = x;
    d->y = y;
    d->shadow = set->d[x % HSZ];
    set->d[x % HSZ] = d;
    set->n ++;
}
bool map_area(int **rectangles, int rowsz) {
    int a, i;
    int x1, y1, x2, y2;
    int x_min, y_min, x_max, y_max;
    dot_t *buff[HSZ * 2] = { 0 };
    set_t set = { 0 };
    set.d = &buff[HSZ];
    
    a = 0;
    for (i = 0; i < rowsz; i ++) {
        x1 = rectangles[i][0];
        y1 = rectangles[i][1];
        x2 = rectangles[i][2];
        y2 = rectangles[i][3];
        
        a += (x2 - x1) * (y2 - y1);   // total area
        
        if (i == 0 || x_min > x1) x_min = x1;   // find the outermost shape
        if (i == 0 || y_min > y1) y_min = y1;
        if (i == 0 || x_max < x2) x_max = x2;
        if (i == 0 || y_max < y2) y_max = y2;
        
        if (!lookup_remove(&set, x1, y1)) add2set(&set, x1, y1);
        if (!lookup_remove(&set, x1, y2)) add2set(&set, x1, y2);
        if (!lookup_remove(&set, x2, y1)) add2set(&set, x2, y1);
        if (!lookup_remove(&set, x2, y2)) add2set(&set, x2, y2);
    }
    
    return ((a == ((y_max - y_min) * (x_max - x_min))) &&
            (set.n == 4 &&
             lookup_remove(&set, x_min, y_min) &&
             lookup_remove(&set, x_min, y_max) &&
             lookup_remove(&set, x_max, y_min) &&
             lookup_remove(&set, x_max, y_max))) ? true : false;
}
bool isRectangleCover(int** rectangles, int rectanglesRowSize, int rectanglesColSize) {
    return map_area(rectangles, rectanglesRowSize);
}

/*
Difficulty:Hard
Total Accepted:10.3K
Total Submissions:39.2K


Companies Google

*/
