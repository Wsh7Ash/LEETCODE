class Solution {
    public:
        int palindromePartition(string s, int k) {
            int n = s.length();
    
            vector<vector<int>> cost(n, vector<int>(n, 0));
    
            for(int len = 2; len <= n; len++){
                for(int i = 0; i <= n - len; i++){
                    int j = i + len - 1;
                    cost[i][j] = cost[i+1][j-1];
                    if(s[i] != s[j]){
                        cost[i][j]++;
                    }
                }
            }
    
            vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
    
            dp[0][0] = 0;
    
            for(int i =1; i <= n; i++){
                for(int j = 1; j <= min(i, k); j++){
                    for(int prev = j - 1; prev < i; prev++){
                        if(dp[prev][j-1] != INT_MAX){
                            dp[i][j] = min(dp[i][j], dp[prev][j-1] + cost[prev][i-1]);
                        }
                    }
                }
            }
            return dp[n][k];
        }
    };