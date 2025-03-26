#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    // If k >= n/2, we can trade as much as we want (like Best Time to Buy and Sell Stock II)
    if (k >= n / 2) {
        int max_profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                max_profit += prices[i] - prices[i - 1];
        }
        return max_profit;
    }

    // DP array: dp[i][j] = max profit using at most i transactions up to day j
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int t = 1; t <= k; t++) {
        int maxDiff = -prices[0]; // max of (profit from previous transaction - price)
        for (int d = 1; d < n; d++) {
            dp[t][d] = max(dp[t][d - 1], prices[d] + maxDiff); // Either skip or sell today
            maxDiff = max(maxDiff, dp[t - 1][d] - prices[d]); // Update maxDiff for next day
        }
    }

    return dp[k][n - 1];
}

// Example usage
int main() {
    vector<int> prices1 = {2, 4, 1};
    cout << maxProfit(2, prices1) << endl; // Output: 2

    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(2, prices2) << endl; // Output: 7

    return 0;
}
