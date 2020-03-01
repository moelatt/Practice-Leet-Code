#include "main.h"

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// first = "aa"
// second = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// first = "ab"
// second = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
class ExpressMatch {
public:
    bool isMatch(string first, string second) {
        
        if(second.length() == 0){
            return first.length() == 0;
        }
        //second'first length 1 is special case    
        if(second.length() == 1 || second.at(1) != '*'){
            if(first.length() < 1 || (second.at(0) != '.' && first.at(0) != second.at(0)))
                return false;
            return isMatch(first.substr(1), second.substr(1));    
 
        }else{
            int len = first.length();
 
            int i = -1; 
            while(i<len && (i < 0 || second.at(0) == '.' || second.at(0) == first.at(i))){
                if(isMatch(first.substr(i+1), second.substr(2)))
                    return true;
                i++;
            }
            return false;
        } 
    }
};
int main(){
    ExpressMatch e;
    string first = "aa";
    string second = "a*";
    int result = e.isMatch(first, second);
    if(result == 1){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    int len = first.size();
    cout << typeid(first.size()).name() << endl;
    cout << typeid(len).name() << endl;
    return 0;
}