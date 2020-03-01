#include "main.h"
// Median of Two Sorted Arrays ==> (Hard)
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
class MeanTwoArray {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double mean = 0.0; 
		vector<int> newArr;
		int totalSize = nums1.size() + nums2.size();
		int tempIndex;
		
		tempIndex = round(totalSize / 2);
		for(int i = 0; i < nums1.size(); i++){
			newArr.push_back(nums1[i]);
		}
		for(int i = 0; i < nums2.size(); i++){
			newArr.push_back(nums2[i]);
		}
		sort(newArr.begin(), newArr.end()); // sorting vector 
		if(totalSize % 2 == 1){
			mean = (newArr[tempIndex]);
		}
		else{
			mean = (newArr[tempIndex] + newArr[tempIndex - 1]) / 2.0;
		}
		return mean;
    }
};
int main(){
	MeanTwoArray m;
	int firstArr[] = {1,3};
	int secondArr[] = {2};
	vector<int> num1(begin(firstArr), end(firstArr)); // ***
	vector<int>num2(begin(secondArr), end(secondArr));
	
	double result = m.findMedianSortedArrays(num1, num2);
	cout << result << endl;
	
	return 0;
}