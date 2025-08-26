class Solution {
    public:
        int mctFromLeafValues(vector<int>& arr) {
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));
            vector<vector<int>> maxLeaf(n, vector<int>(n, 0));
    
            for(int i = 0; i < n; i++){
                maxLeaf[i][i] = arr[i];
                for(int j = i+1; j < n; j++){
                    maxLeaf[i][j] = max(maxLeaf[i][j-1], arr[j]);
                }
            }
    
            for(int l = 2; l <= n; l++){
                for(int i = 0; i <= n - l; i++){
                    int j = i + l - 1;
                    dp[i][j] = INT_MAX;
                    for(int k = i; k < j; k++){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + maxLeaf[i][k] * maxLeaf[k+1][j]);
                    }
                }
            }
            return dp[0][n-1];
        }
    };