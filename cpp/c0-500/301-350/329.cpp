#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Cache to store the longest path length from each cell
        vector<vector<int>> cache(m, vector<int>(n, 0));
        int maxLength = 0;
        
        // Check every cell as a starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLength = max(maxLength, dfs(matrix, i, j, cache));
            }
        }
        
        return maxLength;
    }
    
private:
    // Four directions: up, right, down, left
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache) {
        // If already computed, return cached result
        if (cache[i][j] != 0) return cache[i][j];
        
        int m = matrix.size();
        int n = matrix[0].size();
        int maxPath = 1;  // Minimum path length is 1 (current cell)
        
        // Check all four directions
        for (auto& dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];
            
            // Check boundaries and if next value is greater
            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && 
                matrix[newI][newJ] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(matrix, newI, newJ, cache));
            }
        }
        
        cache[i][j] = maxPath;
        return maxPath;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> matrix1 = {{9,9,4},{6,6,8},{2,1,1}};
    cout << solution.longestIncreasingPath(matrix1) << endl;  // Output: 4
    
    // Test case 2
    vector<vector<int>> matrix2 = {{3,4,5},{3,2,6},{2,2,1}};
    cout << solution.longestIncreasingPath(matrix2) << endl;  // Output: 4
    
    // Test case 3
    vector<vector<int>> matrix3 = {{1}};
    cout << solution.longestIncreasingPath(matrix3) << endl;  // Output: 1
    
    return 0;
}
How it works:

DFS with Memoization:
We use DFS to explore all possible paths from each cell
Cache stores the longest increasing path length starting from each cell
This prevents recalculating the same paths multiple times
Algorithm:
For each cell in the matrix:
Explore all 4 directions (up, right, down, left)
Only move to neighboring cell if its value is greater
Use DFS to find longest path from each neighbor
Cache the result for current cell
Return maximum path length found
Example Walkthrough for [[9,9,4],[6,6,8],[2,1,1]]:
From (2,1)=1: can go to (2,0)=2 or (1,1)=6
From (2,0)=2: can go to (1,0)=6
From (1,1)=6 or (1,0)=6: can go to (0,0)=9
Longest path: 1->2->6->9 (length 4)
Complexity:

Time Complexity: O(m*n)
Each cell is visited once and cached
Each cell checks 4 neighbors
Space Complexity: O(m*n) for the cache
Key Features:

Handles all four directions correctly
Prevents moving outside boundaries
No diagonal movement
Works with all test cases
The solution satisfies all constraints:

Works for m,n between 1 and 200
Handles values from 0 to 2^31-1
Returns correct longest increasing path length
For the examples:

[[9,9,4],[6,6,8],[2,1,1]] → 4 (1->2->6->9)
[[3,4,5],[3,2,6],[2,2,1]] → 4 (3->4->5->6)
[[1]] → 1 (single cell)