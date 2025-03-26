#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        // dp[i][j] represents the side length of the largest square ending at (i-1, j-1)
        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
        int maxSide = 0;
        
        // Iterate through the matrix
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1') {
                    // If current cell is '1', take minimum of left, top, and top-left diagonal
                    // and add 1 to form a larger square
                    dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    maxSide = std::max(maxSide, dp[i][j]);
                }
            }
        }
        
        // Return area (square of the side length)
        return maxSide * maxSide;
    }
};
// Let's break down how this solution works:

// Approach:
// We use dynamic programming with a 2D DP array.
// dp[i][j] represents the side length of the largest square ending at position (i-1, j-1) in the original matrix.
// For each cell with '1', we look at the minimum of three neighbors (left, top, top-left diagonal) and add 1.
// Key Insights:
// If a cell is '0', no square can end there (dp value remains 0).
// If a cell is '1', the square size depends on the smallest square among its three neighbors plus 1.
// We use an extra row and column in dp array (initialized to 0) to handle boundary cases.
// Time and Space Complexity:
// Time Complexity: O(m × n) where m and n are the dimensions of the matrix
// Space Complexity: O(m × n) for the dp array
// How it works with Example 1:
// text
// Wrap
// Copy
// Input:
// ["1","0","1","0","0"]
// ["1","0","1","1","1"]
// ["1","1","1","1","1"]
// ["1","0","0","1","0"]

// DP table progression (showing only relevant part):
// 0 0 0 0 0 0
// 0 1 0 1 0 0
// 0 1 0 1 1 1
// 0 1 1 2 2 2
// 0 1 0 0 1 0

// - At (2,3) we get dp[3][4] = 2 because min(2,1,1) + 1 = 2
// - Max side length is 2, so area = 4
// Optimization Note: We could optimize space to O(n) by using a 1D array and keeping track of previous row values, but this 2D solution is more readable and still efficient.
// The solution handles all the given test cases:

// Example 1: Returns 4 (2×2 square)
// Example 2: Returns 1 (1×1 square)
// Example 3: Returns 0 (no square possible)
// This implementation efficiently finds the largest square of 1's in the binary matrix while meeting all the constraints and producing the expected output for each example.