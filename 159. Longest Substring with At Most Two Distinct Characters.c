/*
159. Longest Substring with At Most Two Distinct Characters

Given a string, find the length of the longest substring T that contains at most 2 distinct characters.



For example,

Given s = “eceba”,



T is "ece" which its length is 3.
*/

int lengthOfLongestSubstringTwoDistinct(char* s) {
    int cnt[128] = { 0 };
    int head, tail, d = 0;
    char c;
    
    int k = 2;
    
    head = tail = 0;
    while (s[tail]) {
        while (s[tail] && (cnt[s[tail]] > 0 || k > 0)) { // advance k distinct characters
            if (cnt[s[tail]] == 0) {
                k --;  // reduce number if a new character is counted
            }
            cnt[s[tail]] ++;  // record the count
            tail ++;
        }
        
        if (d < tail - head) {
            d = tail - head;
        }
        
        do {
            c = s[head ++];
            cnt[c] --;  // reduce the count
        } while (cnt[c] > 0);  // push out one distinct character from head
        
        k = 1;  // find another one distince character from tail
    }
    
    return d;
​
}


/*
Difficulty:Hard
Total Accepted:28K
Total Submissions:68.1K


Companies Google
Related Topics Hash Table Two Pointers String
Similar Questions 
                
                  
                    Longest Substring Without Repeating Characters
                  
                    Sliding Window Maximum
                  
                    Longest Substring with At Most K Distinct Characters
*/
