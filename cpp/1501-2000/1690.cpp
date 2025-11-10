class Solution {
    public:
        int stoneGameVII(vector<int>& stones) {
            int n = stones.size();
            vector<int> prefixSum(n + 1, 0);
            for(int i = 0; i < n; i++){
                prefixSum[i + 1] = prefixSum[i] + stones[i];
            }
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            for(int l = 2; l <= n; l++){
                for(int i = 0; i <= n - l; i++){
                    int j = i + l - 1;
                    int rmL = (prefixSum[j + 1] - prefixSum[i + 1]) - dp[i+1][j];
                    int rmR = (prefixSum[j] - prefixSum[i]) - dp[i][j - 1];
                    dp[i][j] = max(rmL, rmR);
                }
            }
            return dp[0][n-1];
        }
    };