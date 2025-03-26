class Solution {
    public:
        int trapRainWater(vector<vector<int>>& heightMap) {
            if (heightMap.empty() || heightMap[0].empty()) return 0;
            
            int m = heightMap.size();
            int n = heightMap[0].size();
            int water = 0;
            
            // Min heap of {height, row, col}
            priority_queue<tuple<int, int, int>, 
                          vector<tuple<int, int, int>>, 
                          greater<>> pq;
            
            // Track visited cells
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            
            // Directions: up, right, down, left
            vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
            
            // Add all border cells to priority queue
            for (int i = 0; i < m; i++) {
                pq.push({heightMap[i][0], i, 0});
                pq.push({heightMap[i][n-1], i, n-1});
                visited[i][0] = visited[i][n-1] = true;
            }
            for (int j = 1; j < n-1; j++) {
                pq.push({heightMap[0][j], 0, j});
                pq.push({heightMap[m-1][j], m-1, j});
                visited[0][j] = visited[m-1][j] = true;
            }
            
            int maxHeight = 0;  // Maximum height encountered from borders
            
            // Process cells starting from lowest height
            while (!pq.empty()) {
                auto [height, row, col] = pq.top();
                pq.pop();
                
                maxHeight = max(maxHeight, height);
                
                // Check all four adjacent cells
                for (auto [dr, dc] : dirs) {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    
                    if (newRow >= 0 && newRow < m && 
                        newCol >= 0 && newCol < n && 
                        !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        
                        // If current cell is lower than maxHeight, it can trap water
                        if (heightMap[newRow][newCol] < maxHeight) {
                            water += maxHeight - heightMap[newRow][newCol];
                        }
                        
                        pq.push({heightMap[newRow][newCol], newRow, newCol});
                    }
                }
            }
            
            return water;
        }
    };
    How this solution works:
    
    Approach:
    Use a min-heap to process cells from lowest to highest height
    Start from border cells (water flows out from borders)
    BFS-like expansion tracking maximum height encountered
    Key Insight:
    Water trapped at a cell = min height of surrounding barriers - cell height
    Process from outside in, maintaining minimum boundary height
    Similar to 1D trapping rain water but in 2D
    Algorithm:
    Add all border cells to min-heap
    Process lowest height cell:
    Update maxHeight seen so far
    Check all 4 adjacent cells
    If unvisited and lower than maxHeight, add water
    Add new cells to heap
    Continue until all cells processed
    Example Walkthrough ([[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]):
    text
    
    Collapse
    
    Wrap
    
    Copy
    Start with borders, process lowest (1):
    - Check neighbors, update maxHeight
    - Find cells lower than maxHeight (e.g., 2 next to 4)
    - Add water when height < maxHeight
    Total water = 4
    Complexity:
    Time: O(mn log(mn)) - heap operations for each cell
    Space: O(mn) - heap and visited array
    Key Features:
    Handles 2D grid correctly
    Calculates water volume based on minimum surrounding height
    Processes all possible water-trapping cells
    The solution satisfies all constraints:
    
    Works for m,n from 1 to 200
    Handles heights from 0 to 2*10⁴
    Returns correct water volume
    Key optimizations:
    
    Uses min-heap for efficient lowest-height processing
    Marks visited cells to avoid cycles
    Starts from borders as natural boundaries
    The solution correctly handles:
    
    Example 1: [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] → 4
    Example 2: [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]] → 10
    This approach efficiently computes trapped water by simulating how water would be contained by the lowest surrounding barriers, expanding inward from the edges of the map.