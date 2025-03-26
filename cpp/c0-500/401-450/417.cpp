#include <vector>

class Solution {
private:
    // Directions for adjacent cells: up, right, down, left
    vector<vector<int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, 
             int row, int col, int prevHeight) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Check boundaries and if cell is reachable with current height
        if (row < 0 || row >= m || col < 0 || col >= n || 
            reachable[row][col] || heights[row][col] < prevHeight) {
            return;
        }
        
        // Mark as reachable
        reachable[row][col] = true;
             
        // Explore all four directions
        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            dfs(heights, reachable, newRow, newCol, heights[row][col]);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        // Track cells reachable from Pacific and Atlantic
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS from Pacific borders (left and top)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, -1);    // Left edge
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, -1);    // Top edge
        }
        
        // DFS from Atlantic borders (right and bottom)
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n-1, -1); // Right edge
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m-1, j, -1); // Bottom edge
        }
        
        // Find cells reachable from both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    
    auto result = solution.pacificAtlantic(heights);
    for (auto& coord : result) {
        cout << "[" << coord[0] << "," << coord[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
Let's break down how this solution works:

Approach:
Use DFS from ocean borders to find all reachable cells
Water flows from lower to equal/higher heights
Find intersection of cells reachable from both oceans
Algorithm:
Create two boolean matrices: one for Pacific, one for Atlantic
Run DFS from Pacific borders (left and top)
Run DFS from Atlantic borders (right and bottom)
Find cells marked true in both matrices
DFS Function:
Takes current position and previous height
Checks boundaries and height conditions
Marks cell as reachable
Recursively explores all four directions
Key Features:
Uses -1 as initial prevHeight to allow all border cells
Time Complexity: O(m*n) - each cell visited at most twice
Space Complexity: O(m*n) for the two boolean matrices
Example:
For cell [0,4]:
Pacific: reachable from top edge
Atlantic: directly on right edge
For cell [2,2]:
Pacific: path through [1,2] -> [0,2]
Atlantic: path through [2,3] -> [2,4]
The solution handles all constraints:

Works for m,n from 1 to 200
Handles heights from 0 to 10^5
Correctly identifies all cells that can flow to both oceans
This approach is efficient because:

Each cell is visited at most twice (once per ocean)
DFS naturally follows the water flow paths
Simple intersection operation finds the final result