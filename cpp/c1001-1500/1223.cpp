class Solution {
    public:
        int dieSimulator(int n, vector<int>& rollMax) {
            const int mod = 1e9 + 7;
    
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(6, vector<int>(16, 0)));
    
            for(int j = 0; j < 6; j++){
                dp[1][j][1] = 1;
            }
    
            for(int i = 2; i <= n; i++){
                for(int j = 0; j < 6; j++){
                    for(int k = 1; k <= rollMax[j]; k++){
                        for(int l = 0; l < 6; l++){
                            if(l == j){
                                if(k < rollMax[j]){
                                    dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k]) % mod;
                                }
                            }else{
                                dp[i][l][1] = (dp[i][l][1] + dp[i-1][j][k]) % mod;
                            }
                        }
                    }
                }
            }
            int res = 0;
            for(int j = 0; j < 6; j++){
                for(int k = 1; k <= rollMax[j]; k++){
                    res = (res + dp[n][j][k]) % mod;
                }
            }
            return res;
        }
    };