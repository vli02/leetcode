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

#define HF 1021

typedef struct e_s {
    int y1;
    int y2;
    int x;
    struct e_s *shadow;
} e_t;

typedef struct {
    e_t *e[HF];
    e_t buff[250000];
    int n;
} h_t;

int hash_code(int y1, int y2) {
    int hc = y1 * 33 + y2;
    return hc % HF;
}

e_t *lookup(h_t *ht, int y1, int y2) {
    int hc = hash_code(y1, y2);
    e_t *e = ht->e[hc];
    while (e && (e->y1 != y1 || e->y2 != y2)) e = e->shadow;
    return e;
}

void insert(h_t *ht, int y1, int y2, int x) {
    e_t *e = &ht->buff[ht->n ++];
    int hc = hash_code(y1, y2);
    e->y1 = y1;
    e->y2 = y2;
    e->x = x;
    e->shadow = ht->e[hc];
    ht->e[hc] = e;
}

int cmp(const void *a, const void *b) {
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;
    
    if (p1[0] < p2[0]) return -1;
    if (p1[0] > p2[0]) return 1;
    if (p1[1] < p2[1]) return -1;
    return 1;
}

int minAreaRect(int** points, int pointsSize, int* pointsColSize){
    int i, j, x, y1, y2, area, ans = 0;
    e_t *e;
    h_t ht = { 0 };
    
    // x ascending, y ascending
    qsort(points, pointsSize, sizeof(int *), cmp);
    
    for (int i = 0; i < pointsSize - 1; i ++) {
        x  = points[i][0];
        y1 = points[i][1];
        for (j = i + 1; j < pointsSize && points[j][0] == x; j ++) {
            y2 = points[j][1];
            e = lookup(&ht, y1, y2);
            if (e) {
                area = (x - e->x) * (y2 - y1);
                if (ans == 0 || ans > area) ans = area;
                e->x = x;
            } else {
                insert(&ht, y1, y2, x);
            }
        }
    }
    
    return ans;
}


/*
Difficulty:Medium


*/
