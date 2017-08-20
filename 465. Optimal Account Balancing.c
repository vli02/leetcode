/*
465. Optimal Account Balancing

A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].

Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.

Note:

A transaction will be given as a tuple (x, y, z). Note that x ? y and z > 0.
Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.



Example 1:
Input:
[[0,1,10], [2,0,5]]

Output:
2

Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.

Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.



Example 2:
Input:
[[0,1,10], [1,0,1], [1,2,5], [2,0,5]]

Output:
1

Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.

Therefore, person #1 only need to give person #0 $4, and all debt is settled.
*/

struct person_money {
    int pid;
    int credit;
};
​
int minTransfers(int** transactions, int transactionsRowSize, int transactionsColSize) {
    struct person_money *pm;
    int a, b, m;
    int i, j;
    int k, x;
    int t;
    
    pm = calloc(transactionsRowSize * 2, sizeof(struct person_money));
    //assert(pm);
    
    // caculate credit and debt
    k = x = 0;
    for (i = 0; i < transactionsRowSize; i ++) {
        a = transactions[i][0];
        b = transactions[i][1];
        m = transactions[i][2];
        j = 0;
        while (j < k && pm[j].pid != a) {
            j ++;
        }
        if (j == k) {
            k ++;   // new person
            x ++;   // new debt
            pm[j].pid = a;
        }
        pm[j].credit += m;
        if (pm[j].credit == 0) {
            x --;
        }
        
        j = 0;
        while (j < k && pm[j].pid != b) {
            j ++;
        }
        if (j == k) {
            k ++;   // new person
            x ++;   // new debt
            pm[j].pid = b;
        }
        pm[j].credit -= m;
        if (pm[j].credit == 0) {
            x --;
        }
    }
    
    t = 0;
​
spm:    
    // single person match
    for (i = 0; i < k - 1; i ++) {
        if (pm[i].credit != 0) {
            for (j = i + 1; j < k; j ++) {
                if (pm[i].credit + pm[j].credit == 0) {
                    pm[i].credit = pm[j].credit = 0;
                    t ++;
                    x -= 2;
                    break;
                }
            }
        }
    }
​
    if (x == 0) {
        goto done;
    }
    
    // split
    for (i = 0; i < k - 1; i ++) {
        if (pm[i].credit != 0) {
            for (j = i + 1; j < k; j ++) {
                if ((pm[i].credit > 0 && pm[j].credit < 0) ||
                    (pm[i].credit < 0 && pm[j].credit > 0)) {
                    if ((pm[i].credit + pm[j].credit > 0 && pm[i].credit > 0) ||
                        (pm[i].credit + pm[j].credit < 0 && pm[i].credit < 0)) {
                        pm[i].credit += pm[j].credit;
                        pm[j].credit = 0;
                    } else {
                        pm[j].credit += pm[i].credit;
                        pm[i].credit = 0;
                    }
                    t ++;
                    x --;
                    goto spm;
                }
            }
        }
    }
    
done:
    free(pm);
    
    return t;
}


/*
Difficulty:Hard
Total Accepted:4.5K
Total Submissions:12.2K


Companies Google

*/
