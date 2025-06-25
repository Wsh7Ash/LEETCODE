class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            unordered_map<int, int> f;
            int mn = 0;
            for(int num : nums){
                f[num]++;
                mn = max(mn, num);
            }
            vector<int> dp(mn + 1, 0);
            dp[1] = f.count(1) ? f[1] * 1: 0;
    
            for(int i = 2; i <= mn; i++){
                int g = f.count(i) ? f[i] * i: 0;
                dp[i] = max(dp[i - 1], dp[i - 2] + g);
            }
            return dp[mn];
        }
    };