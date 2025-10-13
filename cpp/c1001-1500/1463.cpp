class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
    
            vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
            dp[0][0][cols-1] = grid[0][0] + grid[0][cols- 1];
    
            for(int row = 0; row < rows - 1; row++){
                for(int col1 = 0; col1 < cols; col1++){
                    for(int col2 = 0; col2 < cols; col2++){
                        if(dp[row][col1][col2] == -1) continue;
    
                        for(int d1 = -1; d1 <= 1; d1++){
                            for(int d2 = -1; d2 <= 1; d2++){
                                int newCol1 = col1 + d1;
                                int newCol2 = col2 + d2;
    
                                if(newCol1 < 0 || newCol1 >= cols || newCol2 < 0 || newCol2 >= cols){
                                    continue;
                                }
    
                                int cherries = dp[row][col1][col2];
    
                                if(newCol1 == newCol2){
                                    cherries += grid[row+1][newCol1];
                                }
                                else{
                                    cherries += grid[row+1][newCol1] + grid[row+1][newCol2];
                                }
    
                                dp[row+1][newCol1][newCol2] = max(dp[row+1][newCol1][newCol2], cherries);
                            }
                        }
                    }
                }
            }
            int res = 0;
            for(int col1 = 0; col1 < cols; col1++){
                for(int col2 = 0; col2 < cols; col2++){
                    res = max(res, dp[rows-1][col1][col2]);
                }
            }
            return res;
        }
    };