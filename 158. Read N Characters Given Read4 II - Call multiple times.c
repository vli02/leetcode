/*
158. Read N Characters Given Read4 II - Call multiple times

The API: int read4(char *buf) reads 4 characters at a time from a file.



The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.



By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.



Note:
The read function may be called multiple times.
*/

// Forward declaration of the read4 API.
int read4(char *buf);
​
class Solution {
private:
    char saved[4];
    int saved_start = 0;
    int saved_len = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char *p = buf;
        int i, l, k = 0;
        
        if (!n) return n;
        
        if (saved_len) {
            k = n < saved_len ? n : saved_len;
            memcpy(p, &saved[saved_start], k * sizeof(char));
            saved_start = (saved_start + k) % 4;
            saved_len -= k;
            p += k;
            n -= k;
        }
        
        while (n >= 4) {
            l = read4(p);
            k += l;
            if (l < 4) return k;
            p += 4;
            n -= 4;
        }
        
        if (n) {
            l = read4(saved);
            i = l < n ? l : n;
            memcpy(p, saved, i * sizeof(char));
            saved_start = i;
            saved_len = l - i;
            k += i;
        }
        
        return k;
    }
};


/*
Difficulty:Hard
Total Accepted:27.8K
Total Submissions:115.4K


Companies Bloomberg Google Facebook
Related Topics String
Similar Questions 
                
                  
                    Read N Characters Given Read4
*/
