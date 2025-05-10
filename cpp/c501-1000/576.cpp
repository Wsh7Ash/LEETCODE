class Solution {
    public:
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            int MOD = 1e9 + 7;
    
            vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
            int directions[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
    
            for(int k = 1; k <= maxMove; k++){
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        for(auto& dir : directions){
                            int ni = i + dir[0];
                            int nj = j + dir[1];
    
                            if(ni < 0 || ni >= m|| nj < 0 || nj >= n){
                                dp[k][i][j] += 1;
                            }else{
                                dp[k][i][j] = (dp[k][i][j] + dp[k-1][ni][nj]) % MOD;
                            }
                        }
                    }
                }
            }
    
            return dp[maxMove][startRow][startColumn] % MOD;
        }
    };