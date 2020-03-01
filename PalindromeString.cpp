#include "main.h"
// Longest Palindromic Substring ===> (Medium)
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

class Palindromic {
public:
    string longestPalindrome(string s) {
        string str = "";
        int size = s.size();
        bool table[size][size];
        int maxLength = 1;
        for(int i = 0; i < size; i++){
            table[i][i] = true;
        }
        int start = 0; 
        for(int i = 0; i < size - 1; i++){
            if(s.at(i) == s.at(i+1)){
                table[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }
        for(int k = 3; k <= size; k++){
            for(int i = 0; i < size - k + 1; i++){
                int j = i + k - 1;
                if(table[i+1][j-1] && s.at(i) == s.at(j)){
                    table[i][j] = true;
                    if(k > maxLength){
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        for(int i = start; i <= start+ maxLength - 1; i++){
            str.push_back(s.at(i)); // string push to new string variabel
        }
        return str;
    }
};

int main(){
    Palindromic p;
    string str = "babad";
    string newStr = p.longestPalindrome(str);
    cout << newStr << endl;
    
    return 0;
}