class Solution {
    public:
        int change(int amount, vector<int>& coins) {
           vector<int> dp(amount + 1,0);
           dp[0] = 1;
           for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                if(dp[i - coin] > INT_MAX - dp[i]){
                    return 0;
                }
                dp[i] += dp[i-coin];
            }
           } 
           return dp[amount] > INT_MAX ? 0 : dp[amount];
        }
    };