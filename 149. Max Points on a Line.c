/*
149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 * }
 */
typedef struct slope_s {
    int x;
    int y;
    int n;
    struct slope_s *next;
} slope_t;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int maxPoints(struct Point* points, int pointsSize) {
    int i, j, k, s, v, m;
    int x, y, d;
    slope_t *list, *tail, *buff, *node;
    
    m = 0;
    list = tail = buff = NULL;
    for (i = 0; i < pointsSize; i ++) {
        k = s = v = 0;
        if (tail != NULL) tail->next = buff;
        buff = list;
        list = tail = NULL;
        for (j = i + 1; j < pointsSize; j ++) {
            x = points[j].x - points[i].x;
            y = points[j].y - points[i].y;
            if (x == 0) {
                if (points[j].y == points[i].y) {
                    s ++;
                } else {
                    v ++;
                }
            } else {
                d = gcd(y, x); // greatest common divider
                x = x / d;
                y = y / d;
                node = list;
                while (node && (node->x != x || node->y != y)) node = node-> next;
                if (node) node->n ++;
                else {
                    if (buff) {
                        node = buff;
                        buff = buff->next;
                    } else {
                        node = malloc(sizeof(slope_t));
                        //assert(node);
                    }
                    node->x = x;
                    node->y = y;
                    node->n = 1;
                    if (!tail) {  // first node of the list
                        node->next = NULL;  // cut if off from buff
                        list = tail = node;
                    } else {
                        node->next = list;  // chain it to the list
                        list = node;
                    }
                }
            }
        }
        if (k < v + s) k = v + s;
        node = list;
        while (node) {
            if (k < node->n + s) k = node->n + s;
            node = node->next;
        }
        k ++;
        
        if (m < k) m = k;
    }
    
    while (list) {
        node = list;
        list = list->next;
        free(node);
    }
    
    while (buff) {
        node = buff;
        buff = buff->next;
        free(node);
    }
    
    return m;
}


/*
Difficulty:Hard
Total Accepted:81.1K
Total Submissions:529.9K


Companies LinkedIn Apple Twitter
Related Topics Hash Table Math
Similar Questions 
                
                  
                    Line Reflection
*/
