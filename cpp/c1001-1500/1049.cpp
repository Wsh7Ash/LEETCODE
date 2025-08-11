+class Solution {
    public:
        int lastStoneWeightII(vector<int>& stones) {
            int total_sum = accumulate(stones.begin(), stones.end(), 0);
            int half_sum = total_sum / 2;
            vector<bool> dp(half_sum + 1, false);
            dp[0] = true;
    
            for(int stone : stones){
                for(int i = half_sum; i >= stone; i--){
                    dp[i] = dp[i] || dp[i - stone];
                }
            }
    
            for(int i = half_sum; i >= 0; i--){
                if(dp[i]){
                    return total_sum - 2 * i;
                }
            }
            return 0;
        }
    };