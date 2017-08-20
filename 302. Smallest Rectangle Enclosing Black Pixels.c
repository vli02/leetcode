/*
302. Smallest Rectangle Enclosing Black Pixels

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.


For example, given the following image:
[
  "0010",
  "0110",
  "0100"
]

and x = 0, y = 2,



Return 6.
*/

int search_horizon(char **image, int start, int end, int rowsz, int left) {
    int mid, i;
    while (start < end) {
        mid = start + (end - start) / 2;
        for (i = 0; i < rowsz; i ++) {
            if (image[i][mid] == '1') break;
        }
        if (i < rowsz == left) {  // find '1' and on left, or don't find '1' and on right
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    
    return start;
}
int search_vertical(char **image, int start, int end, int l, int r, int top) {
    int mid, i;
    while (start < end) {
        mid = start + (end - start) / 2;
        for (i = l; i < r; i ++) {
            if (image[mid][i] == '1') break;
        }
        if (i < r == top) {  // find '1' and on top, or don't find '1' and on bottom
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    
    return end;
}
int minArea(char** image, int imageRowSize, int imageColSize, int x, int y) {
    int l, r, t, b;
    
    l = search_horizon (image, 0,     y,            imageRowSize, true);
    r = search_horizon (image, y + 1, imageColSize, imageRowSize, false);
    t = search_vertical(image, 0,     x,            l, r, true);
    b = search_vertical(image, x + 1, imageRowSize, l, r, false);
​
    return (r - l) * (b - t);
}


/*
Difficulty:Hard
Total Accepted:14.3K
Total Submissions:31.4K


Companies Google
Related Topics Binary Search

*/
