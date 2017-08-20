/*
383. Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom 
note can be constructed from the magazines ; otherwise, it will return false. 


Each letter in the magazine string can only be used once in your ransom note.


Note:
You may assume that both strings contain only lowercase letters.


canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

bool canConstruct(char* ransomNote, char* magazine) {
    int i, t = 0, n[26] = { 0 };
    
    while (ransomNote && *ransomNote) {
        i = *ransomNote - 'a';
        n[i] ++;
        t ++;
        ransomNote ++;
    }
    
    while (magazine && *magazine) {
        i = *magazine - 'a';
        if (n[i]) {
            n[i] --;
            t --;
        }
        magazine ++;
    }
    
    if (t) return false;
    
    return true;
}


/*
Difficulty:Easy
Total Accepted:58.8K
Total Submissions:124.9K


Companies Apple
Related Topics String

*/
