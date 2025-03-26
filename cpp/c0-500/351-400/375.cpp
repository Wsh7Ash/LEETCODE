#include <vector>
#include <algorithm>

class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j] represents the minimum amount needed to guarantee a win
        // for numbers in range [i, j]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Fill the dp table for all possible ranges
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start + len - 1 <= n; start++) {
                int end = start + len - 1;
                dp[start][end] = INT_MAX;
                
                // Try each number k as the first guess in range [start, end]
                for (int k = start; k < end; k++) {
                    // Cost = k + max(cost if number is in left part, cost if number is in right part)
                    int cost = k + max(
                        dp[start][k - 1],    // left part
                        dp[k + 1][end]       // right part
                    );
                    dp[start][end] = min(dp[start][end], cost);
                }
            }
        }
        
        return dp[1][n];
    }
};
This solution uses a dynamic programming approach with the following logic:

DP State Definition:
dp[i][j] represents the minimum amount of money needed to guarantee a win when the number is between i and j inclusive
Base Cases:
When i = j (length = 1), cost is 0 (no guess needed)
When j = i + 1 (length = 2), cost is min(i, j) = i
DP Transition:
For each range [start, end]:
Try each number k in the range as the first guess
Cost = k + maximum of:
Cost for left part [start, k-1]
Cost for right part [k+1, end]
Take minimum of all possible costs
Time Complexity: O(n³)
Outer loop for length: O(n)
Inner loop for start position: O(n)
Loop for trying each guess k: O(n)
Space Complexity: O(n²)
2D DP table of size (n+1) × (n+1)
Example for n = 4:
text

Collapse

Wrap

Copy
dp[1][1] = 0
dp[2][2] = 0
dp[3][3] = 0
dp[4][4] = 0

dp[1][2] = 1    // guess 1: max(0,0) + 1
dp[2][3] = 2    // guess 2: max(0,0) + 2
dp[3][4] = 3    // guess 3: max(0,0) + 3

dp[1][3] = 2    // guess 2: max(dp[1][1],dp[3][3]) + 2 = 2
dp[2][4] = 4    // guess 3: max(dp[2][2],dp[4][4]) + 3 = 3

dp[1][4] = 4    // guess 2: max(dp[1][1],dp[3][4]) + 2 = 5
                // guess 3: max(dp[1][2],dp[4][4]) + 3 = 4 (minimum)
Key Insights:
We need to find the minimum cost that covers the worst-case scenario
For each guess, we take the maximum of left and right subproblems because we must prepare for the worst case
We then take the minimum across all possible guesses to find the optimal strategy
The solution is optimal because:

It considers all possible guessing strategies
It guarantees a win by preparing for the worst case at each step
It finds the minimum amount needed across all possible scenarios
It handles the constraint of n ≤ 200 efficiently
Note: This is different from the first Guess Number problem because:

We need to minimize cost rather than just find the number
We must guarantee a win regardless of the picked number
Each wrong guess costs money equal to the guessed number