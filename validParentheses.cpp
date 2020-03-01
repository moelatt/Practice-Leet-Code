#include "main.h"
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Input: "()[]{}"
// Output: true

// Input: "([)]"
// Output: false

// Need to use Stack (Last in First out) ==> {[]}
class Parentheses {
public:
    bool isValid(string s) {
        stack<char> stackVec;
        for(auto ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                stackVec.push(ch);
            }
            else if(ch == ')' && !stackVec.empty() && stackVec.top() == '('){
                stackVec.pop();
            }
            else if(ch == ']' && !stackVec.empty() && stackVec.top() == '['){
                stackVec.pop();
            }
            else if(ch == '}' && !stackVec.empty() && stackVec.top() == '{'){
                stackVec.pop();
            }
            else
            {
                return false;
            }
        }
        return stackVec.empty();
    }
};
int main(){
    Parentheses p;
    bool flag = p.isValid("{[]()}{}");
    if(flag){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}