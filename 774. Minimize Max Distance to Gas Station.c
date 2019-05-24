/*
774. Minimize Max Distance to Gas Station

On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000


Note:


	stations.length will be an integer in range [10, 2000].
	stations[i] will be an integer in range [0, 10^8].
	K will be an integer in range [1, 10^6].
	Answers within 10^-6 of the true value will be accepted as correct.
*/

​

int num_of_add_station(int *stations, int sz, double d) {
    int i, k;
    for (i = 0, k = 0; i < sz -1; i ++) {
        k += (stations[i + 1] - stations[i]) / d;
    }
    return k;
}
double minmaxGasDist(int* stations, int stationsSize, int K){
#if 0
    double dist[2000 + 1000000];
    int count[2000 + 1000000];
    int i, j;
    
    for (i = 0; i < stationsSize - 1; i ++) {
        dist[i] = stations[i + 1] - stations[i];
        count[i] = 1;
    }
    while (--K >= 0) {
        j = 0;
        for (i = 1; i < stationsSize - 1; i ++) {
            if (dist[i] / count[i] > dist[j] / count[j]) {
                j = i;
            }
        }
        count[j] ++;
    }
    
    j = 0;
    for (i = 1; i < stationsSize - 1; i ++) {
        if (dist[i] / count[i] > dist[j] / count[j]) {
            j = i;
        }
    }
    return dist[j] / count[j];
#else
    double dist, left, right, mid;
    int i, k;
    left = 0; right = 2147483647;
    while (right - left > 0.000001) {
        mid = left + (right - left) / 2;
        k = num_of_add_station(stations, stationsSize, mid);
        if (k <= K) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
#endif
}


/*
Difficulty:Hard


*/
