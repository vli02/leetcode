/*
135. Candy

There are N children standing in a line. Each child is assigned a rating value. 


You are giving candies to these children subjected to the following requirements:


Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.


What is the minimum candies you must give?
*/

int candy(int* ratings, int ratingsSize) {
    int *candies;
    int i, x;
    
    if (ratingsSize < 2) return ratingsSize;
    
    candies = malloc(ratingsSize * sizeof(int));
    //assert(candies);
    
    candies[0] = 1;
    for (i = 1; i < ratingsSize; i ++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        } else {
            candies[i] = 1;
        }
    }
    
    x = candies[ratingsSize - 1];
    
    for (i = ratingsSize - 2; i >= 0; i --) {
        if (ratings[i] > ratings[i + 1]) {
            if (candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }
        x += candies[i];
    }
    
    free(candies);
    
    return x;
}

/*
Difficulty:Hard
Total Accepted:70.3K
Total Submissions:284.7K


Related Topics Greedy

*/
