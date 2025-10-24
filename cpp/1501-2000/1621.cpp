class Solution {
    public:
        int numberOfSets(int n, int k) {
            const int MOD = 1e9+7;
            int N = n + k - 1;
            int K = 2 * k;
    
            vector<int> dp(K + 1, 0);
            dp[0] = 1;
    
            for(int i = 1; i <= N; i++){
                for(int j = min(i, K); j > 0; j--){
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
            }
            return dp[K];
        }
    };