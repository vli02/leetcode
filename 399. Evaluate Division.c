/*
399. Evaluate Division

Equations are given in the format A / B = k, where  A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].


The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.


According to the example above:
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 



The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

#define DUMP(OP, OP1, OP2) do { } while (0)
​
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
double math(int k, double op1, double op2) {
DUMP(k, op1, op2);
    switch(k) {
        case 1:
            op1 = 1.0;
            break;
        case 2:
            op1 = op2;
            break;
        case 3:
            op1 = 1 / op2;
            break;
        case 4:
        case 5:
            op1 = op1 * op2;
            break;
        case 6:
        case 7:
            op1 = op1 / op2;
            break;
    }
    return op1;
}
int match(char **strs, char *fm, char *fz) {
    int x00, x01, x10, x11;
    int k = 0;
    
    x00 = !strcmp(fm, strs[0]);
    x01 = !strcmp(fm, strs[1]);
    x10 = !strcmp(fz, strs[0]);
    x11 = !strcmp(fz, strs[1]);
    
    if ((!x00 && !x01 && !x10 && !x11) ||
        (x00 && x01 && !x10) ||
        (x10 && x11 && !x00)){
        k = 0; // no match or useless match
    } else if ((x00 && x10) || (x01 && x11)) {
        k = 1;  // 1
    } else if (x00 && x11) {
        k = 2;  // equal
    } else if (x01 && x10) {
        k = 3;  // reverse
    } else if (x00) {
        k = 4;  // multiply
    } else if (x11) {
        k = 5;
    } else if (x01) {
        k = 6;  // divide
    } else if (x10) {
        k = 7;
    }
    return k;
}
int calc(int *visited, double *d, char ***equa, double *val, int rowsz, char *fm, char *fz) {
    int i, k, x;
​
    for (i = 0; i < rowsz; i ++) {
        if (visited[i] == 0) {
            k = match(equa[i], fm, fz);
            if (k >= 1 && k <= 3) {
                *d = math(k, *d, val[i]);
                return 1;
            } else if (k != 0) {
                visited[i] = 1;
                if (k == 4) {
                    x = calc(visited, d, equa, val, rowsz, equa[i][1], fz);
                } else if (k == 5) {
                    x = calc(visited, d, equa, val, rowsz, fm, equa[i][0]);
                } else if (k == 6) {
                    x = calc(visited, d, equa, val, rowsz, equa[i][0], fz);
                } else /*if (k == 7)*/ {
                    x = calc(visited, d, equa, val, rowsz, fm, equa[i][1]);
                }
                visited[i] = 0;
                if (x) {
                    *d = math(k, *d, val[i]);
                    return 1;
                }
            }
        }
    }
    return 0;
}
double* calcEquation(char*** equations, int equationsRowSize, int equationsColSize, double* values, int valuesSize, char*** queries, int queriesRowSize, int queriesColSize, int* returnSize) {
    int *visited;
    double *results, d;
    
    int i;
    
    results = malloc(queriesRowSize * sizeof(double));
    visited = calloc(equationsRowSize, sizeof(int));
    //assert(result && visited);
    
    *returnSize = queriesRowSize;
    
    for (i = 0; i < queriesRowSize; i ++) {
        d = -1.0;
        calc(visited, &d, equations, values, equationsRowSize, queries[i][0], queries[i][1]);
        results[i] = d;
    }
    
    free(visited);
    
    return results;
}


/*
Difficulty:Medium
Total Accepted:17.1K
Total Submissions:42K


Companies Google
Related Topics Graph

*/
