class Solution {
    public:
        string stoneGameIII(vector<int>& stoneValue) {
            int n = stoneValue.size();
            vector<int> dp(4, 0);
    
            for(int i = n - 1; i >= 0; i--){
                int best = INT_MIN;
                int take = 0;
    
                for(int k = 0; k <3 && i + k < n; k++){
                    take += stoneValue[i + k];
                    best = max(best, take - dp[(i + k + 1) % 4]);
                }
                dp[i % 4] = best;
            }
    
            if(dp[0] > 0) return "Alice";
            if(dp[0] < 0) return "Bob";
            return "Tie";
        }
    };