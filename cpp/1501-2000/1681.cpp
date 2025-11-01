class Solution {
    public:
        int minimumIncompatibility(vector<int>& nums, int k) {
            int n = nums.size();
            int subsetSize = n / k;
            vector<int> incompatibility(1 << n, -1);
            
            for(int mask = 0; mask < (1 << n); mask++){
                if(__builtin_popcount(mask) == subsetSize){
                    vector<int> subset;
                    for(int i = 0; i < n; i++){
                        if(mask & (1 << i)){
                            subset.push_back(nums[i]);
                        }
                    }
                    sort(subset.begin(), subset.end());
                    bool valid = true;
                    for(int i = 1; i < subset.size(); i++){
                        if(subset[i] == subset[i - 1]){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        incompatibility[mask] = subset.back() - subset[0];
                    }
                }
            }
    
            vector<int> dp(1 << n, -1);
            dp[0] = 0;
            
            for(int mask = 0; mask < (1 << n); mask++){
                if(dp[mask] == -1) continue;
                
                vector<int> unsetBits;
                for(int i = 0; i < n; i++){
                    if(!(mask & (1 << i))){
                        unsetBits.push_back(i);
                    }
                }
                
                if(unsetBits.size() < subsetSize) continue;
                
                int m = unsetBits.size();
                for(int sub = 1; sub < (1 << m); sub++){
                    if(__builtin_popcount(sub) != subsetSize) continue;
                    
                    int subsetMask = 0;
                    for(int i = 0; i < m; i++){
                        if(sub & (1 << i)){
                            subsetMask |= (1 << unsetBits[i]);
                        }
                    }
                    
                    if(incompatibility[subsetMask] != -1){
                        int newMask = mask | subsetMask;
                        if(dp[newMask] == -1 || dp[newMask] > dp[mask] + incompatibility[subsetMask]){
                            dp[newMask] = dp[mask] + incompatibility[subsetMask];
                        }
                    }
                }
            }
            
            return dp[(1 << n) - 1];
        }
    };