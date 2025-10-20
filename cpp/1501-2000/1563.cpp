class Solution {
    public:
        int stoneGameV(vector<int>& stoneValue) {
            int n = stoneValue.size();
            if(n == 1) return 0;
    
            vector<int> prefix(n + 1, 0);
            for(int i =0; i < n; i++){
                prefix[i+1] = prefix[i] + stoneValue[i];
            }
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            for(int l = 2; l <= n; l++){
                for(int i = 0; i + l <= n; i++){
                    int j = i + l - 1;
                    int t = prefix[j + 1] - prefix[i];
                    int sum =0;
                    for(int k = i; k < j; k++){
                        sum += stoneValue[k];
                        int ls = sum;
                        int rs = t - sum;
                        if(ls < rs){
                            dp[i][j] = max(dp[i][j], ls + dp[i][k]);
                        }
                        else if(rs < ls){
                            dp[i][j] = max(dp[i][j], rs + dp[k+1][j]);
                        }else{
                            dp[i][j] = max(dp[i][j], max(ls + dp[i][k], rs + dp[k+1][j]));
                        }
                    } 
                }
            }
            return dp[0][n-1];
        }
    };