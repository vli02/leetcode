/*
406. Queue Reconstruction by Height

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.


Note:
The number of people is less than 1,100.


Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#if 0
int validate(int **q, int i) {
    int j, k;
    k = 0;
    for (j = 0; j < i; j ++) {
        if (q[j][0] >= q[i][0]) {
            k ++;
        }
    }
    if (k != q[i][1]) {
        return 0;
    }
    return 1;
}
int reconstruct(int *visited, int **q, int **p, int d, int sz) {
    int i;
    if (d == 0) {
        return 1;
    } else {
        for (i = 0; i < sz; i ++) {
            if (!visited[i]) {
                visited[i] = 1;
                q[sz - d][0] = p[i][0];
                q[sz - d][1] = p[i][1];
                if (validate(q, sz - d) && reconstruct(visited, q, p, d - 1, sz)) {
                    return 1;
                }
                visited[i] = 0;
            }
        }
    }
    return 0;
}
#else
int cmp(const void *a, const void *b) {
    int c;
    c = (*(int **)b)[0] - (*(int **)a)[0];  // height decreasing order
    if (c) return c;
    c = (*(int **)a)[1] - (*(int **)b)[1];  // number increasing order
    return c;
}
int reconstruct(int *visited, int **q, int **p, int d, int sz) {
    int i, j, k;
    int t[2];
    
    qsort(p, sz, sizeof(int *), cmp);
    
    for (i = 0; i < sz; i ++) {
        q[i][0] = p[i][0];
        q[i][1] = p[i][1];
        if (q[i][1] > i) {
            return 0;  // no way to make it!
        }
        if (q[i][1] < i) {  // move it ahead
            t[0] = q[i][0];
            t[1] = q[i][1];
            for (j = i; j > t[1]; j --) {  // find a slot ahead by pulling some one slot back
                q[j][0] = q[j - 1][0];
                q[j][1] = q[j - 1][1];
            }
            q[j][0] = t[0];  // done with current one
            q[j][1] = t[1];
        }
    }
    return 1;
}
#endif
int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize) {
    int **q, *buff;
    int *visited;
    int i;
    
    *returnSize = 0;
    if (peopleRowSize == 0 || !people) {
        return NULL;
    }
    q = malloc(peopleRowSize * sizeof(int *));
    buff = malloc(peopleRowSize * peopleColSize * sizeof(int));
    visited = calloc(peopleRowSize, sizeof(int));
    //assert(q && buff && visited);
    
    for (i = 0; i < peopleRowSize; i ++) {
        q[i] = &buff[i * peopleColSize];
    }
    
    if (!reconstruct(visited, q, people, peopleRowSize, peopleRowSize)) {
        free(q[0]);
        free(q);
        q = NULL;
        *returnSize = 0;
    } else {
        *returnSize = peopleRowSize;
    }
    free(visited);
    
    return q;
}


/*
Difficulty:Medium
Total Accepted:27.2K
Total Submissions:48.8K


Companies Google
Related Topics Greedy
Similar Questions 
                
                  
                    Count of Smaller Numbers After Self
*/
