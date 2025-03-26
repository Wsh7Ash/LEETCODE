#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int n = prices.size();
        // dp[i][0]: max profit when holding stock at day i
        // dp[i][1]: max profit when not holding stock (can buy) at day i
        // dp[i][2]: max profit when in cooldown at day i
        std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
        
        // Initial state
        dp[0][0] = -prices[0];  // Holding stock after buying
        dp[0][1] = 0;          // Not holding stock
        dp[0][2] = 0;          // In cooldown
        
        for (int i = 1; i < n; i++) {
            // Holding stock: either keep holding or buy from not holding state
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] - prices[i]);
            
            // Not holding: either stay not holding or sell from holding state
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][2]);
            
            // Cooldown: must come from selling on previous day
            dp[i][2] = dp[i-1][0] + prices[i];
        }
        
        // Maximum profit will be either not holding or in cooldown state
        return std::max(dp[n-1][1], dp[n-1][2]);
    }
};
Let's break down how this works:

State Definitions:
dp[i][0]: Maximum profit when holding stock at day i
dp[i][1]: Maximum profit when not holding stock (can buy) at day i
dp[i][2]: Maximum profit when in cooldown at day i
Transitions:
For holding (dp[i][0]):
Keep holding: dp[i-1][0]
Buy: dp[i-1][1] - prices[i]
For not holding (dp[i][1]):
Stay not holding: dp[i-1][1]
Come from cooldown: dp[i-1][2]
For cooldown (dp[i][2]):
Sell from holding: dp[i-1][0] + prices[i]
Optimization: We could optimize space to O(1) by only keeping previous day's values, but this version is clearer to understand.
Here's a test program:

cpp
Wrap
Copy
#include <iostream>
#include <vector>

class Solution {
    // ... (same implementation as above)
};

int main() {
    Solution solution;
    
    // Test case 1
    std::vector<int> prices1 = {1, 2, 3, 0, 2};
    std::cout << "Test 1: " << solution.maxProfit(prices1) << std::endl;
    
    // Test case 2
    std::vector<int> prices2 = {1};
    std::cout << "Test 2: " << solution.maxProfit(prices2) << std::endl;
    
    // Additional test cases
    std::vector<int> prices3 = {2, 1};
    std::cout << "Test 3: " << solution.maxProfit(prices3) << std::endl;
    
    std::vector<int> prices4 = {3, 2, 6, 5, 0, 3};
    std::cout << "Test 4: " << solution.maxProfit(prices4) << std::endl;
    
    return 0;
}
Expected Output:

text
Wrap
Copy
Test 1: 3
Test 2: 0
Test 3: 0
Test 4: 7
Complexity:

Time: O(n) where n is the length of prices array
Space: O(n) for the dp array
Key Points:

Handles cooldown period by maintaining separate state
Ensures we can't buy immediately after selling
Works with all constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
Returns maximum possible profit considering all restrictions
Explanation of Test Case 1:

prices = [1,2,3,0,2]
Buy at 1, sell at 2: profit = 1
Cooldown at 3
Buy at 0, sell at 2: profit = 2
Total profit = 3
The solution correctly handles all cases, including edge cases like single-element arrays, and follows the cooldown restriction while maximizing profit through multiple transactions.