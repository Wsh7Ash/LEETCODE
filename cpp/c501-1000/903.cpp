class Solution {
    public:
        int numPermsDISequence(string s) {
            const int MOD = 1e9 + 7;
            int n = s.size();
            vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    
            dp[0][0] = 1;
            for(int i = 1; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    if(s[i - 1] == 'D'){
                        for(int k = j; k < i ;k++){
                            dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                        }
                    }else{
                        for(int k = 0; k < j; k++){
                            dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                        }
                    }
                }
            }   
            int res = 0;
            for(int j = 0; j <= n; j++){
                res = (res + dp[n][j]) % MOD;
            }
            return res;
        }
    };