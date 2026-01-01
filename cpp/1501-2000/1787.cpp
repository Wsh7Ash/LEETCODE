class Solution {
    public:
        int minChanges(vector<int>& nums, int k) {
            int n = nums.size();
            const int MAX_VAL = 1024;
    
            std::vector<std::vector<int>> groups(k);
            for(int i = 0; i < n; i++){
                groups[i % k].push_back(nums[i]);
            }
    
            std::vector<std::unordered_map<int, int>> count(k);
            for(int i = 0; i < k; i++){
                for(int val : groups[i]){
                    count[i][val]++;
                }
            }
    
            std::vector<std::vector<int>> dp(k + 1, std::vector<int>(MAX_VAL, INT_MAX));
            dp[0][0] = 0;
    
            for(int i  = 0; i < k; i++){
                int groupSize = groups[i].size();
                int minPrev = *std::min_element(dp[i].begin(), dp[i].end());
    
                for(int xorVal = 0; xorVal < MAX_VAL; xorVal++){
                    dp[i + 1][xorVal] = minPrev + groupSize;
                    for(auto& [val, freq] : count[i]){
                        int prevXor = xorVal ^ val;
                        if(prevXor < MAX_VAL && dp[i][prevXor] != INT_MAX){
                            dp[i + 1][xorVal] = std::min(dp[i + 1][xorVal], dp[i][prevXor] + groupSize - freq);
                        }
                    }
                }
            }
            return dp[k][0];
        }
    };