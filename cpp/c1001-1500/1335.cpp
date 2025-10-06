class Solution {
    public:
        int minDifficulty(vector<int>& jobDifficulty, int d) {
            int n = jobDifficulty.size();
    
            if(d > n) return -1;
    
            vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX));
    
            dp[0][0] = 0;
    
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= min(i, d); j++){
                    int maxDiff = 0;
                    for(int k = i; k >= j; k--){
                        maxDiff = max(maxDiff, jobDifficulty[k - 1]);
                        if(dp[k - 1][j - 1] != INT_MAX){
                            dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + maxDiff);
                        }
                    }
                }
            }
    
            return dp[n][d] == INT_MAX ? -1 : dp[n][d];
        }
    };