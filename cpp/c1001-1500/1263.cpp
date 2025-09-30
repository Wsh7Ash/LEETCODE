class Solution {
    public:
        int minPushBox(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            // Find initial positions
            int playerRow = -1, playerCol = -1;
            int boxRow = -1, boxCol = -1;
            int targetRow = -1, targetCol = -1;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    switch (grid[i][j]) {
                        case 'S': playerRow = i; playerCol = j; break;
                        case 'B': boxRow = i; boxCol = j; break;
                        case 'T': targetRow = i; targetCol = j; break;
                    }
                }
            }
    
            // Validate all positions found
            if (playerRow == -1 || boxRow == -1 || targetRow == -1) {
                return -1;
            }
    
            // Use state: (boxRow, boxCol, playerRow, playerCol)
            queue<tuple<int, int, int, int, int>> q; // boxR, boxC, playerR, playerC, pushes
            unordered_set<int> visited;
            
            auto encode = [&](int br, int bc, int pr, int pc) {
                return ((br * n + bc) << 16) | (pr * n + pc);
            };
    
            int initial = encode(boxRow, boxCol, playerRow, playerCol);
            q.push({boxRow, boxCol, playerRow, playerCol, 0});
            visited.insert(initial);
    
            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while (!q.empty()) {
                auto [bRow, bCol, pRow, pCol, pushes] = q.front();
                q.pop();
    
                if (bRow == targetRow && bCol == targetCol) {
                    return pushes;
                }
    
                // Try all possible pushes
                for (auto& dir : dirs) {
                    int newBoxRow = bRow + dir[0];
                    int newBoxCol = bCol + dir[1];
                    int playerTargetRow = bRow - dir[0];  // Player needs to be behind the box
                    int playerTargetCol = bCol - dir[1];
    
                    // Check if new box position is valid
                    if (newBoxRow < 0 || newBoxRow >= m || newBoxCol < 0 || newBoxCol >= n || 
                        grid[newBoxRow][newBoxCol] == '#') {
                        continue;
                    }
    
                    // Check if player target position is valid
                    if (playerTargetRow < 0 || playerTargetRow >= m || playerTargetCol < 0 || 
                        playerTargetCol >= n || grid[playerTargetRow][playerTargetCol] == '#') {
                        continue;
                    }
    
                    // Check if player can reach the pushing position
                    if (!canReach(grid, pRow, pCol, playerTargetRow, playerTargetCol, bRow, bCol)) {
                        continue;
                    }
    
                    int newState = encode(newBoxRow, newBoxCol, bRow, bCol); // Player moves to box's old position
                    if (visited.find(newState) == visited.end()) {
                        visited.insert(newState);
                        q.push({newBoxRow, newBoxCol, bRow, bCol, pushes + 1});
                    }
                }
            }
            return -1;
        }
    
    private:
        bool canReach(vector<vector<char>>& grid, int startRow, int startCol,
                      int targetRow, int targetCol, int boxRow, int boxCol) {
            if (startRow == targetRow && startCol == targetCol) return true;
    
            int m = grid.size(), n = grid[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            
            q.push({startRow, startCol});
            visited[startRow][startCol] = true;
    
            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while (!q.empty()) {
                auto [row, col] = q.front();
                q.pop();
    
                for (auto& dir : dirs) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
    
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                        !visited[newRow][newCol] && grid[newRow][newCol] != '#' &&
                        !(newRow == boxRow && newCol == boxCol)) {
                        
                        if (newRow == targetRow && newCol == targetCol) {
                            return true;
                        }
                        
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
            return false;
        }
    };