class Solution {
    public:
        bool hasValidPath(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            
            if (m == 1 && n == 1) return true;
            
            vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            
            
            vector<vector<int>> streetDirs = {
                {},  
                {1, 3},
                {0, 2},
                {2, 3},
                {1, 2},
                {0, 3},
                {0, 1} 
            };
            
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x == m - 1 && y == n - 1) return true;
                
                int street = grid[x][y];
                
                for (int dir : streetDirs[street]) {
                    int nx = x + dirs[dir][0];
                    int ny = y + dirs[dir][1];
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        int neighborStreet = grid[nx][ny];
                        int reverseDir = (dir + 2) % 4; 
                        
                        bool canConnect = false;
                        for (int neighborDir : streetDirs[neighborStreet]) {
                            if (neighborDir == reverseDir) {
                                canConnect = true;
                                break;
                            }
                        }
                        
                        if (canConnect) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            
            return false;
        }
    };