class Solution {
    public:
        int knightDialer(int n) {
            if(n == 1) return 10;
            const int MOD = 1e9 + 7;
            vector<vector<int>> moves = {{4,6}, {6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
    
            vector<vector<long long>> dp(n, vector<long long>(10, 0));
            for(int j = 0; j < 10; j++){
                dp[0][j] = 1;
            }
    
            for(int i = 1; i < n; i++){
                for(int j = 0; j < 10; j++){
                    for(int prev : moves[j]){
                        dp[i][j] = (dp[i][j] + dp[i-1][prev]) % MOD;
                    }
                }
            }   
    
            long long tot = 0;
            for(int j = 0; j < 10; j++){
                tot = (tot  + dp[n-1][j]) % MOD;
            }
            return tot;
        }
    };