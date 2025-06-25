class Solution {
    public:
        int countPalindromicSubsequences(string s) {
            int n = s.size();
            const int MOD = 1e9 + 7;
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            for(int i = 0; i < n; i++){
                dp[i][i] = 1;
            }
    
            for(int len = 2; len <= n; len++){
                for(int i = 0; i <= n - len; i++){
                    int j = i + len -1;
                    if(s[i] == s[j]){
                        int l = i + 1;
                        int r = j - 1;
                        while(l <= r && s[l] != s[i]){
                            l++;
                        }
                        while(l <= r && s[r] != s[i]){
                            r--;
                        }
                        if(l > r){
                            dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                        }else if(l == r){
                            dp[i][j] = dp[i+ 1][j-1]*2 + 1;
                        }else{
                            dp[i][j] = dp[i+1][j-1]*2 - dp[l+1][r-1];
                        }
                    }else{
                        dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                    }
                    dp[i][j] = dp[i][j] < 0 ? dp[i][j] + MOD : dp[i][j] % MOD;
                }
            }
            return dp[0][n-1];
        }
    };