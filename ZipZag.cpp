#include "main.h"
// ZigZag conversion ==>(Medium)
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// ZipZap mean element follows < , > alternatively
// [5, 10, 8, 12, 6, 9, 4]
class ZipZag {
public:
    string convert(string s, int numRows) {
        string newStr= "";
        int step = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++){
            if(i == 0 || i == numRows - 1){
                for(int j = i; j < s.size(); j = j + step){
                    newStr.push_back(s.at(j));
                }
            }
            else{
                int j = i;
                bool flag = true;
                int step1 = 2 * (numRows - 1 - i);
                int step2 = step - step1;
                while(j < s.size()){
                    newStr.push_back(s.at(j));
                    if(flag){
                        j = j + step1;
                    }
                    else{
                        j = j + step2;
                    }
                    flag = !flag;
                }
            }
        }
        return newStr;
    }
    void convertZZint(int arr[] , int numRows, int arrSize) {
        vector<int> newArr;
        int step = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++){
            if(i == 0 || i == numRows - 1){
                for(int j = i; j < arrSize; j = j + step){
                    newArr.push_back(arr[j]);
                }
            }
            else{
                int j = i;
                bool flag = true;
                int step1 = 2 * (numRows - 1 - i);
                int step2 = step - step1;
                while(j < arrSize){
                    newArr.push_back(arr[j]);
                    if(flag){
                        j = j + step1;
                    }
                    else{
                        j = j + step2;
                    }
                    flag = !flag;
                }
            }
        }
        for(int i = 0; i < newArr.size(); i++){
            cout << newArr[i] << " ";
        }
    }
};
int main(){
    ZipZag z;
    string str = "PAYPALISHIRING";
    int arr[] = {1,2,3,4,5,6,7};
    int arrSize = sizeof(arr)/sizeof(*arr);
    int row = 4;
    string newStr = z.convert(str, row);
    cout << newStr << endl;
    z.convertZZint(arr, 3, arrSize);
    cout << endl;
}