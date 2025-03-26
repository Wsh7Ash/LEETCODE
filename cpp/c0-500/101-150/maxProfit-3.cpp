#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // Arrays to hold maximum profit for 1st and 2nd transactions
        vector<int> profit1(n, 0);  // profit from the first transaction
        vector<int> profit2(n, 0);  // profit from the second transaction

        // Calculate profit1 (maximum profit with at most 1 transaction)
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);  // Track the minimum price
            profit1[i] = max(profit1[i - 1], prices[i] - minPrice);  // Max profit at i

        }

        // Calculate profit2 (maximum profit with at most 2 transactions)
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);  // Track the maximum price
            profit2[i] = max(profit2[i + 1], maxPrice - prices[i] + profit1[i]);  // Max profit from 2 transactions

        }

        return profit2[0];  // Maximum profit with at most 2 transactions
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Maximum profit for prices1: " << sol.maxProfit(prices1) << endl; // Expected output: 6

    // Example 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Maximum profit for prices2: " << sol.maxProfit(prices2) << endl; // Expected output: 4

    // Example 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Maximum profit for prices3: " << sol.maxProfit(prices3) << endl; // Expected output: 0

    return 0;
}
