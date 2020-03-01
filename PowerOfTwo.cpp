#include "main.h"

// Given an integer, write a function to determine if it is a power of two.
// Input: 16
// Output: true
// Explanation: 2^4 = 16
// Input: 218
// Output: false

class PowerOfTwo {
    public:
    bool isPowerOfTwo(int n) {
        long i = 1;
        while(i < n){
            i = i * 2;
        }
        return i == n;
    }
};

int main(){
    PowerOfTwo obj;
    bool flag = obj.isPowerOfTwo(4);
    if(flag == 1){
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
}