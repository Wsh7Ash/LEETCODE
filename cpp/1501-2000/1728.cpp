class Solution {
    public:
        int rows, cols;
        vector<string> grid;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
            this->grid = grid;
            rows = grid.size();
            cols = grid[0].size();
            
            int mx, my, cx, cy, fx, fy;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 'M') mx = i, my = j;
                    else if (grid[i][j] == 'C') cx = i, cy = j;
                    else if (grid[i][j] == 'F') fx = i, fy = j;
                }
            }
            
            
            vector<vector<vector<vector<vector<int>>>>> dp(
                rows, vector<vector<vector<vector<int>>>>(
                    cols, vector<vector<vector<int>>>(
                        rows, vector<vector<int>>(
                            cols, vector<int>(2, 0)
                        )
                    )
                )
            );
            
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == '#') continue;
                    for (int k = 0; k < rows; k++) {
                        for (int l = 0; l < cols; l++) {
                            if (grid[k][l] == '#') continue;
                            if (i == fx && j == fy) {
                                dp[i][j][k][l][0] = dp[i][j][k][l][1] = 1;
                            }
                            else if (k == fx && l == fy || (i == k && j == l)) {
                                dp[i][j][k][l][0] = dp[i][j][k][l][1] = 2;
                            }
                        }
                    }
                }
            }
            
            for (int iter = 0; iter < 1000; iter++) {
                bool changed = false;
                
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (grid[i][j] == '#') continue;
                        for (int k = 0; k < rows; k++) {
                            for (int l = 0; l < cols; l++) {
                                if (grid[k][l] == '#') continue;
                                if (i == fx && j == fy) continue;
                                if (k == fx && l == fy) continue;
                                if (i == k && j == l) continue;
                                
                                if (dp[i][j][k][l][0] == 0) {
                                    bool canWin = false;
                                    bool allCatWin = true;
                                    
                                    for (auto& dir : dirs) {
                                        for (int jump = 0; jump <= mouseJump; jump++) {
                                            int ni = i + dir.first * jump;
                                            int nj = j + dir.second * jump;
                                            if (ni < 0 || ni >= rows || nj < 0 || nj >= cols || grid[ni][nj] == '#') break;
                                            
                                            if (dp[ni][nj][k][l][1] == 1) {
                                                canWin = true;
                                                break;
                                            }
                                            if (dp[ni][nj][k][l][1] != 2) {
                                                allCatWin = false;
                                            }
                                        }
                                        if (canWin) break;
                                    }
                                    
                                    if (canWin) {
                                        dp[i][j][k][l][0] = 1;
                                        changed = true;
                                    } else if (allCatWin) {
                                        dp[i][j][k][l][0] = 2;
                                        changed = true;
                                    }
                                }
                                
                                if (dp[i][j][k][l][1] == 0) {
                                    bool canWin = false;
                                    bool allMouseWin = true;
                                    
                                    for (auto& dir : dirs) {
                                        for (int jump = 0; jump <= catJump; jump++) {
                                            int nk = k + dir.first * jump;
                                            int nl = l + dir.second * jump;
                                            if (nk < 0 || nk >= rows || nl < 0 || nl >= cols || grid[nk][nl] == '#') break;
                                            
                                            if (dp[i][j][nk][nl][0] == 2) {
                                                canWin = true;
                                                break;
                                            }
                                            if (dp[i][j][nk][nl][0] != 1) {
                                                allMouseWin = false;
                                            }
                                        }
                                        if (canWin) break;
                                    }
                                    
                                    if (canWin) {
                                        dp[i][j][k][l][1] = 2;
                                        changed = true;
                                    } else if (allMouseWin) {
                                        dp[i][j][k][l][1] = 1;
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
                
                if (!changed) break;
            }
            
            return dp[mx][my][cx][cy][0] == 1;
        }
    };