#include "main.h"

// Container with most water
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49
class MostWater {
public:
    int maxArea(vector<int>& vec) {
        int maxArea = 0;
        int min = 0, max = vec.size() - 1;
        int area;
        while(min < max){
            if(vec[min] < vec[max]){
                area = (max - min) * vec[min];
            }
            else{
                area = (max - min) * vec[max];
            }
            // area = (max - min) * (vec[min] < vec[max]? vec[min]:vec[max]);
            // maxArea = area > maxArea ? area : maxArea;
            if(area > maxArea){
                maxArea = area;
            }
            if(vec[min] < vec[max]){
                do{
                    min++;
                } while(min < max && vec[min - 1] >= vec[min]);
            }
            else{
                do{
                    max--;
                }while(max > min && vec[max+1] >= vec[max]);
            }
            
        }
        return maxArea;
    }
};

int main(){
    MostWater m;
    int arr[] = {1,2,3};
    vector<int> vec(begin(arr), end(arr));
    int result = m.maxArea(vec);
    cout << result << endl;
    return 0;
}