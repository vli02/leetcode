/*
475. Heaters

Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.



Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.



Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
*/

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    int r = 0, k;
    int i, j;
    
    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);
    
    j = 0;
    for (i = 0; i < housesSize; i ++) {
        while (j < heatersSize - 1 &&
               abs(heaters[j + 1] - houses[i]) <= abs(heaters[j] - houses[i])) {
            j ++;
        }
        k = abs(heaters[j] - houses[i]);
        if (r < k) r = k;
    }
    return r;
}


/*
Difficulty:Easy
Total Accepted:19K
Total Submissions:64.3K


Companies Google
Related Topics Binary Search

*/
