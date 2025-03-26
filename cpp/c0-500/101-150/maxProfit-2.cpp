#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        
        // Traverse the prices array
        for (int i = 1; i < prices.size(); i++) {
            // If there's an increase in price, add the difference to total_profit
            if (prices[i] > prices[i - 1]) {
                total_profit += prices[i] - prices[i - 1];
            }
        }
        
        return total_profit;  // Return the maximum profit
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit for prices1: " << sol.maxProfit(prices1) << endl; // Expected output: 7

    // Example 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Maximum profit for prices2: " << sol.maxProfit(prices2) << endl; // Expected output: 4

    // Example 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Maximum profit for prices3: " << sol.maxProfit(prices3) << endl; // Expected output: 0

    return 0;
}
