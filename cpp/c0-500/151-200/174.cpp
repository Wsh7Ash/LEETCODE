#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    
    // DP table to store the minimum health at each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Start by filling the bottom-right corner (princess' position)
    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

    // Fill the last column (move upward from the princess)
    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
    }

    // Fill the last row (move left from the princess)
    for (int j = n - 2; j >= 0; j--) {
        dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
    }

    // Fill the rest of the DP table (move right and down)
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int minHealth = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, minHealth - dungeon[i][j]);
        }
    }

    // The minimum initial health needed at the start position (0,0)
    return dp[0][0];
}

int main() {
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << "Minimum initial health: " << calculateMinimumHP(dungeon) << endl;
    
    vector<vector<int>> dungeon2 = {{0}};
    cout << "Minimum initial health: " << calculateMinimumHP(dungeon2) << endl;
    
    return 0;
}
