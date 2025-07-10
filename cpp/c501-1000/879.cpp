class Solution {
    public:
        int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
            const int MOD = 1e9 + 7;
            int m = group.size();
            vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(minProfit +1, 0)));
    
            dp[0][0][0] = 1;
            for(int i =1;i<=m; i++){
                int g = group[i-1];
                int p = profit[i-1];
                for(int j = 0; j <= n; j++){
                    for(int k = 0; k <= minProfit; k++){
                        dp[i][j][k] = dp[i-1][j][k];
                        if(j >= g){
                            int prev_k = max(k-p, 0);
                            dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-g][prev_k]) % MOD;
                        }
                    }
                }
            }   
            int res = 0;
            for(int j = 0; j <= n; j++){
                res = (res + dp[m][j][minProfit]) % MOD;
            }
            return res;
        }
    };