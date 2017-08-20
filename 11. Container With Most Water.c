/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

int maxArea(int* height, int heightSize) {
    int l, r, x, water, max = 0;
    int i, j;
#if 0
    for (i = 0; i < heightSize - 1; i ++) {
        if (i == 0 || height[i] > l) {
            l = height[i];
            for (j = i + 1; j < heightSize; j ++) {
                r = height[j];
                x = l < r ? l : r;
                water = x * (j - i);
                if (max < water) max = water;
            }
        }
    }
#else
    i = 0;
    j = heightSize - 1;
    while (i < j) {
        l = height[i];
        r = height[j];
        x = l < r ? l : r;
        water = x * (j - i);
        if (max < water) max = water;
        if (l < r) i ++;
        else j --;
    }
#endif
    return max;
}


/*
Difficulty:Medium
Total Accepted:144.5K
Total Submissions:395.2K


Companies Bloomberg
Related Topics Array Two Pointers
Similar Questions 
                
                  
                    Trapping Rain Water
*/
