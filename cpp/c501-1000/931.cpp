class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>> dp(n, vector<int>(n));
            for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];
    
            for(int i = 1; i < n; i++){
                for(int j = 0; j < n; j++){
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
    
                    if(j > 0){
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + matrix[i][j]);
                    }
                    if(j < n - 1){
                        dp[i][j] = min(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
                    }
                }
            }
    
            int res = dp[n-1][0];
            for(int j = 1; j < n; j++){
                res = min(res, dp[n-1][j]);
            }
            return res;
        }
    };