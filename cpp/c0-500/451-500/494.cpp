class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            unordered_map<int, int> dp;
            dp[0] = 1;
    
            for(int num : nums){
                unordered_map<int, int> ndp;
                for(auto [sum, count] : dp){
                    ndp[sum + num] += count;
                    ndp[sum - num] += count;
                }
                dp = ndp;
            }
            return dp[target];
        }
    };