#include "main.h"
// Given an array of integers, find if the array contains any duplicates.

// Your function should return true if any value appears at least twice in the array, 
// and it should return false if every element is distinct.
// Input: [1,2,3,1]
// Output: true
// Input: [1,2,3,4]
// Output: false
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(auto i : nums){
            if(m.find(i) != m.end()){
                return true;
            }
            m[i] = true;
        }
        return false;
    }
};
int main(){
    Solution s;
    int arr[] = {1,2,3,3,4};
    vector<int> num(begin(arr), end(arr));
    int flag = s.containsDuplicate(num);
    if(flag){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}