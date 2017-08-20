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

#define BYTESZ (sizeof(map[0]))
#define BITSZ  (BYTESZ * 8)
​
bool map_cover(int** rectangles, int rectanglesRowSize) {
    int bottom, left, top, right;
    int rowsz, colsz;
    int i, j, x, y, e, n, k, s, b, t;
    int result;
    
    unsigned int *map;
    const unsigned int all_ones[] = { 0, 0xff, 0xffff, 0, 0xffffffff };
    const unsigned int all_bits[] = {
        0xffffffff, 0xfffffffe, 0xfffffffc, 0xfffffff8,
        0xfffffff0, 0xffffffe0, 0xffffffc0, 0xffffff80,
        0xffffff00, 0xfffffe00, 0xfffffc00, 0xfffff800,
        0xfffff000, 0xffffe000, 0xffffc000, 0xffff8000,
        0xffff0000, 0xfffe0000, 0xfffc0000, 0xfff80000,
        0xfff00000, 0xffe00000, 0xffc00000, 0xff800000,
        0xff000000, 0xfe000000, 0xfc000000, 0xf8000000,
        0xf0000000, 0xe0000000, 0xc0000000, 0x80000000
    };
    
    bottom = rectangles[0][0];
    left   = rectangles[0][1];
    top    = rectangles[0][2];
    right  = rectangles[0][3];
    for (i = 1; i < rectanglesRowSize; i ++) {
        if (bottom > rectangles[i][0]) {
            bottom = rectangles[i][0];
        }
        if (left > rectangles[i][1]) {
            left = rectangles[i][1];
        }
        if (top < rectangles[i][2]) {
            top = rectangles[i][2];
        }
        if (right < rectangles[i][3]) {
            right = rectangles[i][3];
        }
    }
    
    rowsz = top - bottom;
    colsz = right - left;
    map = calloc((rowsz * colsz + BITSZ - 1) / BITSZ, BYTESZ);
    //assert(map);
    
    result = true;
    t = 0;
    
    for (i = 0; i < rectanglesRowSize; i ++) {
        for (y = rectangles[i][0]; y < rectangles[i][2]; y ++) { // bottom - top
            x = rectangles[i][1]; // left - right
            right = rectangles[i][3];
            while (x < right) {
                n = (y - bottom) * colsz + x - left;
                k = n / BITSZ;
                s = n % BITSZ;
                e = right - x;
                if (s || e < BITSZ) {
                    if (e >= BITSZ - s) {
                        b = all_bits[s] & all_ones[BYTESZ];
                        t += BITSZ - s;
                        x += BITSZ - s;
                    } else {
                        b = 0;
                        while (s < BITSZ && e) {
                            b |= 1 << s;
                            s ++;
                            e --;
                            t ++;
                            x ++;
                        }
                    }
                    if (map[k] & b) {
                        result = false;
                        goto done;
                    }
                    map[k] |= b;
                } else {
                    for (j = 0; j < e / BITSZ; j ++) {
                        if (map[k] & all_ones[BYTESZ]) {
                            result = false;
                            goto done;
                        }
                        map[k ++] |= all_ones[BYTESZ];
                        t += BITSZ;
                        x += BITSZ;
                    }
                }
            }
        }
    }
    
    if (t < rowsz * colsz) {
        result = false;
    }
​
done:
    free(map);
    
    return result;
}
​
#define BOTTOM(X) (X)[0]
#define LEFT(X)   (X)[1]
#define TOP(X)    (X)[2]
#define RIGHT(X)  (X)[3]
​
bool overlap(int *a, int *b) {
    if ((BOTTOM(b) < TOP(a)    && LEFT(b)  < RIGHT(a) &&
         TOP(b)    > BOTTOM(a) && RIGHT(b) > LEFT(a))) {
        return true;
    }
    return false;
}
bool map_area(int **rectangles, int rowsz) {
    int n;
    int *a, *b;
    int i, j;
    int x_min, y_min, x_max, y_max;
    
    n = 0;
    a = rectangles[0];
​
    y_min = BOTTOM(a);
    x_min = LEFT(a);
    y_max = TOP(a);
    x_max = RIGHT(a);
​
    for (i = 0; i < rowsz; i ++) {
        a = rectangles[i];
        n += (TOP(a) - BOTTOM(a)) * (RIGHT(a) - LEFT(a));  // total area
        y_min = (y_min > BOTTOM(a)) ? BOTTOM(a) : y_min;   // find the outermost shape
        x_min = (x_min > LEFT(a)) ? LEFT(a) : x_min;
        y_max = (y_max < TOP(a)) ? TOP(a) : y_max;
        x_max = (x_max < RIGHT(a)) ? RIGHT(a) : x_max;
        for (j = i + 1; j < rowsz; j ++) {
            b = rectangles[j];
            if (overlap(a, b)) {  // verify overlap
                return false;
            }
        }
    }
    
    return (n == ((y_max - y_min) * (x_max - x_min))) ? true : false;
}
bool isRectangleCover(int** rectangles, int rectanglesRowSize, int rectanglesColSize) {
    //return map_cover(rectangles, rectanglesRowSize);
    return map_area(rectangles, rectanglesRowSize);
}


/*
Difficulty:Hard
Total Accepted:10.3K
Total Submissions:39.2K


Companies Google

*/
