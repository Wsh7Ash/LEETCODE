#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    
    // If the start or end cell has an obstacle, return 0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;  // Start point
    
    // Fill first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 0) ? dp[i-1][0] : 0;
    }
    
    // Fill first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 0) ? dp[0][j-1] : 0;
    }
    
    // Fill the rest of the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            } else {
                dp[i][j] = 0;  // Obstacle blocks the path
            }
        }
    }
    
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid1 = {{0,0,0}, {0,1,0}, {0,0,0}};
    cout << uniquePathsWithObstacles(grid1) << endl; // Output: 2
    
    vector<vector<int>> grid2 = {{0,1}, {0,0}};
    cout << uniquePathsWithObstacles(grid2) << endl; // Output: 1
    
    return 0;
}
