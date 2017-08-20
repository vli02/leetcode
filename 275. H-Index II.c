/*
275. H-Index II

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/

int hIndex(int* citations, int citationsSize) {
    int i, h = 0;
    for (i = 0; i < citationsSize; i ++) {
        if (citations[citationsSize - 1 - i] >= i + 1) {
            h = i + 1;
        } else {
            break;
        }
    }
    return h;
}


/*
Difficulty:Medium
Total Accepted:50.2K
Total Submissions:146.3K


Companies Facebook
Related Topics Binary Search
Similar Questions 
                
                  
                    H-Index
*/
