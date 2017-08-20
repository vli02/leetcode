/*
274. H-Index

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.



According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."



For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.



Note: If there are several possible values for h, the maximum one is taken as the h-index.


Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

int hIndex(int* citations, int citationsSize) {
    int i, j, k = 0;
    int n;
#if 0   // O(n^2) 39ms
    for (i = citationsSize; i > 0; i --) { // for every possible h
        n = 0;
        for (j = 0; j < citationsSize; j ++) { // for every citation
            if (citations[j] >= i) n ++;
        }
        if (n >= i) {
            return i;
        }
    }
#else   // O(n) 3ms
    int *x;
    x = calloc(citationsSize + 1, sizeof(int));
    //assert(x);
    for (i = 0; i < citationsSize; i ++) { // for every citation
        j = citations[i] > citationsSize ? citationsSize : citations[i];
        x[j] ++;
    }
    n = 0;
    for (i = citationsSize; i > 0; i --) {
        n += x[i];
        if (n >= i) { k = i; break; }
    }
    free(x);
#endif
    return k;
}


/*
Difficulty:Medium
Total Accepted:77.3K
Total Submissions:233.4K


Companies Bloomberg Google Facebook
Related Topics Hash Table Sort
Similar Questions 
                
                  
                    H-Index II
*/
