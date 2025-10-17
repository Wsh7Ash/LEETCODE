class Solution {
    public:
        int getLengthOfOptimalCompression(string s, int k) {
            int n = s.length();
            int INF = 1e9;
    
            vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
            dp[0][0] = 0;
    
            for(int i = 1; i <= n; i++){
                for(int j = 0; j <= k; j++){
                    if(j > 0){
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    }
                    int same = 0, diff = 0;
                    for(int m = i; m <= n; m++){
                        if(s[m-1] == s[i-1]) same++;
                        else diff++;
                        if(j + diff <= k){
                            int extralen = 1;
                            if(same > 1){
                                if(same < 10) extralen = 2;
                                else if(same < 100) extralen = 3;
                                else extralen = 4;
                            }
                            dp[m][j+diff] = min(dp[m][j+diff], dp[i-1][j] + extralen);
                        }else{ 
                            break;
                        }
                    }
                }
            }
            return dp[n][k];
        }
    };