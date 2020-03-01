#include "main.h"
// Given a string, find the length of the longest substring
// without repeating characters.
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
class findOriginalString {
public:
    int lengthOfLongestSubstring(string s) {
		if(s == ""){
			return 0;
		}
		int count = 0; int start = 0;
		int stringSize = s.size();
		char char_arr[stringSize + 1];
		strcpy(char_arr, s.c_str()); // copy string to char

		bool *flag = new bool[256];

		for(int i = 0; i < s.size(); i++){
			if(flag[char_arr[i]]){
				for(int j = start; j < i; j++){
					start = j + 1; break;
				}
			}
			else{
				flag[char_arr[i]] = true;
			}
		}
		count = max(stringSize - start, count);
		return count;
    }
};
int main(){
	findOriginalString s;
	string str = "cbacbacb";
	int result = s.lengthOfLongestSubstring(str);
	cout << result << endl;
	return 0;
}