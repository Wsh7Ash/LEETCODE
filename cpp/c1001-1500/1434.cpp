class Solution {
    public:
        int numberWays(vector<vector<int>>& hats) {
            int n = hats.size();
            const int MOD = 1e9+7;
    
            vector<vector<int>> hatToPeople(41);
            for(int i = 0; i < n; i++){
                for(int hat : hats[i]){
                    hatToPeople[hat].push_back(i);
                }
            }
    
            vector<int> dp(1 << n, 0);
            dp[0] = 1;
    
            for(int hat = 1; hat <= 40; hat++){
                for(int mask = (1 << n) - 1; mask >= 0; mask--){
                    for(int person : hatToPeople[hat]){
                        if(!(mask & (1 << person))){
                            dp[mask | (1 << person)] = (dp[mask | (1 << person)] + dp[mask]) % MOD;
                        }
                    }
                }
            }
            
            return dp[(1 << n) - 1];
        }
    };