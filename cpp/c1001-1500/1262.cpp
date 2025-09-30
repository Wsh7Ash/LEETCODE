class Solution {
    public:
        int maxSumDivThree(vector<int>& nums) {
            vector<int> dp(3, 0);
    
            for(int num : nums){
                vector<int> t = dp;
    
                for(int r = 0; r < 3; r++){
                    int newr = (t[r] + num) % 3;
                    dp[newr] = max(dp[newr], t[r] + num);
                }
            }
            return dp[0];
        }
    };