class Solution {
    public:
        int maximumScore(vector<int>& nums, vector<int>& multipliers) {
            int n = nums.size();
            int m = multipliers.size();
            vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));
    
            dp[0][0] = 0;
    
            for(int op = 0; op < m; op++){
                for(int left = 0; left <= op; left++){
                    int right = op - left;
                    if(dp[left][right] == INT_MIN) continue;
                    int takeLeft = dp[left][right] + nums[left] * multipliers[op];
                    if(dp[left + 1][right] == INT_MIN || dp[left + 1][right] < takeLeft){
                        dp[left + 1][right] = takeLeft;
                    }
                    int takeRight = dp[left][right] + nums[n - 1 - right] * multipliers[op];
                    if(dp[left][right + 1] == INT_MIN || dp[left][right + 1] < takeRight){
                        dp[left][right + 1] = takeRight;
                    }
                }
            }
    
            int res = INT_MIN;
            for(int i = 0; i <= m; i++){
                if(dp[i][m - i] > res){
                    res = dp[i][m - i];
                }
            }
            return res;
        }
    };