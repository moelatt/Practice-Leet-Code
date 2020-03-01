#include "main.h"

// Given a non-empty array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//  using hash table algorithm
class findSingleNum {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            s = s ^ nums[i];
        }
        return s;
    }
};

int main(){
    findSingleNum f;
    int arr[] = {1,2,4,1,2};
    vector<int> num(begin(arr), end(arr));
    int result = f.singleNumber(num);
    cout << result << endl;
}