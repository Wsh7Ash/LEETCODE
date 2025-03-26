#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check bounds and if the current cell is land ('1')
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current land as visited
        grid[i][j] = '0';
        
        // Explore all 4 directions: up, down, left, right
        dfs(grid, i - 1, j); // up
        dfs(grid, i + 1, j); // down
        dfs(grid, i, j - 1); // left
        dfs(grid, i, j + 1); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int islandCount = 0;

        // Traverse through every cell in the grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j); // Call DFS to mark all connected land as visited
                }
            }
        }

        return islandCount;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int result = solution.numIslands(grid);
    cout << "Number of Islands: " << result << endl;

    return 0;
}
