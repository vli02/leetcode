/*
223. Rectangle Area

Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.




Assume that the total area is never beyond the maximum possible value of int.


Credits:Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
*/

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int a, b, c, d, e, f, g, h;
    int dup;
    int x, y;
    if (A < E) {
        a = A; b = B; c = C; d = D;
        e = E; f = F; g = G; h = H;
    } else {
        a = E; b = F; c = G; d = H;
        e = A; f = B; g = C; h = D;
    }
    if (h < b || f > d || e > c) {
        dup = 0;
    } else {
        x = c < g ? c - e : g - e;
        y = d < h ? d - (b > f ? b : f) : h - (b > f ? b : f);
        dup = x * y;
    }
    return (c - a) * (d - b) + (g - e) * (h - f) - dup;
}


/*
Difficulty:Medium
Total Accepted:63.1K
Total Submissions:191.8K


Related Topics Math

*/
