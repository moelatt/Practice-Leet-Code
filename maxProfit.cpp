#include "main.h"
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction 
// (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Note that you cannot sell a stock before you buy one.
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

/* Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price. */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int getMax = 0;
        int minPrice = INT32_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(minPrice > prices[i]){
                minPrice = prices[i];
            }
            else{
                getMax = max(getMax, prices[i] - minPrice);
            }
        }
        return getMax;
    }
};
int main(){
    int arr[] = {7,1,5,3,2,0,9};
    vector<int>num(begin(arr), end(arr));
    Solution s;
    int result = s.maxProfit(num);
    cout << result << endl;
}