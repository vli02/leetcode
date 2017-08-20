/*
332. Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.


Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.




    Example 1:
    tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    Return ["JFK", "MUC", "LHR", "SFO", "SJC"].


    Example 2:
    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
    Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    const char **s1 = *(const char ***)a, **s2 = *(const char ***)b;
    int c = strcmp(s1[0], s2[0]);
    if (c) return c;
    return strcmp(s1[1], s2[1]);
}
int dfs(int *v, char ***tickets, int n, char **p, int last, int d) {
    int i;
    
    if (d == n) {
        p[n] = tickets[last][1];
        return 1;
    }
    
    for (i = 0; i < n; i ++) {
        if (!v[i] && !strcmp(tickets[last][1], tickets[i][0])) {
            v[i] = 1;
            p[d] = tickets[i][0];
            if (dfs(v, tickets, n, p, i, d + 1)) return 1;
            v[i] = 0;
        }
    }
    
    return 0;
}
char** findItinerary(char*** tickets, int ticketsRowSize, int ticketsColSize, int* returnSize) {
    int *v, i, done;
    char **p;
    
    qsort(tickets, ticketsRowSize, sizeof(char **), cmp);
    
    p = malloc((ticketsRowSize + 1) * sizeof(char *));
    v = calloc(ticketsRowSize, sizeof(int));
    //assert(p && v);
    
    done = 0;
    for (i = 0; !done && i < ticketsRowSize; i ++) {
        if (!strcmp(tickets[i][0], "JFK")) {
            v[i] = 1;
            p[0] = tickets[i][0];
            done = dfs(v, tickets, ticketsRowSize, p, i, 1);
            v[i] = 0;
        }
    }
    
    *returnSize = ticketsRowSize + 1;
    free(v);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:36.5K
Total Submissions:125.2K


Companies Google
Related Topics Depth-first Search Graph

*/
