#include "main.h"
// Two Sum code with dynamic array.==> (Easy)
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		vector<int> newVec;
		for(int i = 0; i < nums.size(); i++){
			for(int j = i + 1; j < nums.size(); j++){
				if(nums.at(i) + nums.at(j) == target){
						newVec.push_back(i);
						newVec.push_back(j);
				}
			}
		}
		return newVec;
	}
	  vector<int> twoSum(vector<int> &numbers, int target) { // fast algorithm, run time complexity
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            // not found the second one
            if (m.find(numbers[i])== m.end() ) { 
                // store the first one poisition into the second one's key
                m[target - numbers[i]] = i; 
            }else { 
                // found the second one
                result.push_back(m[numbers[i]]+1);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};