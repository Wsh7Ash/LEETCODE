The "Coin Change" problem is a classic dynamic programming problem. The goal is to determine the minimum number of coins required to make up a given amount using coins of specified denominations. If it's not possible to make up the amount with the given coins, we return -1.

Approach:
Dynamic Programming Table:

Use a dp array where dp[i] represents the minimum number of coins needed to make up the amount i.

Initialize dp[0] = 0 because no coins are needed to make up the amount 0.

Initialize all other entries in dp to a large value (e.g., amount + 1) to represent an unreachable state.

Fill the DP Table:

For each amount from 1 to amount, iterate through all coin denominations.

If the coin value is less than or equal to the current amount, update dp[i] as the minimum of its current value and dp[i - coin] + 1.

Result:

If dp[amount] remains the initial large value, it means the amount cannot be made up with the given coins, so return -1.

Otherwise, return dp[amount].

Code Implementation:
cpp
Copy
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // Initialize dp array with a large value
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: 0 coins are needed to make up amount 0

        // Fill the dp array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still the initial value, return -1
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
Explanation:
Initialization:

dp[0] = 0: No coins are needed to make up the amount 0.

All other dp[i] are set to amount + 1 (a value larger than the maximum possible number of coins).

DP Table Filling:

For each amount i from 1 to amount, check each coin denomination.

If the coin value is less than or equal to i, update dp[i] to be the minimum of its current value and dp[i - coin] + 1.

Result:

If dp[amount] is still amount + 1, it means the amount cannot be made up with the given coins, so return -1.

Otherwise, return dp[amount], which is the minimum number of coins needed.

Example Walkthrough:
Input: coins = [1,2,5], amount = 11
Initialize dp array:

dp = [0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12]

Fill the dp array:

For i = 1: Use coin 1, dp[1] = min(12, dp[0] + 1) = 1

For i = 2: Use coin 1 or 2, dp[2] = min(12, dp[1] + 1, dp[0] + 1) = 1

For i = 3: Use coin 1 or 2, dp[3] = min(12, dp[2] + 1, dp[1] + 1) = 2

Continue this process until i = 11.

Result:

dp[11] = 3 (using two 5 coins and one 1 coin).

Input: coins = [2], amount = 3
Initialize dp array:

dp = [0, 4, 4, 4]

Fill the dp array:

For i = 1: No valid coin, dp[1] = 4

For i = 2: Use coin 2, dp[2] = min(4, dp[0] + 1) = 1

For i = 3: No valid coin, dp[3] = 4

Result:

dp[3] = 4 (which is greater than amount), so return -1.

Time Complexity:
O(amount * n): Where n is the number of coin denominations. We iterate through all amounts and all coins for each amount.

Space Complexity:
O(amount): We use a dp array of size amount + 1.

This approach is efficient and works well within the given constraints.