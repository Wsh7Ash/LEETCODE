class Solution {
    public:
        string largestNumber(vector<int>& cost, int target) {
            vector<int> dp(target + 1, -10000);
            dp[0] = 0;
    
            for(int i = 1; i <= target; i++){
                for(int digit = 0; digit < 9; digit++){
                    if(i >= cost[digit]){
                        dp[i] = max(dp[i] , dp[i - cost[digit]] + 1);
                    }
                }
            }
    
            if(dp[target] < 0) return "0";
    
            string res = "";
            int rem = target;
    
            for(int digit = 8; digit >= 0; digit--){
                while(rem >= cost[digit] && dp[rem] == dp[rem - cost[digit]] + 1){
                    res += to_string(digit + 1);
                    rem -= cost[digit];
                }
            }
    
            return res;
        }
    };