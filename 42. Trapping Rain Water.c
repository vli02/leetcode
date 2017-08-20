/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 



For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.




The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

int trap(int* height, int heightSize) {
    int w = 0;
    int i, j, h, k;
    
#if 0
    i = 0;
again:
    while (i + 1 < heightSize && height[i + 1] >= height[i]) { // find start point i
        i ++;
    }
    j = i + 1;
    if (j == heightSize) return 0;
    while (j < heightSize && height[j] < height[i]) {  // find end point j
        j ++;
    }
    if (j == heightSize) {
        height[i] -= 1;  // cut the bar and retry
        goto again;
    }
    if (j < heightSize) {
        for (k = i + 1; k < j; k ++) {
            w += height[i] - height[k];
        }
        w += trap(&height[j], heightSize - j);
    }
#else
    i = 0;
    j = heightSize - 1;
    k = 0;
    while (i <= j) {
        if (height[i] <= height[j]) {
            h = height[i ++];
        } else {
            h = height[j --];
        }
        if (k > h) {
            w += k - h;
        } else {
            k = h;
        }
    }
#endif
    return w;
}


/*
Difficulty:Hard
Total Accepted:121.2K
Total Submissions:330.6K


Companies Google Twitter Zenefits Amazon Apple Bloomberg
Related Topics Array Stack Two Pointers
Similar Questions 
                
                  
                    Container With Most Water
                  
                    Product of Array Except Self
                  
                    Trapping Rain Water II
*/
