#include "main.h"
// Reverse Integer
// Input: 123
// Output: 321
class ReverseInteger {
public:
    int reverse(int x) {
        string str = to_string(x);
        if(x < 0){
            str = to_string(x * -1);
        }
        string newStr  = "";
        int i = str.size();
        while(i != 0){
            newStr.push_back(str.at(i-1));
            i = i - 1;
        }
        int result = stoi(newStr);
        if(x < 0){
            result = result * -1;
        }
        if(result < INT_MIN || result > INT_MAX){
            return 0;
        }
        else{
            return result;
        }
    }
    int mathReverse(int num){
        long res = 0;
        
        while(num != 0){
            res = res * 10 + num % 10;
            num = num / 10;
        }
        if(res < INT32_MIN){
            return INT32_MIN;
        }
        if(res > INT32_MAX){
            return INT32_MAX;
        }
        return (int)res;
    }
};

int main(){
    ReverseInteger r;
    long num = -123456789123;
    
    // int reverseInt = r.reverse(num);
    // cout << reverseInt << endl;
    int math = r.mathReverse(num);
    cout << math << endl;

}