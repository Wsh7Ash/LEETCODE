#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;  // Initialize the minimum price to a very large number
        int max_profit = 0;  // Initially, the maximum profit is 0
        
        // Traverse through the prices array
        for (int price : prices) {
            // Update the minimum price if we find a smaller price
            min_price = min(min_price, price);
            
            // Calculate the profit if we sell at the current price
            int profit = price - min_price;
            
            // Update the maximum profit
            max_profit = max(max_profit, profit);
        }
        
        return max_profit;  // Return the maximum profit
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << "Maximum profit for prices1: " << sol.maxProfit(prices1) << endl; // Expected output: 5

    // Example 2
    vector<int> prices2 = {7,6,4,3,1};
    cout << "Maximum profit for prices2: " << sol.maxProfit(prices2) << endl; // Expected output: 0

    return 0;
}
