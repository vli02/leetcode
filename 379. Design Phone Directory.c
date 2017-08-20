/*
379. Design Phone Directory

Design a Phone Directory which supports the following operations:



get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.



Example:
// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/

typedef struct {
    int *numbers;
    int max_num;
} PhoneDirectory;
​
/** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
PhoneDirectory* phoneDirectoryCreate(int maxNumbers) {
    PhoneDirectory *obj = malloc(sizeof(PhoneDirectory));
    //assert(obj);
    obj->max_num = maxNumbers;
    obj->numbers = calloc((maxNumbers + 31)/32, sizeof(int));
    //assert(obj->numbers);
    return obj;
}
​
/** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
int phoneDirectoryGet(PhoneDirectory* obj) {
    int i;
    for (i = 0; i < obj->max_num; i ++) {
        if (!(obj->numbers[i / 32] & (1 << (i % 32)))) {
            obj->numbers[i / 32] |= 1 << (i % 32);
            return i;
        }
    }
    return -1;
}
​
/** Check if a number is available or not. */
bool phoneDirectoryCheck(PhoneDirectory* obj, int number) {
    if (number < 0 ||
        number >= obj->max_num ||
        obj->numbers[number / 32] & (1 << (number % 32))) return false;
    return true;
}
​
/** Recycle or release a number. */
void phoneDirectoryRelease(PhoneDirectory* obj, int number) {
    if (number >= 0 && number < obj->max_num) {
        obj->numbers[number / 32] &= ~(1 << (number % 32));
    }
}
​
void phoneDirectoryFree(PhoneDirectory* obj) {
    free(obj->numbers);
    free(obj);
}
​
/**
 * Your PhoneDirectory struct will be instantiated and called as such:
 * struct PhoneDirectory* obj = phoneDirectoryCreate(maxNumbers);
 * int param_1 = phoneDirectoryGet(obj);
 * bool param_2 = phoneDirectoryCheck(obj, number);
 * phoneDirectoryRelease(obj, number);
 * phoneDirectoryFree(obj);
 */


/*
Difficulty:Medium
Total Accepted:10.6K
Total Submissions:32.3K


Companies Google
Related Topics Linked List Design

*/
