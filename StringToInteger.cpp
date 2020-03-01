#include "main.h"
// String to Integer
// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
class StringToInt {
public:
    // white space skip function
    string trim(string& str)
    {
        size_t first = str.find_first_not_of(' ');
        if (first == std::string::npos)
            return "";
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last-first+1));
    }
    // convert string to integer
    int myAtoi(string str) {
        if(str == "")
            return 0;
        str = trim(str);
        if(str.length() < 1)
            return 0;

        bool isNeg = false;
        int startIndex = 0;
        if(str.at(0) == '-' ) {
            isNeg = true;
            startIndex++;
        }
        else if(str.at(0) == '+'){
            startIndex++;
        }
        else if(str.at(startIndex) == ' ') {
            startIndex++;
        }
        double result = 0;
        while(startIndex < str.length() && str.at(startIndex) >= '0' && str.at(startIndex) <= '9') {
            result = result*10 + (str.at(startIndex) - '0');
            startIndex++;
        }
        if(isNeg)
            result = -result;
        if (result > INT32_MAX)
            return INT32_MAX;

        if (result < INT32_MIN)
            return INT32_MIN;
        return (int)result;
    }
};
int main(){
    StringToInt s;
    string str = "        -42";
    int result = s.myAtoi(str);
    cout << result << endl;
    return 0;    
}