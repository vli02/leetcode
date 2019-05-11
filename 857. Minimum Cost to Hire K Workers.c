/*
857. Minimum Cost to Hire K Workers

There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:


	Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
	Every worker in the paid group must be paid at least their minimum wage expectation.


Return the least amount of money needed to form a paid group satisfying the above conditions.

 





Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.



Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 


 

Note:


	1 <= K <= N <= 10000, where N = quality.length = wage.length
	1 <= quality[i] <= 10000
	1 <= wage[i] <= 10000
	Answers within 10^-5 of the correct answer will be considered correct.
*/

// 1. brute-force with dfs to try every possibility is pretty straightforward
// 2. the final result will have at least one worker being paied with minimal wage,
//    use this woker's wage/quality ratio as standard to caculate other worker's wage,
//    if there are >= k workers can be hired, get the minimal wage of K workers in this group.
//    use each worker as the standard ratio.
// 3. sort by wage/quality ratio, the total wage of k workers will be:
//    total quality * ratio of kth.
//    increase ratio to next one and push out the biggest quality...

typedef struct {
    double ratio;
    int quality;
} e_t;
int cmp(const void *a, const void *b) {
    const e_t *e1 = a;
    const e_t *e2 = b;
    if (e1->ratio < e2->ratio) return -1;
    if (e1->ratio > e2->ratio) return 1;
    return 0;
}
int cmp2(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int K) {
    e_t e[10000];
    int heap[10000], hsz, i;
    long total_quality;
    double current_ratio, ans = 0, w;
    
    for (i = 0; i < qualitySize; i ++) {
        e[i].ratio = (double)wage[i] / quality[i];
        e[i].quality = quality[i];
    }
    
    qsort(e, qualitySize, sizeof(e_t), cmp);
    
    hsz = 0;
    total_quality = 0;
    for (i = 0; i < qualitySize; i ++) {
        //printf("%d:%f,%d\n", i, e[i].ratio, e[i].quality);
        heap[hsz ++] = e[i].quality;            // enqueue to heap
        total_quality += e[i].quality;
        current_ratio  = e[i].ratio;
        if (hsz > K) {                          // push out the largest quality from heap
            qsort(heap, hsz, sizeof(int), cmp2);    // TODO: use real heap to optimize
            total_quality -= heap[-- hsz];
        }
        if (hsz == K) {
            w = total_quality * current_ratio;
            if (ans == 0 || ans > w) ans = w;
        }
    }
    
    return ans;
}


/*
Difficulty:Hard


*/
