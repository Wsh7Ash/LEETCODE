class Solution {
    public:
        int numOfArrays(int n, int m, int k) {
            const int MOD = 1e9 + 7;
            if (k == 0 || k > m) return 0;
            
            vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, 0));
            vector<vector<long long>> next(m + 1, vector<long long>(k + 1, 0));
            
            for (int j = 1; j <= m; j++) {
                dp[j][1] = 1;
            }
            
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= m; j++) {
                    for (int c = 1; c <= k; c++) {
                        next[j][c] = 0;
                    }
                }
                
                for (int j = 1; j <= m; j++) {
                    for (int c = 1; c <= k; c++) {
                        if (dp[j][c] == 0) continue;
                        
                        next[j][c] = (next[j][c] + dp[j][c] * j) % MOD;
                        
                        if (c < k) {
                            for (int newJ = j + 1; newJ <= m; newJ++) {
                                next[newJ][c + 1] = (next[newJ][c + 1] + dp[j][c]) % MOD;
                            }
                        }
                    }
                }
                
                swap(dp, next);
            }
            
            long long res = 0;
            for (int j = 1; j <= m; j++) {
                res = (res + dp[j][k]) % MOD;
            }
            return res;
        }
    };