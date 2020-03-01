#include "main.h"
// Given two strings s and t , write a function to determine if t is an anagram of s.
// Input: s = "anagram", t = "nagaram"
// Output: true

// Input: s = "rat", t = "car"
// Output: false

// You may assume the string contains only lowercase alphabets.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int counts[26] = {0}; // a to z (26 characters)
        for(int i = 0; i < s.size(); i++){
            counts[s.at(i) - 'a'] ++;
            counts[t.at(i) - 'a'] --;
            cout << counts[t.at(i) - 'a'] -- << endl;
        }
        for(auto i : counts){
            if(counts[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    string str = "krt";
    string t = "rkt";
    // int flag = s.isAnagram(str, t);
    // if(flag){
    //     cout << "true" << endl;
    // }
    // else{
    //     cout << "false" << endl;
    // }
    s.isAnagram(str, t);
    return 0;
}