class Solution {
    public:
        int tallestBillboard(vector<int>& rods) {
            unordered_map<int, int> dp;
            dp[0] = 0;
    
            for(int rod : rods){
                unordered_map<int, int> temp = dp;
                for(auto it : temp){
                    int d = it.first;
                    int h = it.second;
    
                    int new_d = d + rod;
                    int new_h = h + rod;
                    if(dp.find(new_d) == dp.end()) dp[new_d] = new_h;
                    else dp[new_d] = max(dp[new_d], new_h);
    
                    new_d = abs(d - rod);
                    new_h = max(h, h - d + rod);
                    if(dp.find(new_d) == dp.end()) dp[new_d] = new_h;
                    else dp[new_d] = max(dp[new_d], new_h);
                }
            }
            return dp[0];
        }
    };