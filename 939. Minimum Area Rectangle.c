/*
939. Minimum Area Rectangle

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 


Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4



Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2


 

Note:


	1 <= points.length <= 500
	0 <= points[i][0] <= 40000
	0 <= points[i][1] <= 40000
	All points are distinct.
*/

int cmp(const void *a, const void *b) {
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;
    
    if (p1[0] < p2[0]) return -1;
    if (p1[0] > p2[0]) return 1;
    if (p1[1] < p2[1]) return -1;
    return 1;
}
​
int minAreaRect(int** points, int pointsSize, int* pointsColSize){
    int *a, *b, *c, *d, area, ans = 0;
    
    // x ascending, y ascending
    qsort(points, pointsSize, sizeof(int *), cmp);
    
    for (int i = 0; i < pointsSize; i ++) {
        a = points[i];
        for (int j = i + 1; j < pointsSize && points[j][0] == a[0]; j ++) {
            b = points[j];
            for (int k = j + 1; k < pointsSize; k ++) {
                c = points[k];
                if (c[1] == a[1]) {
                    for (int l = k + 1; l < pointsSize && points[l][0] == c[0]; l ++) {
                        d = points[l];
                        if (d[1] == b[1]) {
                            // this is a rectangle
                            area = (b[1] - a[1]) * (c[0] - a[0]);
                            if (ans == 0 || ans > area) ans = area;
                            goto next;
                        }
                    }

            }
next:
            b = NULL;
        }
    }
    
    return ans;
}
​
​


/*
Difficulty:Medium


*/
