class Solution {
    public:
        bool splitArraySameAverage(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return false;
    
            int t = accumulate(nums.begin(), nums.end(), 0);
    
            bool p = false;
            for(int k = 1; k <= n / 2; k++){
                if(t * k % n == 0){
                    p = true;
                    break;
                }
            }
            if(!p) return false;
    
            vector<unordered_set<int>> dp(n / 2 + 1);
            dp[0].insert(0);
    
            for(int num : nums){
                for(int k = n / 2; k >= 1; k--){
                    for(int s : dp[k - 1]){
                        int ns = s + num;
                        if(ns * n == t * k){
                            return true;
                        }
                        dp[k].insert(ns);
                    }
                }
            }
            return false;
        }
    };