class Solution {
    public:
        int ways(vector<string>& pizza, int k) {
            int rows = pizza.size();
            int cols = pizza[0].size();
            int MOD = 1e9+7;
    
            vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
            for(int i = rows - 1; i >= 0; i--){
                for(int j = cols - 1; j >= 0; j--){
                    prefix[i][j] = prefix[i+1][j] + prefix[i][j+1] - prefix[i+1][j+1] + (pizza[i][j] == 'A'); 
                }
            }
    
            vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k + 1, -1)));
    
            return dfs(0, 0, k - 1, rows, cols, prefix, dp, MOD);
        }
    
    private:
        int dfs(int r, int c, int pieces, int rows, int cols, vector<vector<int>>& prefix, vector<vector<vector<int>>>& dp, int MOD){
            if(prefix[r][c] == 0) return 0;
            if(pieces == 0) return 1;
            if(dp[r][c][pieces] != -1) return dp[r][c][pieces];
            long long ways = 0;
            for(int i = r + 1; i < rows; i++){
                if(prefix[r][c] - prefix[i][c] > 0){
                    ways = (ways + dfs(i, c, pieces - 1, rows, cols, prefix, dp, MOD)) % MOD;
                }
            }
            for(int j = c + 1; j < cols; j++){
                if(prefix[r][c] - prefix[r][j] > 0){
                    ways = (ways + dfs(r, j, pieces - 1, rows, cols, prefix, dp, MOD)) % MOD;
                }
            }
    
            return dp[r][c][pieces] = ways;
        }
    };