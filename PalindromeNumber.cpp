#include "main.h"
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
class PalindromeNumber {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int div = 1;
        while(x / div >= 10){
            div = div * 10;
        }
        while(x != 0){
            int left = x / div;
            int right = x % 10;
            if(left != right){
                return false;
            }
            x = (x % div) / 10;
            div = div / 100;
        }
        return true;
    }
};

int main(){
    PalindromeNumber p;
    int num = 113;
    bool flag = p.isPalindrome(num);
    if(flag == 1){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}